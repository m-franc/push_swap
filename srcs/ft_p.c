/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:43:52 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/11 20:30:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_p(t_node **src, t_node **dest)
{
	if (*dest)	
	{
		(*dest)->next = *dest;
		*dest = *src;
		(*dest)->next->prev = *dest;
	}
	else
	{
		*dest = *src;
		(*dest)->next = NULL;
	}
	(*dest)->prev = NULL;
	(*src)->next->prev = *src;
	*src = (*src)->next;
	(*src)->prev = NULL;
	return (1);
}
