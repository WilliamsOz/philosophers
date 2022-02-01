/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:16:55 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/01 13:52:49 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*get_philo_id(t_dlk *dlk)
{
	t_dlk	*tmp;
	int		i;
	int		count;

	tmp = dlk;
	count = dlk->data->philo_nbr;
	i = 1;
	while (count > 0)
	{
		pthread_mutex_init(&dlk->fork_mutex, NULL);
		tmp->id = i;
		count -= 1;
		i += 1;
		tmp = tmp->next;
	}
	return (dlk);
}
