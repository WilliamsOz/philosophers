/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:11:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 15:34:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*one_philo(t_dlk *dlk)
{
	pthread_mutex_unlock(&dlk->fork_mutex);
	while (1)
	{
		pthread_mutex_lock(&dlk->data->end_mutex);
		if (dlk->data->end == 1)
		{
			pthread_mutex_unlock(&dlk->data->end_mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&dlk->data->end_mutex);
	}
	return (dlk);
}

t_dlk	*do_routine(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	if (dlk->id == dlk->previous->id)
	{
		dlk = one_philo(dlk);
		return (dlk);
	}
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	pthread_mutex_lock(&dlk->eat_mutex);
	dlk->time_last_meal = get_time(dlk->data, 0);
	pthread_mutex_unlock(&dlk->eat_mutex);
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
	dlk->number_of_meal += 1;
	print_status(dlk->data, dlk, SLEEP);
	usleep(dlk->data->sleep);
	print_status(dlk->data, dlk, THINK);
	return (dlk);
}

void	*routine(void *arg)
{
	t_dlk	*dlk;

	dlk = (t_dlk *)arg;
	if (dlk->id % 2 == 0)
		usleep(dlk->data->eat / 2);
	while (1)
	{
		pthread_mutex_lock(&dlk->data->end_mutex);
		if (dlk->data->end == 1)
		{
			pthread_mutex_unlock(&dlk->data->end_mutex);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&dlk->data->end_mutex);
			dlk = do_routine(dlk);
		}
		if (dlk->number_of_meal == dlk->data->min_must_eat)
			break ;
	}
	pthread_mutex_lock(&dlk->data->end_mutex);
	dlk->data->end = 1;
	pthread_mutex_unlock(&dlk->data->end_mutex);
	return (NULL);
}
