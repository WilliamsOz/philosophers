/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:02:22 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/25 16:34:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/philo.h"

void	*routine_childs(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1 && is_it_end(philo) == FALSE)
	{
		philo->dlk = do_routine(philo, philo->dlk);
		if (philo->dlk->next != NULL)
			philo->dlk = philo->dlk->next;
	}
	return (NULL);
}
