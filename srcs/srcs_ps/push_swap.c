/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/01 11:44:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_med_pad(t_ctl *b_ctl)
{
	t_node	*last;
	t_node	*first;
	int		from_last;
	int		from_first;

	from_last = 0;
	from_first = 0;
	first = FIRST(b_ctl);
	last = LAST(b_ctl);
	while (STATUS(first) != 1 && first)
	{
		from_first++;
		first = NEXT(first);
	}
	while (STATUS(last) != 1 && last)
	{
		from_last++;
		last = PREV(last);
	}
	if (from_last >= from_first)
		return (1);
	else
		return (2);
}

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
		if (DATA(FIRST(a_ctl)) <= median)
		{
			if (DATA(FIRST(a_ctl)) == median)
				STATUS(FIRST(a_ctl)) = 1;
			ft_pb(&a_ctl, &b_ctl, 1);
			if (DATA(FIRST(a_ctl)) == median)
				ft_rb(&b_ctl, 1);
		}
		else
			ft_ra(&a_ctl, 1);
		i++;	
	}
	ft_rrb(&b_ctl, 1);
	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
}

int			ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	ft_split_stack(a_ctl, b_ctl);
//	ft_quick_sort_b(b_ctl);
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
