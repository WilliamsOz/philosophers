/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:09:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 16:34:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static t_dlk	*__death_starving__(t_philo *philo, t_dlk *dlk)
{
	int	time_last_eat;

	pthread_mutex_lock(&dlk->last_eat_time_mutex);
	time_last_eat = 0;
	time_last_eat = (get_time(philo)) - dlk->last_eat_time;
	if (get_time(philo) != dlk->last_eat_time
		&& time_last_eat > (philo->data->die / 1000))
	{
		if ((get_time(philo) - dlk->last_eat_time) > (philo->data->die / 1000))
			dlk->is_alive = DEAD;
	}
	pthread_mutex_unlock(&dlk->last_eat_time_mutex);
	return (dlk);
}

static int	__everyone_ate__(t_philo *philo)
{
	t_dlk	*dlk;

	if (philo->dlk->next == NULL)
		return (FALSE);
	dlk = philo->dlk->next;
	while (dlk != philo->dlk)
	{
		pthread_mutex_lock(&dlk->eating_number_mutex);
		if (dlk->eating_number < philo->data->min_must_eat)
		{
			pthread_mutex_unlock(&dlk->eating_number_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(&dlk->eating_number_mutex);
		dlk = dlk->next;
	}
	return (TRUE);
}

static t_philo	*__philo_is_dead__(t_philo *philo, t_dlk *tmp)
{
	printf("\033[0;31m");
	printf("%d %d died\n", get_time(philo), tmp->id);
	printf("\033[0m");
	return (philo);
}

int	manager(t_philo *philo)
{
	t_dlk	*tmp;

	tmp = philo->dlk;
	while (1)
	{
		tmp = __death_starving__(philo, tmp);
		if (tmp->is_alive == DEAD || (philo->data->min_must_eat != -1
				&& __everyone_ate__(philo) == TRUE))
		{
			pthread_mutex_lock(&philo->print_mutex);
			pthread_mutex_lock(&philo->exit_status_mutex);
			philo->exit_status = -1;
			pthread_mutex_unlock(&philo->exit_status_mutex);
			break ;
		}
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (tmp->is_alive == DEAD)
		philo = __philo_is_dead__(philo, tmp);
	pthread_mutex_unlock(&philo->print_mutex);
	return (0);
}
