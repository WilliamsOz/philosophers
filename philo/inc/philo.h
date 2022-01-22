/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/22 12:15:52 by wiozsert         ###   ########.fr       */
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
# define REDCOLOR printf("\033[0;31m");
# define GRNCOLOR printf("\033[0;32m");
# define YELCOLOR printf("\033[0;33m");
# define BLUCOLOR printf("\033[0;34m");
# define PRPCOLOR printf("\033[0;35m");
# define WHTCOLOR printf("\033[0;37m");
# define ENDCOLOR printf("\033[0m");


//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

# define PD(x) printf("%d\n", x);
# define PL(x) printf("%ld\n", x);
# define PC(x) printf("%c\n", x);
# define PS(x) printf("%s\n", x);
# define PP(x) printf("%p\n", x);
# define ICI printf("ICI\n");
void	print_data(t_data *data);
# define PRTDATA(x) print_data(x);
void	print_dlk(t_dlk *dlk);
# define PRTDLK(x) print_dlk(x);
# define EX exit(EXIT_SUCCESS);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

void	print_status(t_philo *philo, t_dlk *tmp, int ind);
void	*routine_childs(void *arg);
int		init_childs(t_philo *philo, int ind);
int		init_manager(t_philo *philo, int ind);
t_philo	*destroy_all_data(t_philo *philo);
t_philo	*init_philo(t_philo *philo, char **av);
t_philo	*destroy_philo_and_data(t_philo *philo);
t_philo	*philo_destroyer(t_philo *philo);

#endif