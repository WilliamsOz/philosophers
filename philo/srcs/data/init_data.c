/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:01:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:07:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_philo	*__mall_data_failed__(t_philo *philo)
{
	print_fd(2, "Malloc of data has failed\n");
	philo->exit_status = -1;
	return (philo);
}

t_data	*init_data(t_philo *philo, char **av)
{
	philo->data = (t_data *)malloc(sizeof(t_data));
	if (philo->data == NULL)
	{
		philo = __mall_data_failed__(philo);
		return (NULL);
	}
	philo->data = get_data(philo->data, av);
	philo->data = get_starting_time(philo);
	return (philo->data);
}
