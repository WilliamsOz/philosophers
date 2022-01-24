/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlk_destroyer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:32:57 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 16:19:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_dlk	*dlk_destroyer(t_dlk *dlk)
{
	t_dlk	*tmp;
	t_dlk	*keep;

	if (dlk->next == NULL)
	{
		free(dlk);
		dlk = NULL;
		return (dlk);
	}
	tmp = dlk->next;
	keep = tmp->next;
	while (tmp != dlk)
	{
		free(tmp);
		tmp = NULL;
		tmp = keep;
		keep = keep->next;
	}
	free(tmp);
	tmp = NULL;
	return (dlk);
}
