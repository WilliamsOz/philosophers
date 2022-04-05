/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:57:40 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/05 15:18:30 by wiozsert         ###   ########.fr       */
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
# include "./structure.h"
# include "./errors.h"
# include "./utils.h"
# include "./data.h"
# include "./dlk.h"
# include "./mutex.h"
# include "./time.h"
# include "./thread.h"
# define FALSE 0
# define TRUE 1
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3

#endif