/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:39:13 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/04 19:05:12 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_get_max_value(t_ctl *ctl)
{
	t_node	*tmp;
	int		value;

	if (SIZE(ctl) < 1)
		return (0);
	tmp = FIRST(ctl);
	if (SIZE(ctl) == 1)
		return (tmp);
	value = -1;
	tmp = NEXT(tmp);
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
	tmp = FIRST(ctl);
	if (SIZE(ctl) == 1)
		return (tmp);
	value = (SIZE(ctl) + 1);
	tmp = NEXT(tmp);
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
