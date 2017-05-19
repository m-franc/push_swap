/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_medstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:58:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/19 12:17:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_medstack(t_ctl **ctl)
{
	int		index_max;
	int		index_min;
	int		median_index;
	t_node	*node;
	
	if (!*ctl)
		return (0);
	node = FIRST((*ctl));
	index_max = INDEX(node);
	index_min = INDEX(node);
	while (node)
	{
		if (INDEX(node) > index_max)
			index_max = INDEX(node);
		if (INDEX(node) < index_min)
			index_min = INDEX(node);
		node = NEXT(node);
	}
	node = FIRST((*ctl));
	median_index = (index_max + index_min) / 2;
	return (median_index);
}
