/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dlk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:51:26 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/22 18:59:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_dlk	*malloc_node_has_failed(t_dlk *dlk)
{
	t_dlk	*tmp;

	while (dlk != NULL)
	{
		tmp = dlk;
		dlk = dlk->next;
		free(tmp);
	}
	return (dlk);
}

static t_dlk	*get_all_node(t_dlk *dlk, int number_of_philosopher)
{
	t_dlk	*tmp;
	t_dlk	*keep;

	while (number_of_philosopher > 0)
	{
		tmp = (t_dlk *)malloc(sizeof(t_dlk));
		if (tmp == NULL)
		{
			dlk = malloc_node_has_failed(dlk);
			return (dlk);
		}
		tmp->next = NULL;
		keep = dlk;
		while (keep->next != NULL)
			keep = keep->next;
		keep->next = tmp;
		number_of_philosopher -= 1;
	}
	return (dlk);
}

static t_dlk	*set_dlk(t_data *data, t_dlk *dlk, int id)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (tmp->next != NULL)
	{
		tmp->time_last_meal = 0;
		tmp->number_of_meal = 0;
		tmp->data = data;
		tmp->id = id;
		id += 1;
		tmp = tmp->next;
	}
	tmp->time_last_meal = 0;
	tmp->number_of_meal = 0;
	tmp->data = data;
	tmp->id = id;
	tmp->next = dlk;
	dlk->previous = tmp;
	return (dlk);
}

static t_dlk	*link_dlk(t_dlk *dlk, int number_of_philosopher)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (number_of_philosopher > 0)
	{
		dlk = dlk->next;
		dlk->previous = tmp;
		tmp = tmp->next;
		number_of_philosopher -= 1;
	}
	return (dlk);
}

t_dlk	*init_dlk(t_data *data, int number_of_philosopher)
{
	t_dlk	*dlk;

	dlk = (t_dlk *)malloc(sizeof(t_dlk));
	if (dlk == NULL)
		return (NULL);
	dlk->next = NULL;
	dlk = get_all_node(dlk, number_of_philosopher - 1);
	dlk = set_dlk(data, dlk, 1);
	if (number_of_philosopher != 1)
		dlk = link_dlk(dlk, number_of_philosopher);
	return (dlk);
}
