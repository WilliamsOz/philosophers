/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:40:29 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 17:39:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_data
{
	int				number_of_philosopher;
	int				die;
	int				eat;
	int				sleep;
	int				min_must_eat;
	pthread_mutex_t	print_mutex;
	struct timeval	starting_time;
}					t_data;

typedef struct s_dlk
{
	pthread_t		thread;
	struct s_dlk	*next;
	struct s_dlk	*previous;
}					t_dlk;

#endif