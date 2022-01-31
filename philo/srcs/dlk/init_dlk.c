/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dlk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:26:42 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:19:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_data	*__mall_dlk_failed__(t_data *data)
{
	print_fd(2, "Malloc of dlk has failed\n");
	data->exit_status = -1;
	return (data);
}

static t_data	*__mall_new_node_failed__(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;

	while (dlk != NULL)
	{
		tmp = dlk;
		dlk = dlk->next;
		free(tmp);
		tmp = NULL;
	}
	print_fd(2, "Malloc of new_node_dlk has failed\n");
	data->exit_status = -1;
	return (data);
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
		new_node->next = NULL;
		new_node->time = 0;
		new_node->is_alive = ALIVE;
		new_node->fork = 1;
		new_node->last_eat_time = 0;
		new_node->eating_number = 0;
		new_node->data = data;
		pthread_mutex_init(&new_node->fork_mutex, NULL);
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
	dlk->next = NULL;
	dlk->previous = NULL;
	dlk->time = 0;
	dlk->is_alive = ALIVE;
	dlk->fork = 1;
	dlk->last_eat_time = 0;
	dlk->eating_number = 0;
	dlk->data = data;
	dlk = __get_all_node__(data, dlk, philo_nbr -1);
	if (dlk != NULL)
		dlk = link_dlk(dlk);
	if (dlk->next == NULL)
		dlk->next = dlk;
	return (dlk);
}
