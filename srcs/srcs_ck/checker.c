/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/10 15:06:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exit_ck(t_node **node)
{
	// free if exist
	(void)node;
	ft_printf("Error\n");
	return (-1);
}

t_node	*ft_new_node(char *integer, int *pi, t_node *prev)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->data = ft_atoi(integer);
	*pi += ft_ilen(node->data, 10);
	node->next = NULL;
	node->prev = prev;
	return (node);
}

int	ft_fill_node(t_node **node, char *ints)
{
	t_node	*tmp;
	t_node	*prev;
	int		i;
	int		*pi;

	tmp = *node;
	i = 0;
	pi = &i;
	while (ints[i] && ft_isdigit(ints[i]) == 0)
		i++;
	if (ints[i] == '\0')
		return (ft_exit_ck(node));
	if (!(tmp = ft_new_node(ints + i, pi, NULL)))
		return (ft_exit_ck(node));
	while (ints[i])
	{
		if (ft_isfigit(ints[i]))
		{
			prev = tmp;
			if (!(tmp->next = ft_fill_node(ints + i, pi, prev)))
				return (ft_exit_ck(node));
			tmp = tmp->next;
		}
	}
	return (new);
}

int	main(int ac, char **av)
{
	t_node	*node;

	(void)av;
	if (ac == 1)
		return (ft_exit_ck(&node));
	node = NULL;
	if ((ft_fill_node(&node, av[1])) == -1)		
		return (ft_exit_ck(&node));
	ft_printf("Liste : {green}%s{eoc}\n", av[1]);
	return (0);
}
