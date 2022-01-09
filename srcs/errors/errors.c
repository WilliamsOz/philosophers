/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:23:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/09 17:32:58 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	incorrect_arg_num(void)
{
	print_fd(2, "Numbers of arguments incorrect\n");
	exit (EXIT_FAILURE);
}
