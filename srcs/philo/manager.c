/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:09:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/16 16:36:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__thread_manager_create_failed__(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "Creation of thread manager has failed\n");
	exit (EXIT_FAILURE);
}

static void	*__routine_manager__(void *arg)
{
	t_dlk	*tmp;

	tmp = (t_dlk *)arg;
	while (tmp->is_alive == ALIVE)
		tmp = tmp->next;
	if (tmp->is_alive == DEAD)
	{
		ICI
		exit (EXIT_SUCCESS);
	}
	return (NULL);
}

void	init_manager(t_philo *philo, int ind)
{
	ind = pthread_create(&philo->thread, NULL, &__routine_manager__, philo->dlk);
	if (ind != 0)
		__thread_manager_create_failed__(philo);
}
