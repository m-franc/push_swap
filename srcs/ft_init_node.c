/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/26 20:00:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node			*ft_new_node(t_node *check, char *integer)
{
	t_node		*node;
	long long 	num;

	if (ft_ilen(ft_atoi(integer), 10) != (int)ft_strlen(integer))
		return (NULL);
	if (ft_atoi(integer) == 0 && integer[0] != '0')			
		return (NULL);
	num = ft_atoi(integer);
	if (num > INT_MAX || num < INT_MIN)
		return (NULL);
	if ((ft_check_duplicate(check, integer)) == -1)
		return (NULL);
	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->data = num;
	node->next = NULL;
	return (node);
}

int				ft_check_duplicate(t_node *duplicate, char *ints)
{
	while (duplicate)
	{
		if (ft_atoi(ints) == duplicate->data)
			return (-1);
		duplicate = duplicate->next;
	}
	return (0);
}

void			ft_init_index(t_node *check, t_node *new)
{
	int			i;
	t_node		*tmp;

	tmp = check;
	i = 0;
	if (!new->prev)
	{
		INDEX(new) = i;
		return ;
	}
	while (tmp)
	{
		if (DATA(tmp) < DATA(new))
			i++;
		else if (DATA(tmp) > DATA(new))
			INDEX(tmp) += 1;
		tmp = tmp->next;
	}
	INDEX(new) = i;
}

void			ft_push_back(t_node **node, t_node *new)
{
	t_node		*tmp;
	t_node		*prev;

	if (!*node)
	{
		*node = new;
		(*node)->prev = NULL;
	}
	else
	{
		tmp = *node;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;	
		}
		new->prev = prev;
		tmp->next = new;
	}
}

int				ft_arg_got_many_int(t_ctl **a_ctl, char *arg)
{
	char		**ints;
	t_node		*new;
	t_node		*check;
	int			i;

	i = -1;
	if (!(ints = ft_strsplit(arg, ' ')))
		return (-1);
	check = FIRST((*a_ctl));
	while (ints[++i])
	{
		if (!(new = ft_new_node(check, ints[i])))
			return (ft_exit_parsing(a_ctl, NULL, ints));
		check = FIRST((*a_ctl));
		ft_init_index(check, new);
		check = FIRST((*a_ctl));
		ft_push_back(&check, new);
		SIZE((*a_ctl))++;
		LAST((*a_ctl)) = new;
	}
	ft_tabdel(ints);
	return (1);
}

int				ft_arg_got_one_int(t_ctl **a_ctl, char *arg)
{
	t_node		*check;
	t_node		*new;

	check = FIRST((*a_ctl));
	if (!(new = ft_new_node(check, arg)))
		return (ft_exit_begin(a_ctl, NULL));
	check = FIRST((*a_ctl));
	ft_init_index(check, new);
	check = FIRST((*a_ctl));
	ft_push_back(&check, new);
	SIZE((*a_ctl))++;
	LAST((*a_ctl)) = new;
	return (1);
}

int				ft_fill_node(t_node **node, t_ctl **a_ctl, char **args)
{
	int			i;

	i = 1;
	FIRST((*a_ctl)) = *node;
	while (args[i])
	{
//		if (ft_strstr("-v", args[i]))
			// option -v activated
		if (ft_strchr(args[i], ' '))
		{
			if ((ft_arg_got_many_int(a_ctl, args[i])) == -1)
				return (-1);
		}
		else
		{
			if ((ft_arg_got_one_int(a_ctl, args[i])) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
