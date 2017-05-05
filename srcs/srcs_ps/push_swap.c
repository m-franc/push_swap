/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/05 18:11:22 by mfranc           ###   ########.fr       */
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
	(void)a_ctl;
	(void)b_ctl;
//	t_node	*max;

//	while (ft_)
//	{
//		max = ft_get_max_value(a_ctl);
//		if (DST_TOP(max) <= DST_BOTTOM(max))
///		{	
//			while (INDEX(FIRST(a_ctl)) != INDEX(max))
//				ft_ra(&a_ctl, 1);	
//			ft_pb(&a_ctl, &b_ctl, 1);
//		}
//		else
//		{
//			while (INDEX(FIRST(a_ctl)) != INDEX(max))
//				ft_rra(&a_ctl, 1);		
//			ft_pb(&a_ctl, &b_ctl, 1);
//		}
//		ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
//	}
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
