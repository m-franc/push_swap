/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:32:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/20 15:31:30 by mfranc           ###   ########.fr       */
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
		if (a->status && b->status)
			ft_printf("{green}%-14d%d{eoc}\n", a->data, b->data);
		else if (b->status)
			ft_printf("%-14d{green}%d{eoc}\n", a->data, b->data);
		else if (a->status)
			ft_printf("{green}%-14d{eoc}%d\n", a->data, b->data);
		else
			ft_printf("%-14d%d\n", a->data, b->data);
		a = a->next;
		b = b->next;
	}
	if (a)
	{
		while (a)
		{
			if (a->status)
				ft_printf("{green}%d{eoc}\n", a->data);
			else
				ft_printf("%d\n", a->data);
			a = a->next;
		}
	}
	if (b)
	{
		while (b)
		{
			if (b->status)
				ft_printf("{green}%*d{eoc}\n", (14 + ft_ilen(b->data, 10)), b->data);
			else
				ft_printf("%*d\n", (14 + ft_ilen(b->data, 10)), b->data);
			b = b->next;
		}
	}
	ENDL
}
