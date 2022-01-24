/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:02:22 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:37:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_philo	*__philo_take_fork__(t_philo *philo, t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	dlk->fork = 0;
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	dlk->previous->fork = 0;
	print_status(philo, dlk, FORK);
	philo->dlk = dlk;
	return (philo);
}

static t_philo	*__philo_eat__(t_philo *philo, t_dlk *dlk)
{
	print_status(philo, dlk, EAT);
	usleep(philo->data->eat);
	dlk->fork = 1;
	pthread_mutex_unlock(&dlk->fork_mutex);
	dlk->previous->fork = 1;
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
	philo->dlk = dlk;
	return (philo);
}

static void	__philo_sleep__(t_philo *philo, t_dlk *dlk)
{
	print_status(philo, dlk, SLEEP);
	dlk->eating_number++;
	usleep(philo->data->sleep);
	print_status(philo, dlk, THINK);
}

static t_philo	*__routine__(t_philo *philo, t_dlk *dlk)
{
	philo = __philo_take_fork__(philo, dlk);
	dlk->last_eat_time = get_time(philo);
	philo = __philo_eat__(philo, dlk);
	return (philo);
}

void	*routine_childs(void *arg)
{
	t_philo	*philo;
	t_dlk	*dlk;

	philo = (t_philo *)arg;
	dlk = philo->dlk;
	while (philo->exit_status != -1)
	{
		if (dlk->next != NULL && dlk->fork == 1 && dlk->previous->fork == 1
			&& dlk->ind == 0 && philo->exit_status != -1)
		{
			dlk->ind = 1;
			philo = __routine__(philo, dlk);
			pthread_mutex_lock(&dlk->ind_mutex);
			__philo_sleep__(philo, dlk);
			dlk->ind = 0;
			pthread_mutex_unlock(&dlk->ind_mutex);
		}
		if (dlk->next != NULL && philo->exit_status != -1)
			dlk = dlk->next;
	}
	return (NULL);
}
