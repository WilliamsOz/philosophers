/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/22 18:21:23 by wiozsert         ###   ########.fr       */
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

# define PD(x) printf("%d\n", x);
# define PL(x) printf("%ld\n", x);
# define PC(x) printf("%c\n", x);
# define PS(x) printf("%s\n", x);
# define PP(x) printf("%p\n", x);
# define ICI printf("ICI\n");
void    print_data(t_data *data);
# define PRTDATA(x) print_data(x);
void    print_dlk(t_dlk *dlk);
# define PRTDLK(x) print_dlk(x);
# define EX exit(EXIT_SUCCESS);

t_dlk	*do_routine(t_dlk *dlk);
void	*routine_childs(void *arg);
void	print_status(t_data *data, t_dlk *tmp, int ind);
t_data	*wait_threads(t_data *data, t_dlk *dlk);
int		manager(t_data *data, t_dlk *dlk);
int		init_childs(t_data *data, t_dlk *dlk, int count, int ind);
void	destroy_all_mutex(t_data *data, t_dlk *dlk);
void	destroy_all_data(t_data *data, t_dlk *dlk);

#endif