/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:31:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/26 11:52:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTURE_H
# define PHILO_STRUCTURE_H

typedef struct s_dlk
{
	pthread_t		thread;
	struct timeval	current_time;
	pthread_mutex_t	fork_mutex;
	int				id;
	int				fork;
	int				time;
	int				is_alive;
	int				last_eat_time;
	int				eating_number;
	int				ate;
	pthread_mutex_t	ate_mutex;
	pthread_mutex_t	last_eat_time_mutex;
	pthread_mutex_t	eating_number_mutex;
	struct s_dlk	*next;
	struct s_dlk	*previous;
}				t_dlk;

typedef struct s_data
{
	int				philo_nbr;
	int				die;
	int				eat;
	int				sleep;
	int				min_must_eat;
	struct timeval	starting_time;
}			t_data;

typedef struct s_philo
{
	t_data			*data;
	t_dlk			*dlk;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	exit_status_mutex;
	int				exit_status;
}					t_philo;

#endif