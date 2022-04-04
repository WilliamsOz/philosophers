/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:04:16 by wiozsert          #+#    #+#             */
/*   Updated: 2022/04/04 10:24:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_data	*destroy_data(t_data *data)
{
	if (data != NULL)
	{
		free(data);
		data = NULL;
	}
	return (data);
}
