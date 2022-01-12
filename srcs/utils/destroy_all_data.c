/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:45:54 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 12:48:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_philo	*destroy_all_data(t_philo *philo)
{
	philo->data = data_destroyer(philo->data);
	philo = philo_destroyer(philo);
	return (philo);
}
