/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:44:18 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 19:08:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo(char **av, int exit_status)
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
	data = destroy_data(data);
	dlk = destroy_dlk(dlk);
	return (exit_status);
}

int main (int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		print_fd(2, "Numbers of arguments incorrect\n");
		return (2);
	}
	else if (errors(av) == TRUE)
		return (2);
	return (philo(av, 0));
}