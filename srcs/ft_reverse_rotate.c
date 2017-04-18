/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:21:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 16:22:28 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rreverse_rotate(t_ctl **a, t_ctl **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}

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
