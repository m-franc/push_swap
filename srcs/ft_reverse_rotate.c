/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:21:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/22 14:55:35 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_reverse_rotate(t_ctl **ctl)
{
	t_node	*tmplast;
	t_node	*tmpfirst;

	if ((*ctl)->size < 2)
		return ;
	tmplast = (*ctl)->last;
	tmpfirst = (*ctl)->first;
	(*ctl)->last = (*ctl)->last->prev;
	(*ctl)->last->next = NULL;
	(*ctl)->first = tmplast;
	(*ctl)->first->next = tmpfirst;
	(*ctl)->first->next->prev = (*ctl)->first;
}

void		ft_rra(t_ctl **ctl)
{
	ft_reverse_rotate(ctl);
	ft_putendl(RRA);
}

void		ft_rrb(t_ctl **ctl)
{
	ft_reverse_rotate(ctl);
	ft_putendl(RRB);
}

void		ft_rrr(t_ctl **a, t_ctl **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putendl(RRR);
}
