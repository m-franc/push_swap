/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:48:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/12 20:33:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_s(t_ctl **a_ctl)
{
	t_node	*first;
	t_node	*second;

	if ((*a_ctl)->size == 0)
		return (-1);
	if ((*a_ctl)->size == 1)
		return (0);
	first = (*a_ctl)->first;
	second = (*a_ctl)->first->next;
	second->prev = NULL;
	first->prev = second;
	first->next = second->next;
	second->next = second;
	(*a_ctl)->first = second;
	(*a_ctl)->first->next = first;
	(*a_ctl)->first->next->next->prev = (*a_ctl)->first->next;
	return (1);
}
