/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:46:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/01 17:23:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_is_asort(t_ctl **a_ctl)
{
	t_node	*stack;
	size_t	count;

	if (SIZE((*a_ctl)) == 0)
		return (0);
	stack = FIRST((*a_ctl));
	if (!NEXT(stack))
		return (1);
	stack = NEXT(stack);
	count = 1;
	while (stack)
	{
		if (INDEX(stack) < INDEX(PREV(stack)))
			return (count);
		stack = NEXT(stack);
		count++;
	}
	return (count);
}

size_t		ft_is_dsort(t_ctl **a_ctl)
{
	t_node	*stack;
	size_t	count;

	if (SIZE((*a_ctl)) == 0)
		return (0);
	stack = FIRST((*a_ctl));
	if (!NEXT(stack))
		return (1);
	stack = NEXT(stack);
	count = 1;
	while (stack)
	{
		if (INDEX(stack) > INDEX(PREV(stack)))
			return (count);
		stack = NEXT(stack);
		count++;
	}
	return (count);
}
