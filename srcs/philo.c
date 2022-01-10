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

void*	routine()
{
	printf("Test from Threads\n");
	return (NULL);
}

void	philo(int ac, char **av)
{
	// t_philo	*philo;
	// t_data	*data;

	// data = NULL;
	// daata = init_data(av);
	// philo = NULL;
	// (void)ac;
	// (void)av;
	// printf("OK\n");


	(void)ac;
	(void)av;
	pthread_t	thread, thread1;

	pthread_create(&thread, NULL, &routine, NULL);
	pthread_create(&thread1, NULL, &routine, NULL);
	pthread_join(thread, NULL);
	pthread_join(thread1, NULL);
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

