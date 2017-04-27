/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:19:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/27 17:03:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(t_ctl **ctl)
{
	t_node	*first;
	t_node	*second;

	if (!*ctl)
		return ;

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

void		ft_sa(t_ctl **ctl, int ps)
{
	ft_swap(ctl);
	if (ps == 1)
		ft_putendl(SA);
}

void		ft_sb(t_ctl **ctl, int ps)
{
	ft_swap(ctl);
	if (ps == 1)
		ft_putendl(SB);
}

void		ft_ss(t_ctl **a, t_ctl **b, int ps)
{
	ft_swap(a);
	ft_swap(b);
	if (ps == 1)
		ft_putendl(SS);
}
