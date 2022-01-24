/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:45:54 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:19:38 by wiozsert         ###   ########.fr       */
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
