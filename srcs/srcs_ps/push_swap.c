/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/28 20:02:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_store_min_value(t_ctl **a_ctl, t_ctl **b_ctl)
{
	t_node	*min;
	int		min_dst;

	min = ft_get_min_value(*a_ctl);
	if (min->dst_bottom > min->dst_top)
	{
		min_dst = min->dst_top;
		while (min_dst-- > 0)
			ft_ra(a_ctl, 1);
		ft_pb(a_ctl, b_ctl, 1);
	}
	else
	{
		min_dst = min->dst_bottom;
		while (min_dst-- > 0)
			ft_rra(a_ctl, 1);
		ft_pb(a_ctl, b_ctl, 1);
	}
}

void		ft_little_sort(t_ctl **a_ctl, t_ctl **b_ctl, int size_a)
{
	int		i;

	if (size_a > 1 && size_a < 4)
	{
		if ((*a_ctl)->first->index == (size_a - 1))
			ft_ra(a_ctl, 1);
		else if ((*a_ctl)->last->index != (size_a - 1))
			ft_rra(a_ctl, 1);
		if (ft_is_asort(a_ctl) < 2)
			ft_sa(a_ctl, 1);
	}
	else
	{
		i = -1;
		while (ft_is_asort(a_ctl) != size_a)
		{
			while (++i <= (size_a / 2))
				ft_store_min_value(a_ctl, b_ctl);
			if (ft_is_asort(a_ctl) < 2)
				ft_sa(a_ctl, 1);
			while (i-- > 0)
				ft_pa(b_ctl, a_ctl, 1);
		}
	}
}

void		ft_quick_sort(t_ctl *a_ctl, t_ctl *b_ctl, int stack_part_b)
{
	if (stack_part_b > ft_is_dsort(&b_ctl))
	{
		ft_split_part_b(&a_ctl, &b_ctl, stack_part_b);
		if ((ft_get_stack_part_a(a_ctl)) > 2)
		{
			while ((ft_get_stack_part_a(a_ctl)) > 2)
			{
				if (ft_get_stack_part_a(a_ctl) > ft_is_asort(&a_ctl))
					ft_split_part_a(&a_ctl, &b_ctl, ft_get_stack_part_a(a_ctl));
				else
					break ;
			}
			if (ft_is_asort(&a_ctl) < 2)
				ft_sa(&a_ctl, 1);
		}
		else
		{
			if (ft_is_asort(&a_ctl) < 2)
				ft_sa(&b_ctl, 1);
		}
	}
	else
		while (stack_part_b-- > 0)
			ft_pa(&b_ctl, &a_ctl, 1);
}

void		ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		stack_part_b;
	int		size_a;

	size_a = a_ctl->size;
	if (size_a <= 5)
		ft_little_sort(&a_ctl, &b_ctl, size_a);
	else
	{
		while (a_ctl->size != 1)
			ft_split_stack(&a_ctl, &b_ctl, a_ctl->size);
		while (ft_is_asort(&a_ctl) != size_a)
		{
			if (b_ctl->first->status == 1 || b_ctl->size == 1)
				ft_pa(&b_ctl, &a_ctl, 1);
			else if ((stack_part_b = ft_get_stack_part_b(b_ctl)) > 2)
				ft_quick_sort(a_ctl, b_ctl, stack_part_b);
			else
			{
				if (ft_is_dsort(&b_ctl) < 2)
					ft_sb(&b_ctl, 1);
				ft_pa(&b_ctl, &a_ctl, 1);
				ft_pa(&b_ctl, &a_ctl, 1);
			}
		}
	}
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
	if (a->size == 1 || ft_is_asort(&a) == a->size)
		return (0);
	else
		ft_push_swap(a, b);
	return (0);
}
