/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 23:30:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_quick_sort(t_ctl *a_ctl, t_ctl *b_ctl, int stack_part_b)
{
	int		stack_part_a;

	if (stack_part_b > ft_is_dsort(&b_ctl))
	{
		ft_split_part_b(&a_ctl, &b_ctl, stack_part_b);
		if ((stack_part_a = ft_get_stack_part_a(a_ctl)) > 2)
		{
			while ((stack_part_a = ft_get_stack_part_a(a_ctl)) > 2)
			{
				if (stack_part_a > ft_is_asort(&a_ctl))
					ft_split_part_a(&a_ctl, &b_ctl, stack_part_a);
				else
					break ;
			}
			if (ft_is_asort(&a_ctl) < 2)
				ft_sa(&a_ctl, 1);
		}
		else
			if (ft_is_asort(&a_ctl) < 2)
				ft_sa(&b_ctl, 1);
	}
	else
		while (stack_part_b-- > 0)
			ft_pa(&b_ctl, &a_ctl, 1);
}

void		ft_little_sort(t_ctl **a_ctl, t_ctl **b_ctl, int size_a)
{
	t_node	*max;
	int		max_dst;
	int		i;
	int		o;

	i = 0;
	while (ft_is_asort(a_ctl) != size_a)
	{
		max = ft_get_max_value(*a_ctl);
		if (max->dst_bottom > max->dst_top)
		{
			max_dst = max->dst_top;
			if (i < 0)
			{
				o = i;
				while (o-- > 0)
				{
					ft_rra(a_ctl, 1);
					ft_pb(a_ctl, b_ctl, 1);
				}
			}
			if (max_dst == 0)	
				ft_ra(a_ctl, 1);	
			else
			{	
				while (max_dst-- > 0)
					ft_rra(a_ctl, 1);
			}
			if (i < 0)
			{
				o = i;
				while (o-- > 0)
				{
					ft_pa(b_ctl, a_ctl, 1);	
					ft_ra(a_ctl, 1);
				}
			}
		}
		else
		{
			if (i < 0)
			{
				o = i;
				while (o-- > 0)
				{
					ft_rra(a_ctl, 1);
					ft_pb(a_ctl, b_ctl, 1);	
				}
			}
			max_dst = max->dst_bottom;
			while (max_dst-- > 1)
				ft_ra(a_ctl, 1);
			max_dst = max->dst_bottom;
			if (i < 0)
				while (max_dst-- > 1)
					ft_rra(a_ctl, 1);
			if (i < 0)
			{
				o = i;
				while (o-- > 0)
				{
					ft_pa(b_ctl, a_ctl, 1);	
					ft_ra(a_ctl, 1);	
				}
			}
		}
		if (ft_is_asort(a_ctl) < 2)
			ft_sa(a_ctl, 1);
		ft_putnode_single((*a_ctl)->first);
		i++;
	}
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
	ft_push_swap(a, b);
	return (0);
}
