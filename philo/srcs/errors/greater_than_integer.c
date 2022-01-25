/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:28:10 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 15:26:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	greater_than_integer(char **av)
{
	long	nb;
	int		i;

	i = 1;
	while (av[i] != NULL)
	{
		nb = ft_atol(av[i]);
		if (nb > 2147483647)
		{
			print_fd(2, "Error\nGreater than integer\n");
			return (TRUE);
		}
		else if (i == 1 && nb == 0)
		{
			print_fd(2, "Error\nNumber of philosopher can't be zero\n");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
