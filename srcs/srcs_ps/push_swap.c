/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/27 21:46:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		i;
	int		size;
	int		median;

	i = 0;
	size = SIZE(a_ctl);
	median = ft_get_medstack(&a_ctl);
	while (FIRST(a_ctl) && i < size)
	{
		if (DATA(FIRST(a_ctl)) < median)
			ft_pb(&a_ctl, &b_ctl, 0);	
		else
			ft_ra(&a_ctl, 0);
		i++;	
	}
	ft_putnode(FIRST(a_ctl), FIRST(b_ctl));
	return (1);
}

int	main(int ac, char **av)
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
