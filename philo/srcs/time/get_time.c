/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:35 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:31:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

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
