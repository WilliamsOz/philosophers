/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:19:14 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/22 21:22:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

void	print_data(t_data *data)
{
	printf("---------------DATA---------------\n");
	printf("Numbers of philosophers = %d\n", data->philo_nbr);
	printf("Time to die = %d\n", data->die);
	printf("Time to eat = %d\n", data->eat);
	printf("Time to sleep = %d\n", data->sleep);
	printf("Time to min must eat = %d\n", data->min_must_eat);
	printf("---------------END---------------\n");
}

void	print_dlk(t_dlk *dlk)
{
	t_dlk	*tmp;
	int		i;

	printf("---------------START TO END---------------\n");
	tmp = dlk->next;
	i = 1;
	printf("Philosophe n°%d\n", i);
	i++;
	while (tmp != dlk)
	{
		printf("Philosophe n°%d\n", i);
		i++;
		tmp = tmp->next;
	}
	printf("---------------END TO START---------------\n");
	i--;
	tmp = dlk->previous;
	while (tmp != dlk)
	{
		printf("Philosophe n°%d\n", i);
		i--;
		tmp = tmp->previous;
	}
	printf("Philosophe n°%d\n", i);
	printf("------------------------------------------\n");
}

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

int	init_philosophers(t_philo *philo, int ind)
{
	if (ind == 1)
		ind = init_manager(philo, 0);
	else if (ind == 0)
		ind = init_childs(philo, 0);
	return (ind);
}

void	pthread_join_failed(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "pthread join has failed\n");
}

int	wait_thread(t_philo *philo, int philo_exit_status)
{
	t_dlk	*tmp;

	if (pthread_join(philo->thread, NULL) != 0)
	{
		pthread_join_failed(philo);
		philo_exit_status = THREAD_JOIN_FAILED;
	}
	tmp = philo->dlk->next;
	while (tmp != philo->dlk)
	{
		if (pthread_join(tmp->thread, NULL) != 0)
		{
			pthread_join_failed(philo);
			philo_exit_status = THREAD_JOIN_FAILED;
		}
		tmp = tmp->next;
	}
	if (pthread_join(tmp->thread, NULL) != 0)
	{
		pthread_join_failed(philo);
		philo_exit_status = THREAD_JOIN_FAILED;
	}
	return (philo_exit_status);
}

int	philo(char **av, int philo_exit_status)
{
	t_philo	*philo;

	philo = NULL;
	philo = init_philo(philo, av);
	if (philo == NULL)
		return (MALLOC_ERROR);
	philo_exit_status = init_philosophers(philo, 1);
	philo_exit_status = init_philosophers(philo, 0);
	if (philo_exit_status != 0)
		return (philo_exit_status);
	philo_exit_status = wait_thread(philo, 0);
	philo_exit_status = philo->exit_status;
	philo = destroy_all_data(philo);
	return (philo_exit_status);
}

//-fsanitize==thread + leaks a checker
// il reste des exit avec le temp ect

int	main(int ac, char **av)
{
	int		philo_exit_status;

	if (ac != 5 && ac != 6)
	{
		print_fd(2, "Numbers of arguments incorrect\n");
		return (2);
	}
	else if (errors(av) == TRUE)
		return (2);
	philo_exit_status = philo(av, 0);
	return (philo_exit_status);
}
