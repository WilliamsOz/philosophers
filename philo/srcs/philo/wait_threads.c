/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:22:20 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 15:32:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_data	*__pthread_join_failed__(t_data *data)
{
	print_fd(2, "pthread join has failed\n");
	data->exit_status = -1;
	return (data);
}

static t_data	*__wait_childs__(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;

	tmp = dlk;
	if (pthread_join(tmp->thread, NULL) != 0)
	{
		data = __pthread_join_failed__(data);
		return (data);
	}
	if (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->next != NULL && tmp->id != 1)
	{
		if (pthread_join(tmp->thread, NULL) != 0)
		{
			data = __pthread_join_failed__(data);
			return (data);
		}
		tmp = tmp->next;
	}
	return (data);
}

t_data	*wait_threads(t_data *data, t_dlk *dlk)
{
	int	philo_exit_status;

	philo_exit_status = 0;
	data = __wait_childs__(data, dlk);
	return (data);
}
