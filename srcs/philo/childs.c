/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:20:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/17 14:50:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print(t_philo *philo, t_dlk *tmp, int ind)
{
	pthread_mutex_lock(&philo->print_mutex);
	if (ind == 0)
		printf("%d %d has taken a fork\n", get_time(philo), tmp->id);
	else if (ind == 1)
		printf("%d %d is eating\n", get_time(philo), tmp->id);
	else if (ind == 2)
		printf("%d %d is sleeping\n", get_time(philo), tmp->id);
	else if (ind == 3)
		printf("%d %d is thinking\n", get_time(philo), tmp->id);
	pthread_mutex_unlock(&philo->print_mutex);
}

void	*__routine_childs__(void *arg)
{
	t_philo	*philo;
	t_dlk	*tmp;

	philo = (t_philo *)arg;
	tmp = philo->dlk;
	while (1)
	{
		if (tmp->previous->fork == 1 && tmp->fork == 1)
		{
			pthread_mutex_lock(&tmp->fork_mutex);
			tmp->fork = 0;
			pthread_mutex_lock(&tmp->previous->fork_mutex);
			tmp->previous->fork = 0;
			print(philo, tmp, FORK);
			print(philo, tmp, EAT);
			usleep(philo->data->eat);
			tmp->fork = 1;
			tmp->previous->fork = 1;
			pthread_mutex_unlock(&tmp->fork_mutex);
			pthread_mutex_unlock(&tmp->previous->fork_mutex);
			print(philo, tmp, SLEEP);
			print(philo, tmp, THINK);
			usleep(philo->data->sleep);
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

	ind = pthread_create(&philo->dlk->thread, NULL,
			&__routine_childs__, philo);
	if (ind != 0)
		__thread_childs_create_failed__(philo);
	tmp = philo->dlk->next;
	while (tmp != philo->dlk)
	{
		ind = pthread_create(&tmp->thread, NULL, &__routine_childs__, philo);
		if (ind != 0)
			__thread_childs_create_failed__(philo);
		tmp = tmp->next;
	}
}
