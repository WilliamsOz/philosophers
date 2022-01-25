/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:20:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 12:12:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

static int	__thread_childs_create_failed__(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "Creation of thread child has failed\n");
	philo->exit_status = THREAD_CREATE_ERROR;
	return (philo->exit_status);
}

int	init_childs(t_philo *philo, int ind)
{
	t_dlk	*tmp;

	ind = pthread_create(&philo->dlk->thread, NULL,
			&routine_childs, philo);
	if (ind != 0)
		ind = __thread_childs_create_failed__(philo);
	tmp = philo->dlk->next;
	while (ind != ERROR && tmp != NULL && tmp != philo->dlk)
	{
		ind = pthread_create(&tmp->thread, NULL, &routine_childs, philo);
		if (ind != 0)
			ind = __thread_childs_create_failed__(philo);
		tmp = tmp->next;
	}
	return (ind);
}
