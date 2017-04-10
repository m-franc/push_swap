/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/10 19:33:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putnode(t_node *node)
{
	ft_printf("data : {grey}%d{eoc} - data->prev : {cyan}NULL{eoc}\n",
			node->data);
	node = node->next;
	while (node)
	{
		ft_printf("data : {grey}%d{eoc} - data->prev : {cyan}%d{eoc}\n",
				node->data, node->prev->data);
		node = node->next;
	}
}
