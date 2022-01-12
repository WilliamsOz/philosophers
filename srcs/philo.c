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

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL


// void*	routine()
// {
// 	printf("Test from Threads\n");
// 	return (NULL);
// }

void	philo(int ac, char **av)
{
	t_philo	*philo;

	philo = NULL;
	philo = init_philo(philo, av);
	(void)ac;

	// (void)ac;
	// (void)av;
	// pthread_t	thread, thread1;

	// pthread_create(&thread, NULL, &routine, NULL);
	// pthread_create(&thread1, NULL, &routine, NULL);
	// pthread_join(thread, NULL);
	// pthread_join(thread1, NULL);
}

//./philo(0)	philo_nbrs(1)	die(2)	eat(3)	sleep(4)	min_must_eat(5)
//proteger les fcts threads

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		incorrect_arg_num();
	if (errors(av) == TRUE)
		exit (EXIT_FAILURE);
	philo(ac, av);
	return (EXIT_SUCCESS);
}

