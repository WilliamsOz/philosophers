/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:03:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/09 17:31:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0

// typedef struct s_philo
// {
	
// }				t_philo;

void	incorrect_arg_num(void);
int		ft_strlen(char *str);
void	print_fd(int fd, char *str);

#endif