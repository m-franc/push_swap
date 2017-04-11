/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:43:52 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/11 18:43:06 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_p(t_node **src, t_node **dest)
{
	if ((*src)->next)
	{
		*dest = *src;
		(*src)->next->prev = NULL;
		*src = (*src)->next;
	}
	(*dest)->next = *dest;
	*dest = *src;
	(*dest)->prev = NULL;
	return (1);
}
