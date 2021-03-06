/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:11:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/05 15:38:52 by wiozsert         ###   ########.fr       */
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
	if (dlk->id == dlk->next->id)
	{
		dlk = one_philo(dlk);
		return (dlk);
	}
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->next->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	print_status(dlk->data, dlk, EAT);
	pthread_mutex_lock(&dlk->time_last_meal_mutex);
	dlk->time_last_meal = get_time(0);
	pthread_mutex_unlock(&dlk->time_last_meal_mutex);
	usleep(dlk->data->eat);
	dlk->number_of_meal += 1;
	pthread_mutex_unlock(&dlk->next->fork_mutex);
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
		if (dlk->data->end == 1
			|| dlk->number_of_meal == dlk->data->min_must_eat)
		{
			dlk->data->end = 1;
			pthread_mutex_unlock(&dlk->data->end_mutex);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&dlk->data->end_mutex);
			dlk = do_routine(dlk);
		}
	}
	return (NULL);
}
