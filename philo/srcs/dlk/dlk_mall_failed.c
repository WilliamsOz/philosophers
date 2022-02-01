/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlk_mall_failed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:52:47 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/01 14:53:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_data	*__mall_dlk_failed__(t_data *data)
{
	print_fd(2, "Malloc of dlk has failed\n");
	data->exit_status = -1;
	return (data);
}

t_data	*__mall_new_node_failed__(t_data *data, t_dlk *dlk)
{
	t_dlk	*tmp;

	while (dlk != NULL)
	{
		tmp = dlk;
		dlk = dlk->next;
		free(tmp);
		tmp = NULL;
	}
	print_fd(2, "Malloc of new_node_dlk has failed\n");
	data->exit_status = -1;
	return (data);
}
