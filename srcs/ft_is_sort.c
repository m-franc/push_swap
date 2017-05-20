/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:46:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/20 12:54:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_is_asort(t_ctl **a_ctl)
{
	t_node	*stack;
	size_t	count;

	if ((*a_ctl)->size == 0)
		return (0);
	stack = (*a_ctl)->first;
	if ((*a_ctl)->size == 1)
		return (1);
	if (stack->index != 0)
		return (0);
	stack = stack->next;
	count = 1;
	while (stack)
	{
		if (stack->index != (stack->prev->index + 1))
			return (count);	
		stack = stack->next;
		count++;
	}
	return (count);
}

size_t		ft_is_dsort(t_ctl **a_ctl)
{
	t_node	*stack;
	size_t	count;

	if ((*a_ctl)->size == 0)
		return (0);
	stack = (*a_ctl)->first;
	if (!stack->next)
		return (1);
	if (stack->index != 0)
		return (0);
	stack = stack->next;
	count = 0;
	while (stack)
	{
		if (stack->index != (stack->prev->index - 1))
			return (count);
		stack = stack->next;
		count++;
	}
	return (count);
}
