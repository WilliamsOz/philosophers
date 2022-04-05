/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/05 15:32:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__philo_sleep(t_dlk *dlk)
{
	ft_putnbr(get_time(dlk->data, 0));
	write(STDOUT_FILENO, "	", 1);
	ft_putnbr(dlk->id);
	write(STDOUT_FILENO, "	is sleeping\n", 13);
}

static void	__philo_eat__(t_dlk *dlk)
{
	ft_putnbr(get_time(dlk->data, 0));
	write(STDOUT_FILENO, "	", 1);
	ft_putnbr(dlk->id);
	write(STDOUT_FILENO, "	is eating\n", 11);
}

static void	__philo_fork__(t_dlk *dlk)
{
	ft_putnbr(get_time(dlk->data, 0));
	write(STDOUT_FILENO, "	", 1);
	ft_putnbr(dlk->id);
	write(STDOUT_FILENO, "	has taken a fork\n", 18);
}

static void	__philo_think__(t_dlk *dlk)
{
	ft_putnbr(get_time(dlk->data, 0));
	write(STDOUT_FILENO, "	", 1);
	ft_putnbr(dlk->id);
	write(STDOUT_FILENO, "	is thinking\n", 13);
}

void	print_status(t_data *data, t_dlk *dlk, int ind)
{
	pthread_mutex_lock(&dlk->data->end_mutex);
	if (data->end == 1)
	{
		pthread_mutex_unlock(&dlk->data->end_mutex);
		return ;
	}
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
