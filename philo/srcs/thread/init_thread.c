/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:10:02 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 13:37:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int	philo_die_by_starve(t_dlk *dlk)
{
	pthread_mutex_lock(&dlk->eat_mutex);
	if ((get_time(dlk->data, 0)
			- dlk->time_last_meal) > dlk->data->die / 1000)
	{
		pthread_mutex_unlock(&dlk->eat_mutex);
		printf("\033[0;31m");
		printf("%ld	%d	died\n", get_time(dlk->data, 0), dlk->id);
		printf("\033[0m");
		pthread_mutex_lock(&dlk->data->end_mutex);
		dlk->data->end = 1;
		pthread_mutex_unlock(&dlk->data->end_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&dlk->eat_mutex);
	return (FALSE);
}

static void	wait_thread(t_dlk *dlk, int number_of_philosopher)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (1)
	{
		pthread_mutex_lock(&dlk->data->end_mutex);
		if (dlk->data->end == 1)
		{
			pthread_mutex_unlock(&dlk->data->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&dlk->data->end_mutex);
		if (philo_die_by_starve(dlk) == TRUE)
			break ;
	}
	while (number_of_philosopher > 0)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		number_of_philosopher -= 1;
	}
}

int	init_thread(t_dlk *dlk, int number_of_philosopher)
{
	get_time(dlk->data, 0);
	while (number_of_philosopher > 0)
	{
		if (pthread_create(&dlk->thread, NULL, &routine, dlk) != 0)
		{
			print_fd(2, "pthread_create has failed\n");
			return (2);
		}
		dlk = dlk->next;
		number_of_philosopher -= 1;
	}
	wait_thread(dlk, dlk->data->number_of_philosopher);
	return (0);
}
