/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:02:22 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/10 00:18:07 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

void	philo_eat(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	pthread_mutex_lock(&dlk->previous->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	dlk->last_eat_time = get_time(0);
	dlk->eating_number++;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_unlock(&dlk->previous->fork_mutex);
}

void	philo_sleep(t_dlk *dlk)
{
	print_status(dlk->data, dlk, SLEEP);
	usleep(dlk->data->sleep);
	print_status(dlk->data, dlk, THINK);
}

void	*routine_childs(void *arg)
{
	t_dlk		*dlk;

	dlk = (t_dlk *)arg;
	while (1)
	{
		if (dlk->id % 2 == 0)
			usleep(dlk->data->eat / 2);
		philo_eat(dlk);
		philo_sleep(dlk);
	}
	return (arg);
}
