/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:10:15 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/22 18:23:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

void	print_status(t_data *data, t_dlk *dlk, int ind);
void	*routine(void *arg);
int		init_thread(t_dlk *dlk, int number_of_philosopher);

#endif