/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:59:04 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 13:01:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

t_data	*get_starting_time(t_philo *philo);
t_data	*init_data(t_philo *philo, char **av);
t_data	*get_data(t_data *data, char **av);
t_data	*init_data(t_philo *philo, char **av);
t_data	*data_destroyer(t_data *data);

#endif