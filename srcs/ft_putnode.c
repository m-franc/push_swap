/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/21 16:33:36 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putnode(t_node *a, t_node *b)
{
	ft_printf("|{grey}%s{eoc}|  |{grey}%s{eoc}|\n", "A", "B");
	while (a && b)
	{
		ft_printf("|{cyan}%d{eoc}|  |{purple}%d{eoc}|\n", a->data, b->data);
		a = a->next;
		b = b->next;
	}
	if (a)
	{	
		while (a)
		{
			ft_printf("|{cyan}%d{eoc}|\n", a->data);
			a = a->next;
		}
	
	}
	if (b)
	{	
		while (b)
		{
			ft_printf("     |{purple}%d{eoc}|\n", b->data);
			b = b->next;
		}
	}
	ENDL
}
