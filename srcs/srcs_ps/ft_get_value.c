/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:39:13 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/03 17:58:59 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_get_max_value(t_ctl *ctl)
{
	t_node	*tmp;
	int		value;

	if (SIZE(ctl) < 1)
		return (0);
	else if (SIZE(ctl) == 1)
		return (FIRST(ctl));
	tmp = FIRST(ctl);
	value = INT_MIN;
	while (tmp)
	{
		if (INDEX(tmp) > value && STATUS(tmp) != 2)
			value = INDEX(tmp);
		tmp = NEXT(tmp);
	}
	tmp = FIRST(ctl);
	while (tmp && INDEX(tmp) != value)
		tmp = NEXT(tmp);
	return (tmp);
}

t_node		*ft_get_min_value(t_ctl *ctl)
{
	t_node	*tmp;
	int		value;

	if (SIZE(ctl) < 1)
		return (0);
	else if (SIZE(ctl) == 1)
		return (FIRST(ctl));
	tmp = FIRST(ctl);
	value = INT_MAX;
	while (tmp)
	{
		if (INDEX(tmp) < value && STATUS(tmp) != 2)
			value = INDEX(tmp);
		tmp = NEXT(tmp);
	}
	tmp = FIRST(ctl);
	while (tmp && INDEX(tmp) != value)
		tmp = NEXT(tmp);
	return (tmp);
}
