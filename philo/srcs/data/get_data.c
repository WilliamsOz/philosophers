/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:03:40 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/22 11:23:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static	t_data	*__memset_data__(t_data *data)
{
	data->philo_nbr = -1;
	data->die = -1;
	data->eat = -1;
	data->sleep = -1;
	data->min_must_eat = -1;
	return (data);
}

t_data	*get_data(t_data *data, char **av)
{
	data = __memset_data__(data);
	data->philo_nbr = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->min_must_eat = ft_atoi(av[5]);
	data->die *= 1000;
	data->eat *= 1000;
	data->sleep *= 1000;
	return (data);
}
