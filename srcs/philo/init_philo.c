/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:50:01 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 13:03:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_philo	*__memset_philo__(t_philo *philo)
{
	philo->data = NULL;
	philo->next = NULL;
	philo->previous = NULL;
	return (philo);
}

t_philo	*init_philo(t_philo *philo, char **av)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		mall_philo_failed();
	philo = __memset_philo__(philo);
	philo->data = init_data(philo, av);
	return (philo);
}
