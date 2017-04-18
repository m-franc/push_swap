/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/18 12:36:10 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_new_node(char *integer, t_node *prev)
{
	t_node	*node;
	int		num;

	if (ft_ilen(ft_atoi(integer), 10) != (int)ft_strlen(integer))
		return (NULL);
	num = ft_atoi(integer);
	if (num == 0 && integer[0] != '0')
		return (NULL);
	if (num > INT_MAX || num < INT_MIN)
		return (NULL);
	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->data = num;
	node->next = NULL;
	node->prev = prev;
	return (node);
}

int			ft_fill_node(t_node **node, t_ctl **a_ctl, char **ints)
{
	int		i;
	t_node	*tmp;
	t_node	*prev;
	t_node	*repeat;

	i = 1;
	if (!(*node = ft_new_node(ints[i++], NULL)))
		return (-1);
	(*a_ctl)->first = *node;
	(*a_ctl)->size++;
	tmp = *node;
	repeat = *node;
	while (ints[i])
	{
		prev = tmp;
		while (repeat)
		{
			if (ft_atoi(*ints + i) == repeat->data)
				return (-1);
			repeat = repeat->next;
		}
		repeat = *node;
		if (!(tmp->next = ft_new_node(ints[i++], prev)))
			return (-1);
		tmp = tmp->next;
		(*a_ctl)->size++;
		(*a_ctl)->last = tmp;
	}
	return (1);
}
