/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:23:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/26 14:54:06 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_split_stack(t_ctl **a_ctl, t_ctl **b_ctl, int size)
{
	int		i;
	int		median;

	if ((*a_ctl)->size == 0)
		return ;
	median = ft_get_medstack(a_ctl, size);
	i = 0;
	while (i < size)
	{
		if ((*a_ctl)->first->index <= median)
		{
			if ((*a_ctl)->first->index == median)
				(*a_ctl)->first->status = 1;
			ft_pb(a_ctl, b_ctl, 1);
			if ((*b_ctl)->first->index == median)
				ft_rb(b_ctl, 1);
		}
		else
			ft_ra(a_ctl, 1);
		i++;
	}
	ft_rrb(b_ctl, 1);
}

void		ft_split_part_b(t_ctl **a_ctl, t_ctl **b_ctl, int size)
{
	int		i;
	int		o;
	int		median;

	if ((*b_ctl)->size == 0)
		return ;
	median = ft_get_medstack(b_ctl, size);
	i = 0;
	o = 0;
	while (i < size)
	{
		if ((*b_ctl)->first->index >= median)
		{
			if ((*b_ctl)->first->index == median)
				(*b_ctl)->first->status = 1;
			ft_pa(b_ctl, a_ctl, 1);
			if ((*a_ctl)->first->index == median)
				ft_ra(a_ctl, 1);
		}
		else
		{
			o++;
			ft_rb(b_ctl, 1);
		}
		i++;
	}
	ft_rra(a_ctl, 1);
	while (o-- > 0)
		ft_rrb(b_ctl, 1);
}

void		ft_split_part_a(t_ctl **a_ctl, t_ctl **b_ctl, int size)
{
	int		i;
	int		o;
	int		median;

	if ((*a_ctl)->size == 0)
		return ;
	median = ft_get_medstack(a_ctl, size);
	i = 0;
	o = 0;
	while (i < size)
	{
		if ((*a_ctl)->first->index <= median)
		{
			if ((*a_ctl)->first->index == median)
				(*a_ctl)->first->status = 1;
			ft_pb(a_ctl, b_ctl, 1);
			if ((*b_ctl)->first->index == median)
				ft_rb(b_ctl, 1);
		}
		else
		{
			o++;
			ft_ra(a_ctl, 1);
		}
		i++;
	}
	ft_rrb(b_ctl, 1);
	while (o-- > 0)
		ft_rra(a_ctl, 1);
}
