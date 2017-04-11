/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:48:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/11 14:55:28 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_s(t_node **node)
{
	t_node	*first;
	t_node	*second;

	if (!*node)
		return (-1);
	if (!(*node)->next)
		return (0);
	first = (*node);
	second = (*node)->next;
	second->prev = NULL;
	first->prev = second;
	first->next = second->next;
	second->next = second;
	(*node) = second;
	(*node)->next = first;
	(*node)->next->next->prev = (*node)->next;
	return (1);
}
