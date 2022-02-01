/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:09:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/01 18:16:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_dlk	*__death_starving__(t_data *data, t_dlk *dlk)
{
	int	time_last_eat;

	time_last_eat = 0;
	pthread_mutex_lock(&dlk->fork_mutex);
	time_last_eat = (get_time()) - dlk->last_eat_time;
	if (get_time() != dlk->last_eat_time
		&& time_last_eat > (data->die / 1000))
	{
		if ((get_time() - dlk->last_eat_time) > (data->die / 1000))
		{
			dlk->is_alive = DEAD;
			pthread_mutex_unlock(&dlk->fork_mutex);
			return (dlk);
		}
	}
	pthread_mutex_unlock(&dlk->fork_mutex);
	return (dlk);
}

// static int	__everyone_ate__(t_dlk *dlk)
// {
// 	t_dlk	*tmp;
// 	int		count;

// 	tmp = dlk;
// 	count = dlk->data->philo_nbr;
// 	while (tmp->next != NULL && count > 0)
// 	{
// 		if (dlk->eating_number != -1)
// 			return (FALSE);
// 		dlk = dlk->next;
// 		count -= 1;
// 	}
// 	return (TRUE);
// }

static void	philo_is_dead(t_dlk *dlk, int count)
{
	while (count > 0)
	{
		if (dlk->is_alive == DEAD)
		{
			printf("\033[0;31m");
			printf("%ld %d died\n", get_time(), dlk->id);
			printf("\033[0m");
			return ;
		}
		dlk = dlk->next;
		count -= 1;
	}
}

int	manager(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (1)
	{
		tmp = __death_starving__(data, tmp);
		pthread_mutex_lock(&data->exit_status_mutex);
		if (data->exit_status == -1 || dlk->is_alive == DEAD)
		{
			// pthread_mutex_lock(&data->print_mutex);
			pthread_mutex_unlock(&data->exit_status_mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&data->exit_status_mutex);
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	philo_is_dead(dlk, dlk->data->philo_nbr);
	// pthread_mutex_unlock(&data->print_mutex);
	return (0);
}
