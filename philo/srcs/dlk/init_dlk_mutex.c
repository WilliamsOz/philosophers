/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dlk_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:18:45 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 18:16:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*init_dlk_mutex(t_dlk *dlk)
{
	pthread_mutex_init(&dlk->last_eat_time_mutex, NULL);
	pthread_mutex_init(&dlk->fork_mutex, NULL);
	return (dlk);
}
