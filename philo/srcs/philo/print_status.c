/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 16:29:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__philo_sleep(t_philo *philo, t_dlk	*tmp)
{
	if (philo->exit_status != -1)
	{
		printf("\033[0;34m");
		printf("%d	%d	is sleeping\n", get_time(philo), tmp->id);
		printf("\033[0m");
	}
}

static void	__philo_eat__(t_philo *philo, t_dlk *tmp)
{
	if (philo->exit_status != -1)
	{
		printf("\033[0;32m");
		printf("%d	%d	is eating\n", get_time(philo), tmp->id);
		printf("\033[0m");
	}
}

static void	__philo_fork__(t_philo *philo, t_dlk *tmp)
{
	if (philo->exit_status != -1)
	{
		printf("\033[0;33m");
		printf("%d	%d	has taken a fork\n", get_time(philo), tmp->id);
		printf("%d	%d	has taken a fork\n", get_time(philo), tmp->id);
		printf("\033[0m");
	}
}

static void	__philo_think__(t_philo *philo, t_dlk *tmp)
{
	if (philo->exit_status != -1)
	{
		printf("\033[0;35m");
		printf("%d	%d	is thinking\n", get_time(philo), tmp->id);
		printf("\033[0m");
	}
}

void	print_status(t_philo *philo, t_dlk *tmp, int ind)
{
	pthread_mutex_lock(&philo->exit_status_mutex);
	if (ind == FORK && philo->exit_status != -1)
		__philo_fork__(philo, tmp);
	else if (ind == EAT && philo->exit_status != -1)
		__philo_eat__(philo, tmp);
	else if (ind == SLEEP && philo->exit_status != -1)
		__philo_sleep(philo, tmp);
	else if (ind == THINK && philo->exit_status != -1)
		__philo_think__(philo, tmp);
	pthread_mutex_unlock(&philo->exit_status_mutex);
}
