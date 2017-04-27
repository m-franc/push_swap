/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_medstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:58:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/27 19:09:58 by mfranc           ###   ########.fr       */
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
	node = FIRST((*ctl));
	median_index = index_max / 2;
	while (node && node->index != median_index)
		node = node->next;
	return (node->data);
}
