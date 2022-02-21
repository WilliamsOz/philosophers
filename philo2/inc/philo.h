/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:57:40 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 18:06:41 by wiozsert         ###   ########.fr       */
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
# define FALSE 0
# define TRUE 1

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
# define PD(x) printf("%d\n", x);
# define PL(x) printf("%ld\n", x);
# define PC(x) printf("%c\n", x);
# define PS(x) printf("%s\n", x);
# define PP(x) printf("%p\n", x);
# define ICI printf("ICI\n");
# define EX exit(EXIT_SUCCESS);
//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

#endif