/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/28 21:38:49 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_quick_sort_a(t_ctl *a)
{
	int		median;
	size_t	i;

	i = 0;
	median = ft_get_medstack(&a);
	while (i < SIZE(a))
	{
		if (DATA(FIRST(a)) < median)
			ft_sa(&a, 1);
		else
			ft_ra(&a, 1);
		i++;
	}
}

void		ft_quick_sort_b(t_ctl *b)
{
	int		median;
	size_t	i;

	i = 0;
	median = ft_get_medstack(&b);
	while (i < SIZE(b))
	{
		if (DATA(FIRST(b)) < median)
			ft_sb(&b, 1);	
		else
			ft_rb(&b, 1);
		i++;
	}
}

int			ft_sort(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		i;
	int		size;
	int		median;

	i = 0;
	size = SIZE(a_ctl);
	median = ft_get_medstack(&a_ctl);
	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
/*	while (FIRST(a_ctl) && i < size)
	{
		if (DATA(FIRST(a_ctl)) < median)
			ft_pb(&a_ctl, &b_ctl, 1);	
		else
			ft_ra(&a_ctl, 1);
		i++;	
	}*/
//	while (ft_verif_pushswap(&a_ctl) != SIZE(a_ctl))
//		ft_quick_sort_a(a_ctl);
//	while (ft_verif_pushswap(&b_ctl) != SIZE(b_ctl))
//		ft_quick_sort_b(b_ctl);
//	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
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
