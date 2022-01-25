/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:13:03 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 16:34:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

int	is_it_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->exit_status_mutex);
	if (philo->exit_status == -1)
	{
		pthread_mutex_unlock(&philo->exit_status_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->exit_status_mutex);
	return (FALSE);
}
