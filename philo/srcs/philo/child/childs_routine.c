/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:02:22 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/04 11:23:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

void	*routine_childs(void *arg)
{
	t_dlk		*dlk;

	dlk = (t_dlk *)arg;
	do_routine(dlk);
	return (NULL);
}
