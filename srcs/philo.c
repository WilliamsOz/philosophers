/* ************************************************************************** */
/*                                                                            *//*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:06:33 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/07 22:19:14 by wiozsert         ###   ########.fr       */
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


void	*routine(void *arg)
{
	t_dlk	*dlk;
	int	i = 0;

	dlk = (t_dlk *)arg;
	while (i < 10)
		i++;
	dlk->is_alive = DEAD;
	return (dlk);
}

void	philo(char **av)
{
	t_philo	*philo;

	philo = NULL;
	philo = init_philo(philo, av);
	pthread_create(&philo->dlk->thread, NULL, &routine, philo->dlk);
	
	pthread_join(philo->dlk->thread, NULL);
	pthread_join(philo->thread, NULL);
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

