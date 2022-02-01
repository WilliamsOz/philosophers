/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:13:03 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/01 15:28:21 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

int	is_it_end(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->data->exit_status_mutex);
	if (dlk->data->min_must_eat != -1
		&& dlk->eating_number == dlk->data->min_must_eat)
	{
		dlk->data->exit_status = -1;
		pthread_mutex_unlock(&dlk->data->exit_status_mutex);
		return (TRUE);
	}
	if (dlk->is_alive == DEAD)
	{
		dlk->data->exit_status = -1;
		pthread_mutex_unlock(&dlk->data->exit_status_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&dlk->data->exit_status_mutex);
	return (FALSE);
}
