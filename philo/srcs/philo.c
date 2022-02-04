/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:19:14 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/04 12:34:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo(t_data *data, t_dlk *dlk, int philo_exit_status)
{
	philo_exit_status = init_childs(data, dlk, data->philo_nbr, 0);
	if (philo_exit_status == -1)
	{
		destroy_all_data(data, dlk);
		return (philo_exit_status);
	}
	// philo_exit_status = manager(data, dlk);
	// if (philo_exit_status != 0)
	// {
		// destroy_all_data(data, dlk);
		// return (philo_exit_status);
	// }
	data = wait_threads(data, dlk);
	if (data->exit_status == -1)
	{
		destroy_all_data(data, dlk);
		return (philo_exit_status);
	}
	destroy_all_mutex(data, dlk);
	destroy_all_data(data, dlk);
	return (philo_exit_status);
}

int	get_data(char **av, int philo_exit_status)
{
	t_data	*data;
	t_dlk	*dlk;

	data = init_data(av);
	if (data == NULL || data->exit_status == -1)
	{
		destroy_all_data(data, NULL);
		return (ERROR);
	}
	dlk = init_dlk(data, data->philo_nbr);
	if (dlk == NULL || data->exit_status == -1)
	{
		destroy_all_data(data, dlk);
		return (ERROR);
	}
	dlk = get_philo_id(dlk);
	if (data->min_must_eat == 0)
	{
		destroy_all_data(data, dlk);
		return (0);
	}
	else
		philo_exit_status = philo(data, dlk, 0);
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
	philo_exit_status = get_data(av, 0);
	return (philo_exit_status);
}
