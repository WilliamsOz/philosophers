/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:11:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/23 18:59:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*do_routine(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	if (dlk->id == dlk->previous->id)
	{
		pthread_mutex_unlock(&dlk->fork_mutex);
		while (1)
			if (dlk->data->end == 1)
				break ;
		return (dlk);
	}
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	dlk->time_last_meal = get_time(0);
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	dlk->number_of_meal += 1;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
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
	while (1 && dlk->data->end != 1)
	{
		dlk = do_routine(dlk);
		if (dlk->number_of_meal == dlk->data->min_must_eat)
			break ;
	}
	dlk->data->end = 1;
	return (NULL);
}
