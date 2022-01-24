/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:58:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 15:51:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_philo	*__gettimeofday_failed__(t_philo *philo)
{
	print_fd(2, "gettimeofday has failed\n");
	philo->exit_status = -1;
	return (philo);
}

t_data	*get_starting_time(t_philo *philo)
{
	int	ind;

	ind = gettimeofday(&philo->data->starting_time, NULL);
	if (ind == -1)
		philo = __gettimeofday_failed__(philo);
	return (philo->data);
}
