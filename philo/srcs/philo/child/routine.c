/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/30 17:54:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

static void	__philo_sleep__(t_dlk *dlk)
{
	print_status(dlk->data, dlk, SLEEP);
	pthread_mutex_lock(&dlk->eating_number_mutex);
	dlk->eating_number++;
	pthread_mutex_unlock(&dlk->eating_number_mutex);
	usleep(dlk->data->sleep);
	print_status(dlk->data, dlk, THINK);
}

static void	__philo_eat__(t_dlk *dlk)
{
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	dlk->fork = 1;
	dlk->next->fork = 1;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_unlock(&dlk->next->fork_mutex);
}

static void	__philo_take_fork__(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->next->fork_mutex);
	dlk->fork = 0;
	dlk->next->fork = 0;
	print_status(dlk->data, dlk, FORK);
}

static void	__routine__(t_dlk *dlk)
{
	__philo_take_fork__(dlk);
	pthread_mutex_lock(&dlk->last_eat_time_mutex);
	dlk->last_eat_time = get_time(dlk->data, dlk);
	pthread_mutex_unlock(&dlk->last_eat_time_mutex);
	__philo_eat__(dlk);
}

void	do_routine(t_dlk *dlk)
{
	while (is_it_end(dlk) == FALSE)
	{
		__routine__(dlk);
		__philo_sleep__(dlk);
	}
	return ;
}
