/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 18:52:43 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putnode_single(t_node *node)
{
	if (!node)
		return ;
	ft_printf("data : {grey}%d{eoc} - data->prev : {cyan}NULL{eoc}\n",
			node->data);
	if (node->next)
		node = node->next;
	else
		return ;
	while (node)
	{
		ft_printf("data : {grey}%d{eoc} - data->prev : {cyan}%d{eoc}\n",
				node->data, node->prev->data);
		node = node->next;
	}
}
