/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:22:20 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/04 12:35:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_data	*__pthread_join_failed__(t_data *data)
{
	print_fd(2, "pthread join has failed\n");
	data->exit_status = -1;
	return (data);
}

t_data	*wait_threads(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;
	int		count;

	tmp = dlk;
	count = data->philo_nbr;
	while (count > 0 && data->exit_status != -1)
	{
		if (pthread_join(tmp->thread, NULL) != 0)
		{
			data = __pthread_join_failed__(data);
			return (data);
		}
		tmp = tmp->next;
		count -= 1;
	}
	return (data);
}
