/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:58:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 13:02:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__gettimeofday_failed__(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "gettimeofday has failed\n");
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
