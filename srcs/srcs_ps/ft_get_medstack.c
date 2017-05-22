/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_medstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:58:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/20 18:48:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_medstack(t_ctl **ctl, int part)
{
	int		index_max;
	int		index_min;
	int		median_index;
	t_node	*node;
	
	if (!*ctl)
		return (0);
	node = (*ctl)->first;
	index_max = node->index;
	index_min = node->index;
	while (node && part-- > 0)
	{
		if (node->index > index_max)
			index_max = node->index;
		if (node->index < index_min)
			index_min = node->index;
		node = node->next;
	}
	node = (*ctl)->first;
	median_index = (index_max + index_min) / 2;
	return (median_index);
}
