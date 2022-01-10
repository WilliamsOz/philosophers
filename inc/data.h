/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:10 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 16:10:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

void	mall_data_failed(void);
t_data	*get_data(t_data *data, char **av);
t_data	*data_destroyer(t_data *data);
t_data	*init_data(char **av);

#endif