/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dlk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:26:42 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/22 15:24:44 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_dlk	*memset_dlk_data(t_data *data, t_dlk *dlk)
{
	dlk->next = NULL;
	dlk->previous = NULL;
	dlk->is_alive = ALIVE;
	dlk->last_eat_time = 0;
	dlk->eating_number = 0;
	dlk->data = data;
	pthread_mutex_init(&dlk->fork_mutex, NULL);
	return (dlk);
}

static t_dlk	*__get_all_node__(t_data *data, t_dlk *dlk, int philo_nbr)
{
	t_dlk	*new_node;
	t_dlk	*tmp;

	while (philo_nbr > 0)
	{
		new_node = NULL;
		new_node = (t_dlk *)malloc(sizeof(t_dlk));
		if (new_node == NULL)
		{
			data = __mall_new_node_failed__(data, dlk);
			return (NULL);
		}
		new_node = memset_dlk_data(data, new_node);
		tmp = get_last_node(dlk);
		tmp->next = new_node;
		philo_nbr--;
	}
	return (dlk);
}

t_dlk	*link_dlk(t_dlk *dlk)
{
	t_dlk	*keep;
	t_dlk	*tmp;

	if (dlk->next == NULL)
		return (dlk);
	tmp = get_last_node(dlk);
	tmp->next = dlk;
	dlk->previous = tmp;
	tmp = dlk->next;
	while (tmp != dlk)
	{
		keep = dlk;
		while (keep->next != tmp)
			keep = keep->next;
		tmp->previous = keep;
		tmp = tmp->next;
	}
	return (dlk);
}

t_dlk	*init_dlk(t_data *data, int philo_nbr)
{
	t_dlk	*dlk;

	dlk = NULL;
	dlk = (t_dlk *)malloc(sizeof(t_dlk));
	if (dlk == NULL)
	{
		data = __mall_dlk_failed__(data);
		return (NULL);
	}
	dlk = memset_dlk_data(data, dlk);
	if (dlk->data->philo_nbr != 1)
		dlk = __get_all_node__(data, dlk, philo_nbr -1);
	if (dlk != NULL)
		dlk = link_dlk(dlk);
	if (dlk->next == NULL)
		dlk->next = dlk;
	return (dlk);
}
