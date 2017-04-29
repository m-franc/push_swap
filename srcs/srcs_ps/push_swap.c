/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/29 19:42:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_med_pad(t_ctl *b_ctl)
{
	t_node	*last;
	t_node	*first;
	int		from_last;
	int		from_first;
	int		i;

	from_last = 0;
	from_first = 0;
	i = 0;
	first = FIRST(b_ctl);
	last = LAST(b_ctl);
	while (!MEDIAN(first))
	{
		from_first++;
		first = NEXT(first);
	}
	while (!MEDIAN(last))
	{
		from_last++;
		last = PREV(last);
	}
	if (from_last >= from_first)
		return (1);
	else
		return (2);
}

void		ft_put_med_head(t_ctl *ctl, int b)
{
	int		med_pad;

	med_pad = ft_get_med_pad(ctl);
	while (MEDIAN(FIRST(ctl)) != 1)
	{
		if (med_pad == 1)
		{
			if (b == 1)
				ft_rb(&ctl, 1);
			else
				ft_ra(&ctl, 1);
		}
		else
		{
			if (b == 1)
				ft_rrb(&ctl, 1);
			else
				ft_rra(&ctl, 1);	
		}
	}
}

void		ft_split_stack(t_ctl *a_ctl, t_ctl *b_ctl, int median)
{
	int		i;
	int		o;
	int		size;

	i = 0;
	o = 0;
	size = SIZE(a_ctl);
	while (FIRST(a_ctl) && i < size)
	{
		if (DATA(FIRST(a_ctl)) <= median)
		{
			if (DATA(FIRST(a_ctl)) == median)
				MEDIAN(FIRST(a_ctl)) = 1;
			ft_pb(&a_ctl, &b_ctl, 1);		
		}
		else
			ft_ra(&a_ctl, 1);
		i++;	
	}
	ft_put_med_head(b_ctl, 1);
	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
}

int			ft_sort(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		median;

	median = ft_get_medstack(&a_ctl);
	ft_printf("{red}%d{eoc}\n", median);
	ft_split_stack(a_ctl, b_ctl, median);
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
	if ((ft_sort(a, b)) == -1)
		return (-1);
	return (0);
}
