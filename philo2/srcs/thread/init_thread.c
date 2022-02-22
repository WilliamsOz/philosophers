/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:10:02 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/22 18:53:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	wait_thread(t_dlk *dlk, int number_of_philosopher)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (number_of_philosopher > 0)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		number_of_philosopher -= 1;
	}
}

int	init_thread(t_dlk *dlk, int number_of_philosopher)
{
	get_time(0);
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
