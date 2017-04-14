/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_pushswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:14:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 19:08:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_verif_pushswap(t_ctl **ctl)
{
	t_ctl	*stack;
	size_t	count;

	stack = *ctl;
	stack->first = stack->first->next;
	count = 1;
	while (stack)
	{
		if (stack->first->data < stack->first->prev->data)
			return (count);
		stack->first = stack->first->next;
		count++;
	}
	return (count);
}
