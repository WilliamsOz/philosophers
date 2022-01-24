/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:09:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:30:32 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_dlk	*__death_starving__(t_philo *philo, t_dlk *dlk)
{
	int	time_last_eat;

	time_last_eat = 0;
	time_last_eat = (get_time(philo)) - dlk->last_eat_time; 
	if (get_time(philo) != dlk->last_eat_time
		&& time_last_eat > (philo->data->die / 1000))
	{
		if ((get_time(philo) - dlk->last_eat_time) > (philo->data->die / 1000))
			dlk->is_alive = DEAD;
	}
	return (dlk);
}

static int	__everyone_ate__(t_philo *philo)
{
	t_dlk	*dlk;

	dlk = philo->dlk->next;
	while (dlk != philo->dlk)
	{
		if (dlk->eating_number < philo->data->min_must_eat)
			return (FALSE);
		dlk = dlk->next;
	}
	return (TRUE);
}

static void	*__routine_manager__(void *arg)
{
	t_philo	*philo;
	t_dlk	*tmp;

	philo = (t_philo *)arg;
	tmp = philo->dlk;
	while (1)
	{
		if (philo->data->min_must_eat != -1 && __everyone_ate__(philo) == TRUE)
		{
			philo->exit_status = -1;
			break ;
		}
		if (tmp->is_alive == DEAD)
			break ;
		else if (tmp->next != NULL)
			tmp = tmp->next;
		tmp = __death_starving__(philo, tmp);
	}
	if (tmp->is_alive == DEAD)
	{
		pthread_mutex_lock(&philo->print_mutex);
		REDCOLOR
		printf("%d %d died\n", get_time(philo), tmp->id);
		ENDCOLOR
		philo->exit_status = -1;
	}
	return (NULL);
}

int	init_manager(t_philo *philo, int ind)
{
	ind = pthread_create(&philo->thread, NULL,
			&__routine_manager__, philo);
	if (ind != 0)
	{
		print_fd(2, "Creation of thread manager has failed\n");
		return (THREAD_CREATE_ERROR);
	}
	return (philo->exit_status);
}
