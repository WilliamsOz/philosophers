/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:01 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/16 16:22:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_philo	*init_philo(t_philo *philo, char **av)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		mall_philo_failed();
	philo->data = NULL;
	philo->data = init_data(philo, av);
	philo->dlk = NULL;
	philo->dlk = init_dlk(philo, philo->data->philo_nbr);
	return (philo);
}
