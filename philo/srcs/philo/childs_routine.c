/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:02:22 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 18:22:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_philo	*__philo_take_fork__(t_philo *philo, t_dlk *dlk)
{
	if (pthread_mutex_lock(&dlk->fork_mutex) != 0)
		mutex_lock_has_failed(philo);
	dlk->fork = 0;
	if (pthread_mutex_lock(&dlk->previous->fork_mutex) != 0)
		mutex_lock_has_failed(philo);
	dlk->previous->fork = 0;
	print_status(philo, dlk, FORK);
	philo->dlk = dlk;
	return (philo);
}

static t_philo	*__philo_eat__(t_philo *philo, t_dlk *dlk)
{
	dlk->last_eat_time = get_time(philo);
	print_status(philo, dlk, EAT);
	usleep(philo->data->eat);
	dlk->fork = 1;
	if (pthread_mutex_unlock(&dlk->fork_mutex) != 0)
		mutex_unlock_has_failed(philo);
	dlk->previous->fork = 1;
	if (pthread_mutex_unlock(&dlk->previous->fork_mutex) != 0)
		mutex_unlock_has_failed(philo);
	philo->dlk = dlk;
	return (philo);
}

static void	__philo_sleep__(t_philo *philo, t_dlk *dlk)
{
	print_status(philo, dlk, SLEEP);
	usleep(philo->data->sleep);
	print_status(philo, dlk, THINK);
}

static t_philo	*__routine__(t_philo *philo, t_dlk *dlk)
{
	philo = __philo_take_fork__(philo, dlk);
	philo = __philo_eat__(philo, dlk);
	return (philo);
}

void	*routine_childs(void *arg)
{
	t_philo	*philo;
	t_dlk	*dlk;

	philo = (t_philo *)arg;
	dlk = philo->dlk;
	while (1)
	{
		if (dlk->next != NULL && dlk->fork == 1 && dlk->previous->fork == 1
			&& dlk->id % 2 == 1 && ind == 1)
		{
			philo = __routine__(philo, dlk);
			__philo_sleep__(philo, dlk);
		}
		if (dlk->next != NULL)
			dlk = dlk->next;
	}
	return (NULL);
}
