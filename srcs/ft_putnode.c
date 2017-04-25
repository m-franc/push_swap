/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/25 12:47:31 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putnode(t_node *a, t_node *b)
{
	ft_printf("|{grey}%s{eoc}|  |{grey}%s{eoc}|\n", "A", "B");
	while (a && b)
	{
		ft_printf("index : {red}%d{eoc} index : |{cyan}%d{eoc}|  |{purple}%d{eoc}|\n", a->index, a->data, b->index, b->data);
		a = a->next;
		b = b->next;
	}
	if (a)
	{	
		while (a)
		{
			ft_printf("index : {red}%d{eoc} |{cyan}%d{eoc}|\n", a->index, a->data);
			a = a->next;
		}
	
	}
	if (b)
	{	
		while (b)
		{
			ft_printf("     index : {red}%d{eoc} |{purple}%d{eoc}|\n",b->index, b->data);
			b = b->next;
		}
	}
	ENDL
}
