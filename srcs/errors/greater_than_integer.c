/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:28:10 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 14:28:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	greater_than_integer(char **av)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		nb = ft_atol(av[i]);
		if (nb > 2147483647)
		{
			print_fd(2, "Error\nGreater than integer\n");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
