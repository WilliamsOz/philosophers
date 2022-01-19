/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:09:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 17:46:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__thread_manager_create_failed__(t_philo *philo)
{
	philo = destroy_all_data(philo);
	print_fd(2, "Creation of thread manager has failed\n");
	exit (EXIT_FAILURE);
}

t_dlk	*death_starving(t_philo *philo, t_dlk *dlk)
{
	if ((get_time(philo) - dlk->last_eat_time) > (philo->data->die / 1000))
		dlk->is_alive = DEAD;
	return (dlk);
}

static void	*__routine_manager__(void *arg)
{
	t_philo	*philo;
	t_dlk	*tmp;

	philo = (t_philo *)arg;
	tmp = philo->dlk;
	while (1)
	{
		if (tmp->is_alive == DEAD)
			break ;
		else if (tmp->next != NULL)
			tmp = tmp->next;
		tmp = death_starving(philo, tmp);
	}
	if (tmp->is_alive 	== DEAD)
	{
		REDCOLOR
		printf("%d %d died\n", get_time(philo), tmp->id);
		ENDCOLOR
		exit (EXIT_SUCCESS);
	}
	return (NULL);
}

void	init_manager(t_philo *philo, int ind)
{
	ind = pthread_create(&philo->thread, NULL,
			&__routine_manager__, philo);
	if (ind != 0)
		__thread_manager_create_failed__(philo);
}
