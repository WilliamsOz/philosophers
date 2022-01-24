/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:19:14 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:35:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philosophers(t_philo *philo, int ind)
{
	if (ind == 1)
		ind = init_manager(philo, 0);
	else if (ind == 0)
		ind = init_childs(philo, 0);
	return (ind);
}

int	philo(char **av, int philo_exit_status)
{
	t_philo	*philo;

	philo = init_philo(av);
	if (philo == NULL)
		return (MALLOC_ERROR);
	philo_exit_status = init_philosophers(philo, 1);
	if (philo_exit_status != 0)
	{
		philo = destroy_all_data(philo);
		return (philo_exit_status);
	}
	philo_exit_status = init_philosophers(philo, 0);
	if (philo_exit_status != 0)
	{
		philo = destroy_all_data(philo);
		return (philo_exit_status);
	}
	philo = wait_threads(philo, &philo_exit_status);
	if (philo != NULL)
		philo = destroy_all_data(philo);
	return (philo_exit_status);
}

//-fsanitize==thread + leaks a checker
// il reste des exit avec le temp ect

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
