/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:51:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 13:51:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_stack_part_b(t_ctl *ctl)
{
	int		stack_part;
	t_node	*stack;

	stack = ctl->first;
	stack_part = 0;
	while (stack && stack->status != 1)
	{
		stack_part++;
		stack = stack->next;
	}
	return (stack_part);
}

int			ft_get_stack_part_a(t_ctl *ctl)
{
	int		stack_part;
	t_node	*stack;

	stack = ctl->first;
	stack_part = 1;
	stack = stack->next;
	while (stack && stack->status != 1)
	{
		stack_part++;
		stack = stack->next;
	}
	return (stack_part);
}
