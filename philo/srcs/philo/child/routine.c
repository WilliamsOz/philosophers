/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/04 11:40:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

t_dlk	*philo_eat(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->fork_mutex);
	pthread_mutex_lock(&dlk->next->fork_mutex);
	print_status(dlk->data, dlk, FORK);
	print_status(dlk->data, dlk, EAT);
	usleep(dlk->data->eat);
	dlk->last_eat_time = get_time(0);
	dlk->eating_number++;
	pthread_mutex_unlock(&dlk->fork_mutex);
	pthread_mutex_unlock(&dlk->next->fork_mutex);
	// if (dlk->data->min_must_eat != -1
		// && dlk->eating_number == dlk->data->min_must_eat)
		// return (NULL);
	return (dlk);
}

t_dlk	*philo_sleep(t_dlk *dlk)
{
	print_status(dlk->data, dlk, SLEEP);
	usleep(dlk->data->sleep);
	print_status(dlk->data, dlk, THINK);
	return (dlk);
}

t_dlk	*do_routine(t_dlk *dlk)
{
	while (1)
	{
		dlk = philo_eat(dlk);
		if (dlk == NULL)
			break ;
		dlk = philo_sleep(dlk);
	}
	return (dlk);
}

