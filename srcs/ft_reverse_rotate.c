/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:21:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/28 20:00:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_reverse_rotate(t_ctl **ctl)
{
	t_node	*tmplast;
	t_node	*tmpfirst;

	tmplast = (*ctl)->last;
	tmpfirst = (*ctl)->first;
	(*ctl)->last = (*ctl)->last->prev;
	(*ctl)->last->next = NULL;
	(*ctl)->first = tmplast;
	(*ctl)->first->next = tmpfirst;
	(*ctl)->first->next->prev = (*ctl)->first;
}

void		ft_rra(t_ctl **ctl, int ps)
{
	if ((*ctl)->size == 2)
	{
		ft_sa(ctl, ps);
		return ;	
	}
	if ((*ctl)->size < 2)
		return ;
	ft_reverse_rotate(ctl);
	if (ps == 1)
		ft_putendl(RRA);
}

void		ft_rrb(t_ctl **ctl, int ps)
{
	if ((*ctl)->size == 2)
	{
		ft_sb(ctl, ps);
		return ;	
	}
	if ((*ctl)->size < 2)
		return ;
	ft_reverse_rotate(ctl);
	if (ps == 1)
		ft_putendl(RRB);
}

void		ft_rrr(t_ctl **a, t_ctl **b, int ps)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (ps == 1)
		ft_putendl(RRR);
}
