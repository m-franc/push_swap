/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/22 18:59:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*a_cpy;
	t_ctl	*b;
	int		size_a;
	int		*a_sort;
	int		median;
//	t_ctl	*b_cpy;

	stack_a = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (ft_exit_begin(&a, &b));
	if ((ft_parse_arg(&stack_a, &a, av)) == -1)
		return (-1);
	size_a = SIZE(a);
	a_cpy = a;
	if (!(a_sort = ft_list_to_inttab(&a_cpy)))
		return (-1);
	ft_sort_int_tab(a_sort, size_a);
	median = ft_get_median(a_sort, size_a);
	free(a_sort);
	ft_printf("MEDIAN : {purple}%d{eoc}\n", median);
//	size_a = SIZE(a);
	//	while (ft_verif_pushswap(&a) != size_a)
	//	{
//	i = 0;
	while (FIRST(a_cpy))
	{
		if (DATA(FIRST(a_cpy)) < median)
			ft_pb(&a_cpy, &b);
		FIRST(a_cpy) = NEXT(a_cpy);
	}
	ft_putnode(a->first, b->first);
	return (0);
}
