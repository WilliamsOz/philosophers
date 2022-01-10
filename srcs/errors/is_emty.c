/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_emty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:03:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 14:04:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	is_empty(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (av[i][0] == '\0')
		{
			print_fd(2, "Error\nEmpty argument\n");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
