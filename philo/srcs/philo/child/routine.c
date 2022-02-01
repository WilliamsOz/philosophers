/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/01 13:49:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

static t_dlk	*__philo_sleep__(t_dlk *dlk)
{
	print_status(dlk->data, dlk, SLEEP);
	usleep(dlk->data->sleep);
	print_status(dlk->data, dlk, THINK);
	return (dlk);
}

static t_dlk	*__philo_eat__(t_dlk *dlk)
{
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	dlk->eating_number++;
	dlk->fork = 1;
	pthread_mutex_unlock(&dlk->fork_mutex);
	dlk->next->fork = 1;
	pthread_mutex_unlock(&dlk->next->fork_mutex);
	return (dlk);
}

static t_dlk	*__philo_take_fork__(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	dlk->fork = 0;
	pthread_mutex_lock(&dlk->next->fork_mutex);
	dlk->next->fork = 0;
	print_status(dlk->data, dlk, FORK);
	dlk->last_eat_time = get_time();
	return (dlk);
}

static t_dlk	*__routine__(t_dlk *dlk)
{
	dlk = __philo_take_fork__(dlk);
	dlk = __philo_eat__(dlk);
	dlk = __philo_sleep__(dlk);
	return (dlk);
}

void	do_routine(t_dlk *dlk)
{
	if (dlk->id % 2 == 0)
		usleep(dlk->data->eat / 2);
	while (is_it_end(dlk) == FALSE)
		__routine__(dlk);
	return ;
}

