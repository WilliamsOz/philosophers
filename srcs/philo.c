/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:19:14 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/17 11:49:06 by wiozsert         ###   ########.fr       */
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

void	init_philosophers(t_philo *philo, int ind)
{
	if (ind == 1)
		init_manager(philo, 0);
	else if (ind == 0)
		init_childs(philo, 0);
}

void	pthread_join_failed(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "pthread join has failed\n");
	exit (EXIT_FAILURE);
}

void	philo(char **av)
{
	t_philo	*philo;
	int		ind;

	philo = NULL;
	philo = init_philo(philo, av);
	init_philosophers(philo, 1);
	init_philosophers(philo, 0);
	ind = pthread_join(philo->thread, NULL);
	if (ind != 0)
		pthread_join_failed(philo);
	destroy_all_data(philo);
}

//./philo(0)	philo_nbrs(1)	die(2)	eat(3)	sleep(4)	min_must_eat(5)
//proteger les fcts threads

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		incorrect_arg_num();
	if (errors(av) == TRUE)
		exit (EXIT_FAILURE);
	philo(av);
	return (EXIT_SUCCESS);
}
