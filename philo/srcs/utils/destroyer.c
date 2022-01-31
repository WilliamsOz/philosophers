/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:45:54 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 18:16:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	destroy_all_data(t_data *data, t_dlk *dlk)
{
	data = data_destroyer(data);
	if (dlk != NULL)
		dlk = dlk_destroyer(dlk);
}

void	destroy_all_mutex(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;
	int		count;

	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->exit_status_mutex);
	count = data->philo_nbr;
	while (count > 0)
	{
		tmp = dlk;
		dlk = dlk->next;
		pthread_mutex_destroy(&tmp->fork_mutex);
		pthread_mutex_destroy(&tmp->last_eat_time_mutex);
		count -= 1;
	}
}
