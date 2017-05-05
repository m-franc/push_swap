/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/05 14:08:45 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putnode(t_node *a, t_node *b)
{
	if (!a && !b)
		return ;
	ft_printf("{grey}A%14c\n{eoc}", 'B');
	while (a && b)
	{
		ft_printf("%-14d%d\n", a->data, b->data);
		a = a->next;
		b = b->next;
	}
	if (a)
	{
		while (a)
		{
			ft_printf("%d\n", a->data);
			a = a->next;
		}
	}
	if (b)
	{
		while (b)
		{
			ft_printf("%*d\n", (14 + ft_ilen(b->data, 10)), b->data);
			b = b->next;
		}
	}
	ENDL
}
