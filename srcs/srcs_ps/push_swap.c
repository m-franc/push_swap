/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/09 18:20:42 by mfranc           ###   ########.fr       */
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

int			ft_get_best_hit(int *index_a, t_ctl *a_ctl, t_ctl *b_ctl)
{
	t_node	*a;
	t_node	*b;
	int		hit;
	int		pad_a;
	int		pad_b;

	hit = INT_MAX;
	a = FIRST(a_ctl);
	while (a)
	{
		pad_a = DST_TOP(a) >= DST_BOTTOM(a) ? DST_BOTTOM(a) : DST_TOP(a);
		b = FIRST(b_ctl);
		while (b && NEXT(b) && INDEX(a) < INDEX(b))
			b = NEXT(b);
		pad_b = DST_TOP(b) >= DST_BOTTOM(b) ? DST_BOTTOM(b) : DST_TOP(b);
		if ((pad_a + pad_b) < hit)
			*index_a = pad_a;
		a = NEXT(a);
	}
	return (pad_b);
}

int			ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	size_t	hit;
	int		index_a;

	ft_pb(&a_ctl, &b_ctl, 1);
	ft_pb(&a_ctl, &b_ctl, 1);
	index_a = 0;
	while (SIZE(a_ctl) != 0)
	{
		hit = ft_get_best_hit(&index_a, a_ctl, b_ctl);
		if (index_a > (int)(SIZE(a_ctl) / 2))
		{
			while (index_a-- > 0)
				ft_rra(&a_ctl, 1);
			ft_pb(&a_ctl, &b_ctl, 1);
			if (hit > (SIZE(a_ctl) / 2))
				while (hit-- > 0)
					ft_rb(&b_ctl, 1);
			else
				while (hit-- > 0)
					ft_rrb(&b_ctl, 1);	
		}
		else
		{
			while (index_a-- > 0)
				ft_ra(&a_ctl, 1);
			ft_pb(&a_ctl, &b_ctl, 1);
			if (hit > (SIZE(a_ctl) / 2))
				while (hit-- > 0)
					ft_rb(&b_ctl, 1);
			else
				while (hit-- > 0)
					ft_rrb(&b_ctl, 1);	
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
