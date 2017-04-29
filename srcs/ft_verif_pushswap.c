/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_pushswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:14:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/29 12:21:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_verif_pushswap(t_ctl **a_ctl)
{
	t_ctl	*stack;
	size_t	count;

	stack = *a_ctl;
	if (stack->size == 0)
		return (0);
	if (!stack->first->next)
		return (1);
	stack->first = stack->first->next;
	count = 1;
	while (stack->first)
	{
		if (stack->first->data < stack->first->prev->data)
			return (count);
		stack->first = stack->first->next;
		count++;
	}
	return (count);
}
