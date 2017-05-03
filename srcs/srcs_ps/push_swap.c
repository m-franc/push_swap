/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/03 18:00:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_split_stack(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		i;
	int		size;
	int		median;

	median = ft_get_medstack(&a_ctl);
	size = SIZE(a_ctl);
	i = 0;
	while (i < size)
	{
		if (INDEX(FIRST(a_ctl)) <= median)
		{
			if (INDEX(FIRST(a_ctl)) == median)
				STATUS(FIRST(a_ctl)) = 1;
			ft_pb(&a_ctl, &b_ctl, 1);
			if (INDEX(FIRST(b_ctl)) == median)
				ft_rb(&b_ctl, 1);
		}
		else
			ft_ra(&a_ctl, 1);
		i++;	
	}
	ft_rrb(&b_ctl, 1);
}

int			ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		median;
	int		padding;
	int		pdg_cpy;
	t_node	*max;

	ft_split_stack(a_ctl, b_ctl);
	median = ft_get_medstack(&b_ctl);
	while (ft_is_asort(&a_ctl) != SIZE(a_ctl))
	{
		max = ft_get_max_value(a_ctl);
		if (DST_BOTTOM(max) >= DST_TOP(max))
		{	
			padding = DST_TOP(max);
			pdg_cpy = padding;
			while (padding-- > 0)
				ft_ra(&a_ctl, 1);	
			STATUS(FIRST(a_ctl)) = 2;
			ft_update_dst_after_r(a_ctl, pdg_cpy);
		}
		else
		{
			padding = DST_BOTTOM(max);
			pdg_cpy = padding;
			while (padding-- > 0)
				ft_rra(&a_ctl, 1);		
			STATUS(FIRST(a_ctl)) = 2;
			ft_update_dst_after_rr(a_ctl, pdg_cpy);
		}
		ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*b;

	stack_a = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (ft_exit_ps(&a, &b));
	if ((ft_fill_node(&stack_a, &a, av)) == -1)
		return (ft_exit_ps(&a, &b));
	if ((ft_push_swap(a, b)) == -1)
		return (-1);
	return (0);
}
