/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:41 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/28 19:38:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rotate(t_ctl **ctl)
{
	t_node	*tmpfirst;
	t_node	*tmplast;

	tmpfirst = (*ctl)->first;
	tmplast = (*ctl)->last;
	(*ctl)->first->next->prev = NULL;
	(*ctl)->first = (*ctl)->first->next;
	(*ctl)->last->next = tmpfirst;
	(*ctl)->last = (*ctl)->last->next;
	(*ctl)->last->prev = tmplast;
	(*ctl)->last->next = NULL;
}

void		ft_ra(t_ctl **ctl, int ps)
{
	if (SIZE((*ctl)) == 2)
	{
		ft_sa(ctl, ps);
		return ;	
	}
	if (SIZE((*ctl)) < 2)
		return ;
	ft_rotate(ctl);
	if (ps == 1)
		ft_putendl(RA);
}

void		ft_rb(t_ctl **ctl, int ps)
{
	if (SIZE((*ctl)) == 2)
	{
		ft_sb(ctl, ps);
		return ;	
	}
	if (SIZE((*ctl)) < 2)
		return ;
	ft_rotate(ctl);
	if (ps == 1)
		ft_putendl(RB);
}

void		ft_rr(t_ctl **a, t_ctl **b, int ps)
{
	if (SIZE((*a)) == 2)
		ft_sa(a, 0);
	else
		ft_ra(a, 0);
	if (SIZE((*b)) == 2)
		ft_sb(b, 0);
	else
		ft_rb(b, 0);
	if (ps == 1)
		ft_putendl(RR);
}
