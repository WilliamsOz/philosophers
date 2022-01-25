/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 16:35:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

static void	__philo_sleep__(t_philo *philo, t_dlk *dlk)
{
	print_status(philo, dlk, SLEEP);
	pthread_mutex_lock(&dlk->eating_number_mutex);
	dlk->eating_number++;
	pthread_mutex_unlock(&dlk->eating_number_mutex);
	usleep(philo->data->sleep);
	print_status(philo, dlk, THINK);
}

static t_philo	*__philo_eat__(t_philo *philo, t_dlk *dlk)
{
	print_status(philo, dlk, EAT);
	usleep(philo->data->eat);
	pthread_mutex_lock(&dlk->fork_mutex);
	dlk->fork = 1;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	dlk->previous->fork = 1;
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
	return (philo);
}

static t_philo	*__philo_take_fork__(t_philo *philo, t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	dlk->fork = 0;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	dlk->previous->fork = 0;
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
	print_status(philo, dlk, FORK);
	return (philo);
}

static t_philo	*__routine__(t_philo *philo, t_dlk *dlk)
{
	philo = __philo_take_fork__(philo, dlk);
	pthread_mutex_lock(&dlk->last_eat_time_mutex);
	dlk->last_eat_time = get_time(philo);
	pthread_mutex_unlock(&dlk->last_eat_time_mutex);
	philo = __philo_eat__(philo, dlk);
	return (philo);
}

t_dlk	*do_routine(t_philo *philo, t_dlk *dlk)
{
	if (dlk->next != NULL)
	{
		pthread_mutex_lock(&dlk->ate_mutex);
		if (dlk->ate == 0)
		{
			dlk->ate = 1;
			philo = __routine__(philo, dlk);
			pthread_mutex_unlock(&dlk->ate_mutex);
			__philo_sleep__(philo, dlk);
			pthread_mutex_lock(&dlk->ate_mutex);
			dlk->ate = 0;
			pthread_mutex_unlock(&dlk->ate_mutex);
		}
		else
			pthread_mutex_unlock(&dlk->ate_mutex);
	}
	return (dlk);
}
