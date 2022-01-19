/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 16:55:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	__philo_sleep(t_philo *philo, t_dlk	*tmp)
{
	if (pthread_mutex_lock(&philo->print_mutex) != 0)
		mutex_lock_has_failed(philo);
	BLUCOLOR
	printf("%d %d is sleeping\n", get_time(philo), tmp->id);
	ENDCOLOR
	if (pthread_mutex_unlock(&philo->print_mutex) != 0)
		mutex_unlock_has_failed(philo);
}

static void	__philo_eat__(t_philo *philo, t_dlk *tmp)
{
	if (pthread_mutex_lock(&philo->print_mutex) != 0)
		mutex_lock_has_failed(philo);
	GRNCOLOR
	printf("%d %d is eating\n", get_time(philo), tmp->id);
	ENDCOLOR
	if (pthread_mutex_unlock(&philo->print_mutex) != 0)
		mutex_unlock_has_failed(philo);
}

static void	__philo_fork__(t_philo *philo, t_dlk *tmp)
{
	if (pthread_mutex_lock(&philo->print_mutex) != 0)
		mutex_lock_has_failed(philo);
	YELCOLOR
	printf("%d %d has taken a fork\n", get_time(philo), tmp->id);
	printf("%d %d has taken a fork\n", get_time(philo), tmp->id);
	ENDCOLOR
	if (pthread_mutex_unlock(&philo->print_mutex) != 0)
		mutex_unlock_has_failed(philo);
}

static void	__philo_think__(t_philo *philo, t_dlk *tmp)
{
	if (pthread_mutex_lock(&philo->print_mutex) != 0)
		mutex_lock_has_failed(philo);
	PRPCOLOR
	printf("%d %d is thinking\n", get_time(philo), tmp->id);
	ENDCOLOR
	if (pthread_mutex_unlock(&philo->print_mutex) != 0)
		mutex_unlock_has_failed(philo);
}

void	print_status(t_philo *philo, t_dlk *tmp, int ind)
{
	if (ind == FORK)
		__philo_fork__(philo, tmp);
	else if (ind == EAT)
		__philo_eat__(philo, tmp);
	else if (ind == SLEEP)
		__philo_sleep(philo, tmp);
	else if (ind == THINK)
		__philo_think__(philo, tmp);
}
