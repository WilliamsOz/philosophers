/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:22:20 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:38:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_philo	*__pthread_join_failed__(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "pthread join has failed\n");
	return (philo);
}

static t_philo	*__wait_manager__(t_philo *philo, int *ptr_philo_exit_status)
{
	if (pthread_join(philo->thread, NULL) != 0)
	{
		philo = __pthread_join_failed__(philo);
		*ptr_philo_exit_status = THREAD_JOIN_FAILED;
	}
	return (philo);
}

static t_philo	*__wait_childs__(t_philo *philo, int *ptr_philo_exit_status)
{
	t_dlk	*tmp;

	while (philo->dlk->next != NULL && philo->dlk->id != 1)
		philo->dlk = philo->dlk->next;
	tmp = philo->dlk;
	if (pthread_detach(tmp->thread) != 0)
	{
		philo = __pthread_join_failed__(philo);
		*ptr_philo_exit_status = THREAD_JOIN_FAILED;
	}
	tmp = tmp->next;
	while (tmp->next != NULL && tmp->id != 1)
	{
		if (pthread_detach(tmp->thread) != 0)
		{
			philo = __pthread_join_failed__(philo);
			*ptr_philo_exit_status = THREAD_JOIN_FAILED;
		}
		tmp = tmp->next;
	}
	return (philo);
}

t_philo	*wait_threads(t_philo *philo, int *ptr_philo_exit_status)
{
	int	philo_exit_status;

	philo_exit_status = 0;
	philo = __wait_manager__(philo, &philo_exit_status);
	if (philo == NULL)
		return (philo);
	philo = __wait_childs__(philo, &philo_exit_status);
	*ptr_philo_exit_status = philo_exit_status;
	return (philo);
}
