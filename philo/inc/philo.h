/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/26 11:48:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "./structures/philo_structure.h"
# include "utils.h"
# include "errors.h"
# include "data.h"
# include "dlk.h"
# include "time.h"
# define ENDCOLOR 
# define ERROR 2
# define MALLOC_ERROR 2
# define THREAD_CREATE_ERROR 2
# define THREAD_JOIN_FAILED 2
# define TRUE 1
# define FALSE 0
# define ALIVE 1
# define DEAD 0
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3

void	destroy_all_mutex(t_philo *philo);
t_dlk	*do_routine(t_philo *philo, t_dlk *dlk);
int		is_it_end(t_philo *philo);
t_philo	*wait_threads(t_philo *philo, int *ptr_philo_exit_status);
void	print_status(t_philo *philo, t_dlk *tmp, int ind);
void	*routine_childs(void *arg);
int		init_childs(t_philo *philo, int ind);
int		manager(t_philo *philo);
t_philo	*destroy_all_data(t_philo *philo);
t_philo	*init_philo(char **av);
t_philo	*destroy_philo_and_data(t_philo *philo);
t_philo	*philo_destroyer(t_philo *philo);

#endif