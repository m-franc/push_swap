/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/18 16:41:01 by mfranc           ###   ########.fr       */
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

int			ft_check_duplicate(t_node *duplicate, char *ints)
{
	while (duplicate)
	{
		if (ft_atoi(ints) == duplicate->data)
			return (-1);
		duplicate = duplicate->next;
	}
	return (0);
}

int			ft_fill_node(t_node **node, t_ctl **a_ctl, char **ints)
{
	int		i;
	t_node	*tmp;
	t_node	*prev;
	t_node	*duplicate;

	if (!*node)
	{
		i = 0;
		if (!(*node = ft_new_node(ints[i++], NULL)))
			return (-1);
	}
	else
		i = 2;
	(*a_ctl)->first = *node;
	(*a_ctl)->size++;
	tmp = *node;
	duplicate = *node;
	while (ints[i])
	{
		prev = tmp;
		if ((ft_check_duplicate(duplicate, ints[i])) == -1)
			return (-1);
		duplicate = *node;
		if (!(tmp->next = ft_new_node(ints[i++], prev)))
			return (-1);
		tmp = tmp->next;
		(*a_ctl)->size++;
		(*a_ctl)->last = tmp;
	}
	return (1);
}
