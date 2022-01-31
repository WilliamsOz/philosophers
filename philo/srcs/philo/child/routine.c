/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:41:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

static t_dlk	*__philo_sleep__(t_dlk *dlk)
{
	print_status(dlk->data, dlk, SLEEP);
	pthread_mutex_lock(&dlk->eating_number_mutex);
	dlk->eating_number++;
	pthread_mutex_unlock(&dlk->eating_number_mutex);
	usleep(dlk->data->sleep);
	print_status(dlk->data, dlk, THINK);
	return (dlk);
}

static t_dlk	*__philo_eat__(t_dlk *dlk)
{
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	pthread_mutex_lock(&dlk->fork_mutex);
	dlk->fork = 1;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	dlk->previous->fork = 1;
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
	return (dlk);
}

static int	philo_take_one_fork(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	if (dlk->fork == 1)
	{
		dlk->fork = 0;
		print_status(dlk->data, dlk, FORK);
		pthread_mutex_unlock(&dlk->fork_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&dlk->fork_mutex);
	return (FALSE);
}

static int	philo_take_second_fork(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	if (dlk->previous->fork == 1)
	{
		dlk->previous->fork = 0;
		print_status(dlk->data, dlk, FORK);
		pthread_mutex_unlock(&dlk->previous->fork_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
	return (FALSE);
}

void	__routine__(t_dlk *dlk)
{
	while (philo_take_one_fork(dlk) == FALSE && is_it_end(dlk) == FALSE);
	while (philo_take_second_fork(dlk) == FALSE && is_it_end(dlk) == FALSE);
	if (is_it_end(dlk) == FALSE)
	{
		dlk = __philo_eat__(dlk);
		pthread_mutex_lock(&dlk->last_eat_time_mutex);
		dlk->last_eat_time = get_time();
		pthread_mutex_unlock(&dlk->last_eat_time_mutex);
		dlk = __philo_sleep__(dlk);
	}
}
