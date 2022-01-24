/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:23:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/24 11:30:18 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	errors(char **av)
{
	if (not_integer(av) == TRUE)
		return (TRUE);
	else if (is_empty(av) == TRUE)
		return (TRUE);
	else if (greater_than_integer(av) == TRUE)
		return (TRUE);
	return (FALSE);
}
