/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/24 17:53:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort(t_ctl *a, t_ctl *b)
{
	t_ctl	*a_cpy;
	int		i;
	int		size_a;
	int		median;

	i = 0;	
	a_cpy = a;
	size_a = SIZE(a);
	if ((median = ft_get_medstack(&a)) == INT_MIN)
		return (-1);
	ft_printf("MEDIAN : {grey}%d{eoc}\n", median);
	while (FIRST(a_cpy) && i < size_a)
	{
		if (DATA(FIRST(a_cpy)) < median)
			ft_pb(&a_cpy, &b);	
		else
			i++;
	}
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
		return (ft_exit_begin(&a, &b));
	if ((ft_parse_arg(&stack_a, &a, av)) == -1)
		return (-1);
	if ((ft_sort(a, b)) == -1)
		return (-1);
	ft_putnode(a->first, b->first);
	return (0);
}
