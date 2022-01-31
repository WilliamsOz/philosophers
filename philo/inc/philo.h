/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:00:29 by wiozsert         ###   ########.fr       */
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
# define ERROR 2
# define TRUE 1
# define FALSE 0
# define ALIVE 1
# define DEAD 0
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3

void	__routine__(t_dlk *dlk);
int		is_it_end(t_dlk *dlk);
void	*routine_childs(void *arg);
void	print_status(t_data *data, t_dlk *tmp, int ind);
t_data	*wait_threads(t_data *data, t_dlk *dlk);
int		manager(t_data *data, t_dlk *dlk);
int		init_childs(t_data *data, t_dlk *dlk, int count, int ind);
void	destroy_all_mutex(t_data *data, t_dlk *dlk);
void	destroy_all_data(t_data *data, t_dlk *dlk);

#endif