/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_medstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:58:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/01 11:45:49 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_medstack(t_ctl **ctl)
{
	int		index_max;
	int		median_index;
	t_node	*node;
	
	node = FIRST((*ctl));
	index_max = node->index;
	while (node)
	{
		if (node->index > index_max)
			index_max = node->index;
		node = node->next;
	}
	median_index = index_max / 2;
	return (median_index);
}
