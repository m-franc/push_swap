/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/25 11:52:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_new_node(char *integer, t_node *prev)
{
	t_node		*node;
	long long 	num;

	if (ft_ilen(ft_atoi(integer), 10) != (int)ft_strlen(integer))
		return (NULL);
	num = ft_atoi(integer);
	if (num == 0 && integer[0] != '0')
		return (NULL);
	ft_printf("{cyan}%lld{eoc}\n", num);
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

int			ft_fill_inprogress(t_node **node, t_ctl **a_ctl, char **ints, int *pi)
{
	t_node	*prev;
	t_node	*tmp;
	t_node	*duplicate;

	(*a_ctl)->first = *node;
	(*a_ctl)->size++;
	tmp = *node;
	duplicate = *node;
	while (ints[*pi])
	{
		prev = tmp;
		if ((ft_check_duplicate(duplicate, ints[*pi])) == -1)
			return (-1);
		duplicate = *node;
		if (!(tmp->next = ft_new_node(ints[*pi], prev)))
			return (-1);
		tmp = tmp->next;
		(*a_ctl)->size++;
		(*a_ctl)->last = tmp;
		*pi += 1;
	}
	return (1);
}

int			ft_fill_node(t_node **node, t_ctl **a_ctl, char **ints)
{
	int		i;
	int		*pi;

	if (!*node)
	{
		i = 0;
		if (!(*node = ft_new_node(ints[i++], NULL)))
			return (-1);
	}
	else
		i = 2;
	pi = &i;
	if ((ft_fill_inprogress(node, a_ctl, ints, pi)) == -1)
		return (-1);
	return (1);
}

int		ft_parse_arg(t_node **a, t_ctl **a_ctl, char **av)
{
	int	nb_args;
	char	**ints;

	if (!(ints = ft_strsplit(av[1], ' ')))
		return (ft_exit_parsing(a_ctl, NULL, ints));
	nb_args = ft_tablen(ints);
	if (nb_args == 1)
	{
		if (!(*a = ft_new_node(ints[0], NULL)))
			return (ft_exit_parsing(a_ctl, NULL, ints));
		ft_tabdel(ints);
		if ((ft_fill_node(a, a_ctl, av)) == -1)
			return (ft_exit_begin(a_ctl, NULL));
	}
	else
	{
		if ((ft_fill_node(a, a_ctl, ints)) == -1)
			return (ft_exit_parsing(a_ctl, NULL, ints));
		ft_tabdel(ints);
	}
	return (1);
}
