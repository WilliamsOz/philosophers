/* ************************************************************************** */
/*                                                                            *//*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:06:33 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/07 22:19:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	not_integer(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' && av[i][j] > '9')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	is_empty(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (av[i][0] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	parsing_errors(char **av)
{
	if (not_integer(av) == TRUE)
		return (TRUE);
	else if (is_empty(av) == TRUE)
		return (TRUE);
	return (FALSE);
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 5 || ac != 6)
		incorrect_arg_num();
	if (parsing_errors(av) == TRUE)
		exit (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

