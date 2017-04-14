/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:59:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 12:14:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rr(t_ctl **ctl)
{
	t_node	*tmplast;
	t_node	*tmpfirst;

	if ((*ctl)->size < 2)
		return (0);
	tmplast = (*ctl)->last;
	tmpfirst = (*ctl)->first;
	(*ctl)->last = (*ctl)->last->prev;
	(*ctl)->last->next = NULL;
	(*ctl)->first = tmplast;
	(*ctl)->first->next = tmpfirst;
	(*ctl)->first->next->prev = (*ctl)->first;
	return (1);
}
