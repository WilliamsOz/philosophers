/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:09:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:31:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_dlk	*__death_starving__(t_data *data, t_dlk *dlk)
{
	int	time_last_eat;

	pthread_mutex_lock(&dlk->last_eat_time_mutex);
	time_last_eat = 0;
	time_last_eat = (get_time()) - dlk->last_eat_time;
	if (get_time() != dlk->last_eat_time
		&& time_last_eat > (data->die / 1000))
	{
		if ((get_time() - dlk->last_eat_time) > (data->die / 1000))
			dlk->is_alive = DEAD;
	}
	pthread_mutex_unlock(&dlk->last_eat_time_mutex);
	return (dlk);
}

static int	__everyone_ate__(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;
	int		count;

	tmp = dlk;
	count = dlk->data->philo_nbr;
	while (tmp->next != NULL && count > 0)
	{
		pthread_mutex_lock(&dlk->eating_number_mutex);
		if (dlk->eating_number < data->min_must_eat)
		{
			pthread_mutex_unlock(&dlk->eating_number_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(&dlk->eating_number_mutex);
		dlk = dlk->next;
		count -= 1;
	}
	return (TRUE);
}

static t_data	*__philo_is_dead__(t_data *data, t_dlk *tmp)
{
	printf("\033[0;31m");
	printf("%ld %d died\n", get_time(), tmp->id);
	printf("\033[0m");
	return (data);
}

int	manager(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (1)
	{
		tmp = __death_starving__(data, tmp);
		if (tmp->is_alive == DEAD || (data->min_must_eat != -1
				&& __everyone_ate__(data, dlk) == TRUE))
		{
			pthread_mutex_lock(&data->print_mutex);
			pthread_mutex_lock(&data->exit_status_mutex);
			data->exit_status = -1;
			pthread_mutex_unlock(&data->exit_status_mutex);
			break ;
		}
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (tmp->is_alive == DEAD)
		data = __philo_is_dead__(data, tmp);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}
