/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:31:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 13:03:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTURE
# define PHILO_STRUCTURE

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
	pthread_t		thread;
	t_data			*data;
	struct s_philo	*next;
	struct s_philo	*previous;
}					t_philo;

#endif