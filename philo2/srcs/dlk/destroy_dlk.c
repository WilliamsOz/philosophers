/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_dlk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:52:45 by wiozsert          #+#    #+#             */
/*   Updated: 2022/02/21 19:11:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*destroy_dlk(t_dlk *dlk)
{
	t_dlk	*tmp;
	int		number_of_philosopher;

	number_of_philosopher = dlk->data->number_of_philosopher;
	while (number_of_philosopher > 0)
	{
		tmp = dlk;
		dlk = dlk->next;
		free(tmp);
		number_of_philosopher -= 1;
	}
	return (dlk);
}