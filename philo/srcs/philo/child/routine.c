/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/01 18:16:26 by wiozsert         ###   ########.fr       */
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
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_unlock(&dlk->next->fork_mutex);
	return (dlk);
}

static t_dlk	*__philo_take_fork__(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	if (dlk->next != dlk)
	{
		pthread_mutex_lock(&dlk->next->fork_mutex);
		print_status(dlk->data, dlk, FORK);
		dlk->last_eat_time = get_time();
	}
	return (dlk);
}

static t_dlk	*__routine__(t_dlk *dlk)
{
	if ((get_time() - dlk->last_eat_time) > (dlk->data->die / 1000))
		dlk->is_alive = DEAD;
	else
	{
		dlk = __philo_take_fork__(dlk);
		if (dlk->next != dlk)
		{
			dlk = __philo_eat__(dlk);
			dlk = __philo_sleep__(dlk);
		}
	}
	return (dlk);
}

t_dlk	*do_routine(t_dlk *dlk)
{
	// if (dlk->id % 2 == 0)
		// usleep(dlk->data->eat / 2);
	while (is_it_end(dlk) == FALSE)
		dlk = __routine__(dlk);
	return (dlk);
}

