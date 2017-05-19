/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:39:13 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/19 19:04:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_get_max_value(t_ctl *ctl)
{
	t_node	*tmp;
	int		value;

	if (ctl->size < 1)
		return (0);
	tmp = ctl->first;
	if (ctl->size == 1)
		return (tmp);
	value = INT_MIN;
	while (tmp)
	{
		if (tmp->index > value && tmp->status != 2)
			value = tmp->index;
		tmp = tmp->next;
	}
	tmp = ctl->first;
	while (tmp && tmp->index != value)
		tmp = tmp->next;
	tmp->status = 2;
	return (tmp);
}

t_node		*ft_get_min_value(t_ctl *ctl)
{
	t_node	*tmp;
	int		value;

	if (ctl->size < 1)
		return (0);
	tmp = ctl->first;
	if (ctl->size == 1)
		return (tmp);
	value = INT_MAX;
	while (tmp)
	{
		if (tmp->index < value && tmp->status != 2)
			value = tmp->index;
		tmp = tmp->next;
	}
	tmp = ctl->first;
	while (tmp && tmp->index != value)
		tmp = tmp->next;
	tmp->status = 2;
	return (tmp);
	}
