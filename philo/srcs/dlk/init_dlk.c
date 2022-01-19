/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dlk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:26:42 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 17:29:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__mall_dlk_failed__(t_philo *philo)
{
	philo = destroy_philo_and_data(philo);
	print_fd(2, "Malloc of dlk has failed\n");
	exit (EXIT_FAILURE);
}

static void	__mall_new_node_failed__(t_philo *philo, t_dlk *dlk)
{
	t_dlk	*tmp;

	while (dlk != NULL)
	{
		tmp = dlk;
		dlk = dlk->next;
		free(tmp);
		tmp = NULL;
	}
	philo = destroy_philo_and_data(philo);
	print_fd(2, "Malloc of new_node_dlk has failed\n");
	exit (EXIT_FAILURE);
}

static t_dlk	*__get_all_node__(t_philo *philo, t_dlk *dlk, int philo_nbr)
{
	t_dlk	*new_node;
	t_dlk	*tmp;

	while (philo_nbr > 0)
	{
		new_node = NULL;
		new_node = (t_dlk *)malloc(sizeof(t_dlk));
		if (new_node == NULL)
			__mall_new_node_failed__(philo, dlk);
		new_node->next = NULL;
		new_node->time = 0;
		new_node->is_alive = ALIVE;
		new_node->fork = 1;
		new_node->last_eat_time = 0;
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

t_dlk	*init_dlk(t_philo *philo, int philo_nbr)
{
	t_dlk	*dlk;

	dlk = NULL;
	dlk = (t_dlk *)malloc(sizeof(t_dlk));
	if (dlk == NULL)
		__mall_dlk_failed__(philo);
	dlk->next = NULL;
	dlk->previous = NULL;
	dlk->time = 0;
	dlk->is_alive = ALIVE;
	dlk->fork = 1;
	dlk->last_eat_time = 0;
	pthread_mutex_init(&dlk->fork_mutex, NULL);
	dlk = __get_all_node__(philo, dlk, philo_nbr -1);
	dlk = link_dlk(dlk);
	return (dlk);
}
