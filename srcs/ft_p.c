/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:43:52 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/13 16:59:35 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_p(t_ctl **src_ctl, t_ctl **dest_ctl)
{
	t_node	*tmpsrc;
	t_node	*tmpdest;

	if ((*src_ctl)->size == 0)
		return (0);
	tmpsrc = (*src_ctl)->first;
	(*src_ctl)->first = (*src_ctl)->first->next;
	(*src_ctl)->size--;
	if ((*src_ctl)->size > 1)
	{
		(*src_ctl)->first->next->prev = (*src_ctl)->first;
		(*src_ctl)->first->prev = NULL;
	}
	(*dest_ctl)->size++;
	if ((*dest_ctl)->first)
	{
		tmpdest = (*dest_ctl)->first;
		(*dest_ctl)->first = tmpsrc;
		(*dest_ctl)->first->next = tmpdest;
		(*dest_ctl)->first->next->prev = (*dest_ctl)->first;
		return (1);
	}
	(*dest_ctl)->first = tmpsrc;
	(*dest_ctl)->last = (*dest_ctl)->first;
	(*dest_ctl)->first->next = NULL;
	(*dest_ctl)->first->prev = NULL;
	return (1);
}
