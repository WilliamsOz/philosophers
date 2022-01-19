/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:20:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 17:59:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__thread_childs_create_failed__(t_philo *philo)
{
	t_dlk	*tmp;

	tmp = philo->dlk->next;
	while (tmp != philo->dlk)
	{
		pthread_exit(&tmp->thread);
		tmp = tmp->next;
	}
	pthread_exit(&philo->thread);
	philo = destroy_all_data(philo);
	print_fd(2, "Creation of thread child has failed\n");
	exit (EXIT_FAILURE);
}

void	init_childs(t_philo *philo, int ind)
{
	t_dlk	*tmp;

	ind = pthread_create(&philo->dlk->thread, NULL,
			&routine_childs, philo);
	if (ind != 0)
		__thread_childs_create_failed__(philo);
	tmp = philo->dlk->next;
	while (tmp != NULL && tmp != philo->dlk)
	{
		ind = pthread_create(&tmp->thread, NULL, &routine_childs, philo);
		if (ind != 0)
			__thread_childs_create_failed__(philo);
		tmp = tmp->next;
	}
}
