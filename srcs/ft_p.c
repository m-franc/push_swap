/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:43:52 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/12 12:11:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_p(t_node **src, t_node **dest)
{
	t_node	*tmpsrc;
	t_node	*tmpdest;

	tmpsrc = *src;
	*src = (*src)->next;
	if ((*src)->next)
		(*src)->next->prev = *src;
	(*src)->prev = NULL;
	if (*dest)
	{
		tmpdest = *dest;
		*dest = tmpsrc;
		(*dest)->next = tmpdest;
		(*dest)->next->prev = *dest;
	}
	else
	{
		*dest = tmpsrc;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
	}
	return (1);
}
