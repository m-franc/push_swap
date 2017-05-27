/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 22:30:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putnode_single(t_node *node)
{
	if (!node)
		return ;
	while (node)
	{
		ft_printf("data : {green}{italic}%d{eos}{eoc} - dst_top : {cyan}%d{eoc} - dst_bottom : {purple}%d{eoc}\n", node->data, node->dst_top, node->dst_bottom);
		node = node->next;
	}
}
