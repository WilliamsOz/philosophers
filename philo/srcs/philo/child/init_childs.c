/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:20:11 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/04 11:09:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

static int	__thread_childs_create_failed__(t_data *data)
{
	print_fd(2, "Creation of thread child has failed\n");
	data->exit_status = -1;
	return (data->exit_status);
}

int	init_childs(t_data *data, t_dlk *dlk, int count, int ind)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (tmp->next != NULL && count > 0 && ind != -1)
	{
		ind = pthread_create(&tmp->thread, NULL, &routine_childs, tmp);
		if (ind != 0)
			ind = __thread_childs_create_failed__(data);
		tmp = tmp->next;
		count -= 1;
	}
	return (ind);
}
