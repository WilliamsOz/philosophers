/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:35:53 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/12 17:36:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*get_last_node(t_dlk *dlk)
{
	t_dlk	*tmp;

	tmp = dlk;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
