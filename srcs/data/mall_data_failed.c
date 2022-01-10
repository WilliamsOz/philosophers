/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_data_failed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:01:50 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 17:22:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	mall_data_failed(void)
{
	print_fd(2, "Malloc of data has failed\n");
	exit (EXIT_FAILURE);
}
