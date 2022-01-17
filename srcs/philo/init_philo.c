/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:01 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/17 13:01:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*get_philo_id(t_dlk *dlk)
{
	t_dlk	*tmp;
	int		i;

	dlk->id = 1;
	tmp = dlk->next;
	i = 2;
	while (tmp != dlk)
	{
		tmp->id = i;
		i++;
		tmp = tmp->next;
	}
	return (dlk);
}

t_philo	*init_philo(t_philo *philo, char **av)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		mall_philo_failed();
	philo->data = NULL;
	philo->data = init_data(philo, av);
	philo->dlk = NULL;
	philo->dlk = init_dlk(philo, philo->data->philo_nbr);
	philo->dlk = get_philo_id(philo->dlk);
	pthread_mutex_init(&philo->print_mutex, NULL);
	return (philo);
}
