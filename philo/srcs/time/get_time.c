/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:2t6:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/30 15:58:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

// static int	__sec_egal__(t_data *data, t_dlk *dlk, int time)
// {
// 	time = dlk->current_time.tv_usec
// 		- data->starting_time.tv_usec;
// 	time /= 1000;
// 	return (time);
// }

// static int	__sec_not_egal__(t_data *data, t_dlk *dlk, int time)
// {
// 	int	ind;

// 	ind = dlk->current_time.tv_sec - data->starting_time.tv_sec;
// 	if (ind >= 1)
// 	{
// 		time = dlk->current_time.tv_sec
// 			- data->starting_time.tv_sec - 1;
// 		time *= 1000;
// 	}
// 	time = time + ((1000000 - (data->starting_time.tv_usec
// 					- dlk->current_time.tv_usec)) / 1000);
// 	return (time);
// }

// static t_data	*__gettimeofdayfail__(t_data *data)
// {
// 	print_fd(2, "gettimeofday has failed\n");
// 	data->exit_status = -1;
// 	return (data);
// }

// int	get_time(t_data *data, t_dlk *dlk)
// {
// 	int				time;
// 	int				ind;

// 	time = 0;
// 	ind = gettimeofday(&dlk->current_time, NULL);
// 	if (ind == -1)
// 	{
// 		data = __gettimeofdayfail__(data);
// 		return (time);
// 	}
// 	if (data->starting_time.tv_sec == dlk->current_time.tv_sec)
// 		time = __sec_egal__(data, dlk, 0);
// 	else
// 		time = __sec_not_egal__(data, dlk, 0);
// 	return (time);
// }

long	get_time(void)
{
	static struct timeval		tv1;
	static int					tmp;
	struct timeval				tv2;
	struct timeval				tv3;

	if (tmp == 0)
	{
		if (gettimeofday(&tv1, NULL))
			return (-1);
		tmp = 1;
	}
	if (gettimeofday(&tv2, NULL))
		return (-1);
	tv3.tv_sec = tv2.tv_sec - tv1.tv_sec;
	tv3.tv_usec = tv2.tv_usec - tv1.tv_usec;
	if (tv3.tv_usec < 0)
	{
		tv3.tv_sec--;
		tv3.tv_usec += 1000000;
	}
	return (tv3.tv_sec * 1000 + (tv3.tv_usec / 1000));
}
