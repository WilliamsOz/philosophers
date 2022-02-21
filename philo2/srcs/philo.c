/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:44:18 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 18:09:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_dlk	*init_dlk(int number_of_philosopher)
{
	t_dlk	*dlk;

	dlk = (t_dlk *)malloc(sizeof(t_dlk));
	if (dlk == NULL)
		return (NULL);
	
	return (dlk);
}

int	philo(char **av, int exit_status)
{
	t_data	*data;
	t_dlk	*dlk;

	data = init_data(av);
	if (data == NULL)
		return (2);
	dlk = init_dlk(data->number_of_philosopher);
	if (dlk == NULL)
	{
		data = destroy_data(data);
		return (2);
	}
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