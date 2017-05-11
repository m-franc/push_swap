/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/11 19:17:33 by mfranc           ###   ########.fr       */
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

t_move		ft_get_best_hit(t_ctl *a_ctl, t_ctl *b_ctl)
{
	t_node	*a;
	t_node	*b;
	t_move	move;
	int		hit;

	hit = INT_MIN;
	a = FIRST(a_ctl);
	move.pad_a = 0;
	move.pad_b = 0;
	move.ra = 0;
	move.rb = 0;
	while (a)
	{
		move.ra = DST_TOP(a) >= DST_BOTTOM(a) ? 1 : 0;
		move.pad_a = DST_TOP(a) >= DST_BOTTOM(a) ? DST_BOTTOM(a) : DST_TOP(a);
		b = FIRST(b_ctl);
		while (b && NEXT(b) && INDEX(a) > INDEX(b))
			b = NEXT(b);
		move.rb = DST_TOP(a) >= DST_BOTTOM(a) ? 1 : 0;
		move.pad_b = DST_TOP(b) >= DST_BOTTOM(b) ? DST_BOTTOM(b) : DST_TOP(b);
		if ((move.pad_a + move.pad_b) < hit)
			hit = move.pad_a + move.pad_b;
		a = NEXT(a);
	}
	return (move);
}

int			ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	t_move	move;

	ft_pb(&a_ctl, &b_ctl, 1);
	ft_pb(&a_ctl, &b_ctl, 1);
	while (SIZE(a_ctl) != 0)
	{
		move = ft_get_best_hit(a_ctl, b_ctl);
		if (move.ra == 0)
		{
			if (move.rb == 1)
				while (move.pad_b-- > 0)
					ft_rb(&b_ctl, 1);
			else
				while (move.pad_b-- > 0)
					ft_rrb(&b_ctl, 1);	
			while (move.pad_a-- > 0)
				ft_rra(&a_ctl, 1);
			ft_pb(&a_ctl, &b_ctl, 1);
		}
		else
		{
			if (move.rb == 1)
				while (move.pad_b-- > 0)
					ft_rb(&b_ctl, 1);
			else
				while (move.pad_b-- > 0)
					ft_rrb(&b_ctl, 1);	
			while (move.pad_a-- > 0)
				ft_ra(&a_ctl, 1);
			ft_pb(&a_ctl, &b_ctl, 1);
		}
	}
	while (SIZE(b_ctl) != 0)
		ft_pa(&b_ctl, &a_ctl, 1);
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
