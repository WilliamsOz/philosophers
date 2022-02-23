/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:51:52 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 19:02:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLK_H
# define DLK_H

t_dlk	*destroy_dlk(t_dlk *dlk);
t_dlk	*init_dlk(t_data *data, int number_of_philosopher);

#endif