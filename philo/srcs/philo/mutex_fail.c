/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:07:23 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 14:24:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	mutex_lock_has_failed(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "Mutex lock has failed\n");
	exit (EXIT_FAILURE);
}

void	mutex_unlock_has_failed(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "Mutex unlock has failed\n");
	exit (EXIT_FAILURE);
}
