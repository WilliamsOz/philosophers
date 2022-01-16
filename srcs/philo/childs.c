/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:20:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/16 17:07:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	*__routine_childs__(void *arg)
{
	t_dlk	*dlk;
	t_dlk	*tmp;
	pthread_mutex_t mutex;

	dlk = (t_dlk *)arg;
	tmp = dlk;
	while (1)
	{
		pthread_mutex_init(&mutex, NULL);
		if (tmp->previous->fork == 1 && tmp->fork == 1)
		{
			tmp->previous->fork = 0;
			tmp->fork = 0;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static void	__thread_childs_create_failed__(t_philo *philo)
{
	t_dlk	*tmp;

	tmp = philo->dlk->next;
	while (tmp != philo->dlk)
	{
		pthread_exit(&tmp->thread);
		tmp = tmp->next;
	}
	pthread_exit(&philo->thread);
	philo = destroy_all_data(philo);
	print_fd(2, "Creation of thread child has failed\n");
	exit (EXIT_FAILURE);
}

void	init_childs(t_philo *philo, int ind)
{
	t_dlk	*tmp;

	ind = pthread_create(&philo->dlk->thread, NULL, &__routine_childs__, philo->dlk);
	if (ind != 0)
		__thread_childs_create_failed__(philo);
	tmp = philo->dlk->next;
	while (tmp != philo->dlk)
	{
		ind = pthread_create(&tmp->thread, NULL, &__routine_childs__, philo->dlk);
		if (ind != 0)
			__thread_childs_create_failed__(philo);
		tmp = tmp->next;
	}
}
