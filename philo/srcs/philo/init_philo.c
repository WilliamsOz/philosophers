/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:01 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 11:31:53 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*get_philo_id(t_dlk *dlk)
{
	t_dlk	*tmp;
	int		i;

	dlk->id = 1;
	pthread_mutex_init(&dlk->ind_mutex, NULL);
	pthread_mutex_init(&dlk->fork_mutex, NULL);
	tmp = dlk->next;
	i = 2;
	while (tmp != NULL && tmp != dlk)
	{
		pthread_mutex_init(&tmp->ind_mutex, NULL);
		pthread_mutex_init(&tmp->fork_mutex, NULL);
		tmp->id = i;
		tmp->ind = 0;
		i++;
		tmp = tmp->next;
	}
	return (dlk);
}

t_philo	*init_philo(t_philo *philo, char **av)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->exit_status = 0;
	philo->data = NULL;
	philo->data = init_data(philo, av);
	if (philo->data == NULL)
		return (NULL);
	philo->dlk = NULL;
	philo->dlk = init_dlk(philo, philo->data->philo_nbr);
	if (philo->dlk == NULL)
		return (NULL);
	philo->dlk = get_philo_id(philo->dlk);
	pthread_mutex_init(&philo->print_mutex, NULL);
	return (philo);
}
