/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_philo_failed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 11:56:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	mall_philo_failed(void)
{
	print_fd(2, "Malloc of philo has failed\n");
	exit (EXIT_FAILURE);
}
