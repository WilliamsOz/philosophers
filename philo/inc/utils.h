/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:06:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/05 15:24:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_strlen(char *str);
void	print_fd(int fd, char *str);
void	ft_putnbr(long n);

#endif