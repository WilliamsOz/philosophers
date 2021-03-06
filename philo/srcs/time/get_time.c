/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:45:36 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/05 15:38:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

long	get_time(long actual_time_in_ms)
{
	static struct timeval		s_starting_time;
	static int					first_entry = 0;
	struct timeval				tmp_time;
	struct timeval				actual_time;

	if (first_entry == 0)
	{
		gettimeofday(&s_starting_time, NULL);
		first_entry = 1;
	}
	gettimeofday(&tmp_time, NULL);
	actual_time.tv_sec = tmp_time.tv_sec - s_starting_time.tv_sec;
	actual_time.tv_usec = tmp_time.tv_usec - s_starting_time.tv_usec;
	if (actual_time.tv_usec < 0)
	{
		actual_time.tv_sec--;
		actual_time.tv_usec += 1000000;
	}
	actual_time_in_ms = (actual_time.tv_sec * 1000)
		+ (actual_time.tv_usec / 1000);
	return (actual_time_in_ms);
}
