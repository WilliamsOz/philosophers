/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:10:02 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 10:55:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	wait_thread(t_dlk *dlk, int number_of_philosopher)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (1 && dlk->data->end != 1)
	{
		if ((get_time(dlk->data, 0)
				- dlk->time_last_meal) > dlk->data->die / 1000)
		{
			printf("\033[0;31m");
			printf("%ld	%d	died\n", get_time(dlk->data, 0), dlk->id);
			printf("\033[0m");
			pthread_mutex_lock(&dlk->data->end_mutex);
			dlk->data->end = 1;
			pthread_mutex_unlock(&dlk->data->end_mutex);
			break ;
		}
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
