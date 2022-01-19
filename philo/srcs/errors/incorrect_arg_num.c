/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorrect_arg_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:05:25 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 14:05:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	incorrect_arg_num(void)
{
	print_fd(2, "Numbers of arguments incorrect\n");
	exit (EXIT_FAILURE);
}
