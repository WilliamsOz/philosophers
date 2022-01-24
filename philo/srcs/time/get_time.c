/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:26:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 15:58:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int	__sec_egal__(t_philo *philo, int time)
{
	time = philo->dlk->current_time.tv_usec
		- philo->data->starting_time.tv_usec;
	time /= 1000;
	return (time);
}

static int	__sec_not_egal__(t_philo *philo, int time)
{
	int	ind;

	ind = philo->dlk->current_time.tv_sec - philo->data->starting_time.tv_sec;
	if (ind >= 1)
	{
		time = philo->dlk->current_time.tv_sec
			- philo->data->starting_time.tv_sec - 1;
		time *= 1000;
	}
	time = time + ((1000000 - (philo->data->starting_time.tv_usec
					- philo->dlk->current_time.tv_usec)) / 1000);
	return (time);
}

static t_philo	*__gettimeofdayfail__(t_philo *philo)
{
	print_fd(2, "gettimeofday has failed\n");
	philo->exit_status = -1;
	return (philo);
}

int	get_time(t_philo *philo)
{
	int				time;
	int				ind;

	time = 0;
	ind = gettimeofday(&philo->dlk->current_time, NULL);
	if (ind == -1)
	{
		philo = __gettimeofdayfail__(philo);
		return (time);
	}
	if (philo->data->starting_time.tv_sec == philo->dlk->current_time.tv_sec)
		time = __sec_egal__(philo, 0);
	else
		time = __sec_not_egal__(philo, 0);
	return (time);
}
