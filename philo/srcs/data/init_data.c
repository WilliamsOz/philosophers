/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:01:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:20:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_data	*__mall_data_failed__(t_data *data)
{
	print_fd(2, "Malloc of data has failed\n");
	data->exit_status = -1;
	return (data);
}

t_data	*init_data(char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		data = __mall_data_failed__(data);
		return (NULL);
	}
	data = get_philo_data(data, av);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->exit_status_mutex, NULL);
	data = get_starting_time(data);
	return (data);
}
