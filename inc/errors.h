/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:06:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 11:59:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

int		greater_than_integer(char **av);
int		is_empty(char **av);
int		not_integer(char **av);
void	incorrect_arg_num(void);
int		errors(char **av);

#endif