/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:39:13 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/04 12:46:28 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_max_value(t_node **max, t_ctl *ctl)
{
	int		value;

	if (SIZE(ctl) < 1)
		return (0);
	else if (SIZE(ctl) == 1)
		return (INDEX(FIRST(ctl)));
	*max = FIRST(ctl);
	value = INT_MIN;
	while (*max)
	{
		if (INDEX((*max)) > value && STATUS((*max)) != 2)
			value = INDEX((*max));
		*max = NEXT((*max));
	}
	*max = FIRST(ctl);
	while (*max && INDEX((*max)) != value)
		*max = NEXT((*max));
	return (value);
}

int			ft_get_min_value(t_node **max, t_ctl *ctl)
{
	int		value;

	if (SIZE(ctl) < 1)
		return (0);
	else if (SIZE(ctl) == 1)
		return (INDEX(FIRST(ctl)));
	*max = FIRST(ctl);
	value = INT_MAX;
	while (*max)
	{
		if (INDEX((*max)) < value && STATUS((*max)) != 2)
			value = INDEX((*max));
		*max = NEXT((*max));
	}
	*max = FIRST(ctl);
	while (*max && INDEX((*max)) != value)
		*max = NEXT((*max));
	return (value);
}
