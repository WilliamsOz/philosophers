/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 16:06:32 by wiozsert         ###   ########.fr       */
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
# include "./structures/data_structure.h"
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


//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

#endif