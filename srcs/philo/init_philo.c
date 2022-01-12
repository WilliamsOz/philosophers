/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:01 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 18:26:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__thread_manager_create_failed__(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "Creation of thread manager has failed\n");
	exit (EXIT_FAILURE);
}

void	*threads_manager(void *arg)
{
	t_dlk	*tmp;

	tmp = (t_dlk *)arg;
	int i = 50;
	while (tmp->is_alive == ALIVE && i > 0)
	{
		PD(tmp->is_alive)
		tmp = tmp->next;
		i--;
	}
		PD(tmp->is_alive)
	return (NULL);
}

t_philo	*init_philo(t_philo *philo, char **av)
{
	int	ind;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		mall_philo_failed();
	philo->data = NULL;
	philo->data = init_data(philo, av);
	philo->dlk = NULL;
	philo->dlk = init_dlk(philo, philo->data->philo_nbr);
	ind = pthread_create(&philo->thread, NULL, &threads_manager, philo->dlk);
	if (ind != 0)
		__thread_manager_create_failed__(philo);
	return (philo);
}
