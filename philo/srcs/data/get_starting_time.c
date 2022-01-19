/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:58:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/15 14:59:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__gettimeofday_failed__(t_philo *philo)
{
	print_fd(2, "gettimeofday has failed\n");
	philo = destroy_philo_and_data(philo);
	exit (EXIT_FAILURE);
}

t_data	*get_starting_time(t_philo *philo)
{
	int	ind;

	ind = gettimeofday(&philo->data->starting_time, NULL);
	if (ind == -1)
		__gettimeofday_failed__(philo);
	return (philo->data);
}
