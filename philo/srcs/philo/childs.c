/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:20:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 15:09:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print(t_philo *philo, t_dlk *tmp, int ind)
{
	if (pthread_mutex_lock(&philo->print_mutex) != 0)
		mutex_lock_has_failed(philo);
	if (ind == 0)
		printf("%d %d has taken a fork\n", get_time(philo), tmp->id);
	else if (ind == 1)
		printf("%d %d is eating\n", get_time(philo), tmp->id);
	else if (ind == 2)
		printf("%d %d is sleeping\n", get_time(philo), tmp->id);
	else if (ind == 3)
		printf("%d %d is thinking\n", get_time(philo), tmp->id);
	if (pthread_mutex_unlock(&philo->print_mutex) != 0)
		mutex_unlock_has_failed(philo);
}

t_dlk	*philo_take_fork(t_philo *philo, t_dlk *tmp)
{
	print(philo, tmp, FORK);
	if (pthread_mutex_lock(&tmp->fork_mutex) != 0)
		mutex_lock_has_failed(philo);
	tmp->fork = 0;
	if (pthread_mutex_lock(&tmp->previous->fork_mutex) != 0)
		mutex_lock_has_failed(philo);
	tmp->previous->fork = 0;
	return (tmp);
}

t_dlk	*philo_eat(t_philo *philo, t_dlk *tmp)
{
	print(philo, tmp, EAT);
	usleep(philo->data->eat);
	tmp->fork = 1;
	if (pthread_mutex_unlock(&tmp->fork_mutex) != 0)
		mutex_unlock_has_failed(philo);
	tmp->previous->fork = 1;
	if (pthread_mutex_unlock(&tmp->previous->fork_mutex) != 0)
		mutex_unlock_has_failed(philo);
	return (tmp);
}

void	philo_sleep(t_philo *philo, t_dlk *tmp)
{
	print(philo, tmp, SLEEP);
	usleep(philo->data->sleep);
}

void	*__routine_childs__(void *arg)
{
	t_philo	*philo;
	t_dlk	*tmp;

	philo = (t_philo *)arg;
	tmp = philo->dlk;
	while (1)
	{
		if (tmp->fork == 1 && tmp->previous->fork == 1)
		{
			tmp = philo_take_fork(philo, tmp);
			tmp = philo_eat(philo, tmp);
			philo_sleep(philo, tmp);
			print(philo, tmp, THINK);
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
