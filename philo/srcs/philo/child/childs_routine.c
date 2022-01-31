/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:02:22 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/31 16:31:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

void	*routine_childs(void *arg)
{
	t_dlk		*dlk;

	dlk = (t_dlk *)arg;
	if (dlk->id % 2 == 0)
		usleep(dlk->data->eat / 2);
	while (is_it_end(dlk) == FALSE)
		__routine__(dlk);
	return (NULL);
}
