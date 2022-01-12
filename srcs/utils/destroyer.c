/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:45:54 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 18:06:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_philo	*destroy_philo_and_data(t_philo *philo)
{
	philo->data = data_destroyer(philo->data);
	philo = philo_destroyer(philo);
	return (philo);
}

t_philo	*destroy_all_data(t_philo *philo)
{
	philo->dlk = dlk_destroyer(philo->dlk);
	philo = destroy_philo_and_data(philo);
	return (philo);
}
