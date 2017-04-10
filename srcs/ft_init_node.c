/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/10 19:49:36 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_new_node(char *integer, int *pi, t_node *prev)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->data = ft_atoi(integer);
	if (node->data > INT_MAX || node->data < INT_MIN)
		return (NULL);
	*pi += ft_ilen(node->data, 10);
	node->next = NULL;
	node->prev = prev;
	return (node);
}

int			ft_fill_first(t_node **node, char *ints, int *pi)
{	
	while (ints[*pi] && ft_isdigit(ints[*pi]) == ' ')
		*pi += 1;
	if (ints[*pi] == '\0')
		return (-1);
	if (!(*node = ft_new_node(ints + *pi, pi, NULL)))
		return (-1);
	return (1);
}

int			ft_fill_node(t_node **node, char *ints)
{
	t_node	*tmp;
	t_node	*prev;
	int		i;
	int		*pi;

	i = 0;
	pi = &i;
	if ((ft_fill_first(node, ints, pi)) == -1)
		return (-1);
	tmp = *node;
	while (ints[i])
	{
		if (ints[i] != ' ' && ft_isdigit(ints[i]) == 0)
			return (-1);
		else if (ft_isdigit(ints[i]))
		{
			prev = tmp;
			if (!(tmp->next = ft_new_node(ints + i, pi, prev)))
				return (-1);
			tmp = tmp->next;
		}
		else
			i++;
	}
	return (1);
}
