/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:07:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 14:14:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
#define MUTEX_H

void	mutex_unlock_has_failed(t_philo *philo);
void	mutex_lock_has_failed(t_philo *philo);

#endif