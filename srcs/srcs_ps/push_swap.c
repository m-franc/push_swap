/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/22 15:19:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*a_cpy;
	t_ctl	*b;
//	t_ctl	*b_cpy;
	size_t	size_a;

	stack_a = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (ft_exit_begin(&a, &b));
	ft_putendl("--------------");
	if ((ft_parse_arg(&stack_a, &a, av)) == -1)
		return (-1);
	size_a = SIZE(a);
	while (ft_verif_pushswap(&a) != size_a)
	{
		a_cpy = a;
		while (FIRST(a_cpy))
		{
			if (DATA(FIRST(a_cpy)) < DATA(LAST(a_cpy)))
				ft_pb(&a_cpy, &b);
			FIRST(a_cpy) = NEXT(a_cpy);
		}
	}
	return (0);
}
