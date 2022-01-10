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

void	philo(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("OK\n");
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		incorrect_arg_num();
	if (errors(av) == TRUE)
		exit (EXIT_FAILURE);
	philo(ac, av);
	return (EXIT_SUCCESS);
}

