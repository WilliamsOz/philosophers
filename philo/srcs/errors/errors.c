/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:23:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/10 14:28:31 by wiozsert         ###   ########.fr       */
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
