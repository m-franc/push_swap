/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/25 18:13:29 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_new_node(t_node *check, char *integer, t_node *prev)
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
	node->prev = prev;
	integer += ft_ilen(num, 10);
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

void		ft_init_index(t_node *check, t_node *new)
{
	int		i;
	t_node	*tmp;

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

int			ft_fill_node(t_node **node, t_ctl **a_ctl, char **args)
{
	int		i;
	t_node	*prev;
	t_node	*tmp;
	t_node	*check;
	char	**ints;

	i = 1;
	tmp = *node;
	while (args[i])
	{
		prev = tmp;
		if (ft_strchr(args[i], ' '))
		{
			if (!(ints = ft_strsplit(args[i], ' ')))
				return (-1);
			while (ints)
			{
				check = *node;
				if (!(tmp->next = ft_new_node(check, *ints, prev)))
					return (-1);
				check = *node;
				tmp = tmp->next;
				ft_init_index(check, tmp);
				check = *node;
				ints++;
			}
		}
		else
		{
			check = *node;
			if (!(tmp->next = ft_new_node(check, args[i], prev)))
				return (-1);
			check = *node;
			tmp = tmp->next;
			ft_init_index(check, tmp);
			check = *node;
		}
		(*a_ctl)->size++;
		(*a_ctl)->last = tmp;
		i++;
	}
	return (1);
}

/*
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
   }*/
