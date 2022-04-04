/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:44:18 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 15:17:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo(char **av)
{
	t_data	*data;
	t_dlk	*dlk;

	data = init_data(av);
	if (data == NULL)
		return (2);
	dlk = init_dlk(data, data->number_of_philosopher);
	if (dlk == NULL)
	{
		data = destroy_data(data);
		return (2);
	}
	init_mutex(data, dlk, data->number_of_philosopher);
	if (init_thread(dlk, data->number_of_philosopher) == 2)
	{
		dlk = destroy_dlk(dlk);
		data = destroy_data(data);
		return (2);
	}
	dlk = destroy_dlk(dlk);
	data = destroy_data(data);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		print_fd(2, "Numbers of arguments incorrect\n");
		return (2);
	}
	else if (errors(av) == TRUE)
		return (2);
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (0);
	return (philo(av));
}
