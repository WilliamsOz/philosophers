/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:52 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 10:41:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	init_mutex(t_data *data, t_dlk *dlk, int number_of_philosopher)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->end_mutex, NULL);
	while (number_of_philosopher > 0)
	{
		pthread_mutex_init(&dlk->fork_mutex, NULL);
		dlk = dlk->next;
		number_of_philosopher -= 1;
	}
}
