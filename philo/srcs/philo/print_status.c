/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/22 19:15:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__philo_sleep(t_data *data, t_dlk *tmp)
{
	if (data->exit_status != -1)
	{
		printf("\033[0;34m");
		printf("%ld	%d	is sleeping\n", get_time(0), tmp->id);
		printf("\033[0m");
	}
}

static void	__philo_eat__(t_data *data, t_dlk *tmp)
{
	if (data->exit_status != -1)
	{
		printf("\033[0;32m");
		printf("%ld	%d	is eating\n", get_time(0), tmp->id);
		printf("\033[0m");
	}
}

static void	__philo_fork__(t_data *data, t_dlk *tmp)
{
	if (data->exit_status != -1)
	{
		printf("\033[0;33m");
		printf("%ld	%d	has taken a fork\n", get_time(0), tmp->id);
		printf("\033[0m");
	}
}

static void	__philo_think__(t_data *data, t_dlk *tmp)
{
	if (data->exit_status != -1)
	{
		printf("\033[0;35m");
		printf("%ld	%d	is thinking\n", get_time(0), tmp->id);
		printf("\033[0m");
	}
}

void	print_status(t_data *data, t_dlk *tmp, int ind)
{
	pthread_mutex_lock(&data->exit_status_mutex);
	if (ind == FORK && data->exit_status != -1)
		__philo_fork__(data, tmp);
	else if (ind == EAT && data->exit_status != -1)
		__philo_eat__(data, tmp);
	else if (ind == SLEEP && data->exit_status != -1)
		__philo_sleep(data, tmp);
	else if (ind == THINK && data->exit_status != -1)
		__philo_think__(data, tmp);
	pthread_mutex_unlock(&data->exit_status_mutex);
}
