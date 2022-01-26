/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:19:14 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo(char **av, int philo_exit_status)
{
	t_philo	*philo;

	philo = init_philo(av);
	if (philo == NULL)
		return (MALLOC_ERROR);
	if (philo->data->min_must_eat == 0)
	{
		philo = destroy_all_data(philo);
		return (0);
	}
	philo_exit_status = init_childs(philo, 0);
	philo_exit_status = manager(philo);
	if (philo_exit_status != 0)
	{
		philo = destroy_all_data(philo);
		return (philo_exit_status);
	}
	philo = wait_threads(philo, &philo_exit_status);
	if (philo != NULL)
	{
		destroy_all_mutex(philo);
		philo = destroy_all_data(philo);
	}
	return (philo_exit_status);
}

int	main(int ac, char **av)
{
	int		philo_exit_status;

	if (ac != 5 && ac != 6)
	{
		print_fd(2, "Numbers of arguments incorrect\n");
		return (2);
	}
	else if (errors(av) == TRUE)
		return (2);
	philo_exit_status = philo(av, 0);
	return (philo_exit_status);
}
