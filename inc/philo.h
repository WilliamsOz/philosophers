/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 13:03:44 by wiozsert         ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

# define PD(x) printf("%d\n", x);
# define PC(x) printf("%c\n", x);
# define PS(x) printf("%s\n", x);
# define ICI printf("ICI\n");
void	print_data(t_data *data);
# define PRTDATA(x) print_data(x);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

t_philo	*init_philo(t_philo *philo, char **av);
void	mall_philo_failed(void);
t_philo	*destroy_all_data(t_philo *philo);
t_philo	*philo_destroyer(t_philo *philo);

#endif