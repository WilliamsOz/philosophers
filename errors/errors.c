/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:23:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/07 22:24:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

incorrect_arg_num(void)
{
	print_fd(2, "Numbers of arguments incorrect\n");
	exit (EXIT_FAILURE);
}
