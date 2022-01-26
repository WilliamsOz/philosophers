/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:45:54 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_philo	*destroy_philo_and_data(t_philo *philo)
{
	if (philo->data != NULL)
		philo->data = data_destroyer(philo->data);
	if (philo != NULL)
		philo = philo_destroyer(philo);
	return (philo);
}

t_philo	*destroy_all_data(t_philo *philo)
{
	if (philo->dlk != NULL)
		philo->dlk = dlk_destroyer(philo->dlk);
	philo = destroy_philo_and_data(philo);
	return (philo);
}

void	destroy_all_mutex(t_philo *philo)
{
	t_dlk	*tmp;

	pthread_mutex_destroy(&philo->print_mutex);
	pthread_mutex_destroy(&philo->exit_status_mutex);
	pthread_mutex_destroy(&philo->dlk->fork_mutex);
	pthread_mutex_destroy(&philo->dlk->ate_mutex);
	pthread_mutex_destroy(&philo->dlk->last_eat_time_mutex);
	pthread_mutex_destroy(&philo->dlk->eating_number_mutex);
	tmp = philo->dlk->next;
	if (tmp == NULL)
		return ;
	while (tmp != philo->dlk)
	{
		pthread_mutex_destroy(&tmp->fork_mutex);
		pthread_mutex_destroy(&tmp->ate_mutex);
		pthread_mutex_destroy(&tmp->last_eat_time_mutex);
		pthread_mutex_destroy(&tmp->eating_number_mutex);
		tmp = tmp->next;
	}
}
