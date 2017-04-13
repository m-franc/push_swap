/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:09:12 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/13 16:55:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_r(t_ctl **ctl)
{
	t_node	*tmpfirst;
	t_node	*tmplast;

	if ((*ctl)->size < 2)
		return (0);
	tmpfirst = (*ctl)->first;
	tmplast = (*ctl)->last;
	(*ctl)->first->next->prev = NULL;
	(*ctl)->first = (*ctl)->first->next;
	(*ctl)->last->next = tmpfirst;
	(*ctl)->last = (*ctl)->last->next;
	(*ctl)->last->prev = tmplast;
	(*ctl)->last->next = NULL;
	return (1);
}
