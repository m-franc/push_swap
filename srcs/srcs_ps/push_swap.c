/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/18 19:45:01 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*b;

	stack_a = NULL;
	a = NULL;
	b = NULL;
//	ft_printf("pb\npb\npb\npb\npb\npb\n");
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (-1);
	if ((ft_fill_node(&stack_a, &a, av)) == -1)
		return (ft_exit_pushswap(&a, &b, NULL));
	return (0);
}
