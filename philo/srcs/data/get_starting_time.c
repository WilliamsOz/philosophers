/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:58:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:10:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_data	*__gettimeofday_failed__(t_data *data)
{
	print_fd(2, "gettimeofday has failed\n");
	data->exit_status = -1;
	return (data);
}

t_data	*get_starting_time(t_data *data)
{
	int	ind;

	ind = gettimeofday(&data->starting_time, NULL);
	if (ind == -1)
		data = __gettimeofday_failed__(data);
	return (data);
}
