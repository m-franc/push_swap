/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:59:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/13 19:53:26 by mfranc           ###   ########.fr       */
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
	return (1);
}
