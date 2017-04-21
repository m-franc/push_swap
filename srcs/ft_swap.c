/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:19:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/21 18:43:31 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sswap(t_ctl **a, t_ctl **b)
{
	ft_swap(a);
	ft_swap(b);
}

void		ft_swap(t_ctl **ctl)
{
	t_node	*first;
	t_node	*second;

	ft_printf("Taille de la liste : {grey}%d{eoc}\n", (*ctl)->size);
	if ((*ctl)->size == 0 || (*ctl)->size == 1)
		return ;
	first = (*ctl)->first;
	second = (*ctl)->first->next;
	second->prev = NULL;
	first->prev = second;
	first->next = second->next;
	second->next = second;
	(*ctl)->first = second;
	(*ctl)->first->next = first;
	if ((*ctl)->first->next->next)
		(*ctl)->first->next->next->prev = (*ctl)->first->next;
}
