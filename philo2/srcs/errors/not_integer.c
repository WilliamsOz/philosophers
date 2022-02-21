/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:02:36 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 11:22:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	not_integer(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == '-')
			{
				print_fd(2, "Error\nNegative argument\n");
				return (TRUE);
			}
			else if (av[i][j] < '0' || av[i][j] > '9')
			{
				print_fd(2, "Error\nNot integer argument\n");
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}
