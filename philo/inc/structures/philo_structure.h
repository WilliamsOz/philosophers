/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:31:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 18:59:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTURE_H
# define PHILO_STRUCTURE_H

typedef struct s_data
{
	int				philo_nbr;
	long			die;
	long			eat;
	long			sleep;
	long			min_must_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	exit_status_mutex;
	int				exit_status;
	struct timeval	starting_time;
}			t_data;

typedef struct s_dlk
{
	pthread_t		thread;
	struct timeval	current_time;
	pthread_mutex_t	fork_mutex;
	int				id;
	int				fork;
	int				is_alive;
	long			last_eat_time;
	int				eating_number;
	struct s_dlk	*next;
	struct s_dlk	*previous;
	t_data			*data;
}				t_dlk;

#endif