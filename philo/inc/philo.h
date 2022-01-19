/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/19 14:08:23 by wiozsert         ###   ########.fr       */
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
# include "mutex.h"
# define TRUE 1
# define FALSE 0
# define ALIVE 1
# define DEAD 0
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

# define PD(x) printf("%d\n", x);
# define PL(x) printf("%ld\n", x);
# define PC(x) printf("%c\n", x);
# define PS(x) printf("%s\n", x);
# define ICI printf("ICI\n");
void	print_data(t_data *data);
# define PRTDATA(x) print_data(x);
void	print_dlk(t_dlk *dlk);
# define PRTDLK(x) print_dlk(x);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

void	init_childs(t_philo *philo, int ind);
void	init_manager(t_philo *philo, int ind);
t_philo	*destroy_all_data(t_philo *philo);
t_philo	*init_philo(t_philo *philo, char **av);
void	mall_philo_failed(void);
t_philo	*destroy_philo_and_data(t_philo *philo);
t_philo	*philo_destroyer(t_philo *philo);

#endif