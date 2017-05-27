/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:46:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 17:35:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_asort(t_ctl **a_ctl)
{
	t_node	*stack;
	int		count;

	if ((*a_ctl)->size == 0)
		return (0);
	if ((*a_ctl)->size == 1)
		return (1);
	stack = (*a_ctl)->first->next;
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

int			ft_is_dsort(t_ctl **a_ctl)
{
	t_node	*stack;
	int		count;

	if ((*a_ctl)->size == 0)
		return (0);
	stack = (*a_ctl)->first;
	if (!stack->next)
		return (1);
	stack = stack->next;
	count = 1;
	while (stack)
	{
		if (stack->index != (stack->prev->index - 1))
			return (count);
		stack = stack->next;
		count++;
	}
	return (count);
}
