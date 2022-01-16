/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:26:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/16 16:05:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int	__sec_egal__(t_philo *philo, int time)
{
	time = philo->dlk->current_time.tv_usec - philo->data->starting_time.tv_usec;
	time /= 1000;
	return (time);
}

static int	__sec_not_egal__(t_philo *philo, int time)
{
	time = philo->dlk->current_time.tv_sec - philo->data->starting_time.tv_sec;
	if (time == 1)
		time = (1000000 - philo->data->starting_time.tv_usec) / 1000;
	else
		time *= 1000;
	time = time +  ((philo->dlk->current_time.tv_usec) / 1000);
	return (time);
}

void	__gettimeofdayfail__(t_philo *philo)
{
	print_fd(2, "gettimeofday has failed\n");
	philo->dlk = dlk_destroyer(philo->dlk);
	philo = destroy_philo_and_data(philo);
	exit (EXIT_FAILURE);
}

int	get_time(t_philo *philo)
{
	int	time;
	int				ind;

	ind = gettimeofday(&philo->dlk->current_time, NULL);
	if (ind == -1)
		__gettimeofdayfail__(philo);
	if (philo->data->starting_time.tv_sec == philo->dlk->current_time.tv_sec)
		time = __sec_egal__(philo, 0);
	else
		time = __sec_not_egal__(philo, 0);
	return (time);
}
