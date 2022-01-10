/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structure.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:31:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 17:03:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLK_STRUCTURE
# define DLK_STRUCTURE

typedef struct s_philo
{
	pthread_t		thread;
	struct s_philo	*next;
	struct s_philo	*previous;
}					t_philo;

#endif