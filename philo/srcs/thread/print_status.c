/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 10:55:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__philo_sleep(t_dlk *dlk)
{
	printf("\033[0;34m");
	printf("%ld	%d	is sleeping\n", get_time(dlk->data, 0), dlk->id);
	printf("\033[0m");
}

static void	__philo_eat__(t_dlk *dlk)
{
	printf("\033[0;32m");
	printf("%ld	%d	is eating\n", get_time(dlk->data, 0), dlk->id);
	printf("\033[0m");
}

static void	__philo_fork__(t_dlk *dlk)
{
	printf("\033[0;33m");
	printf("%ld	%d	has taken a fork\n", get_time(dlk->data, 0), dlk->id);
	printf("\033[0m");
}

static void	__philo_think__(t_dlk *dlk)
{
	printf("\033[0;35m");
	printf("%ld	%d	is thinking\n", get_time(dlk->data, 0), dlk->id);
	printf("\033[0m");
}

void	print_status(t_data *data, t_dlk *dlk, int ind)
{
	pthread_mutex_lock(&dlk->data->end_mutex);
	if (data->end == 1)
	{
		pthread_mutex_unlock(&dlk->data->end_mutex);
		return ;
	}
	else
		pthread_mutex_unlock(&dlk->data->end_mutex);
	pthread_mutex_lock(&data->print_mutex);
	if (ind == FORK)
		__philo_fork__(dlk);
	else if (ind == EAT)
		__philo_eat__(dlk);
	else if (ind == SLEEP)
		__philo_sleep(dlk);
	else if (ind == THINK)
		__philo_think__(dlk);
	pthread_mutex_unlock(&data->print_mutex);
}
