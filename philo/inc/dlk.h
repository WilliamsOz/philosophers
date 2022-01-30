/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:27:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/30 16:19:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLK_H
# define DLK_H

t_dlk	*init_dlk_mutex(t_dlk *dlk);
t_dlk	*get_philo_id(t_dlk *dlk);
t_dlk	*get_last_node(t_dlk *dlk);
t_dlk	*init_dlk(t_data *data, int philo_nbr);
t_dlk	*dlk_destroyer(t_dlk *dlk);

#endif