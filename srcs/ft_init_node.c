/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 19:25:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_arg_got_many_int(t_ctl **a_ctl, char *arg)
{
	char		**ints;
	t_node		*new;
	int			i;

	i = -1;
	if (!(ints = ft_strsplit(arg, ' ')))
		return (-1);
	while (ints[++i])
	{
		if (!(new = ft_new_node(a_ctl, ints[i])))
			return (ft_exit_parsing(ints));
		(*a_ctl)->size++;
		(*a_ctl)->last = new;
	}
	ft_tabdel(ints);
	return (1);
}

int				ft_arg_got_one_int(t_ctl **a_ctl, char *arg)
{
	t_node		*new;

	if (!(new = ft_new_node(a_ctl, arg)))
		return (-1);
	(*a_ctl)->size++;
	(*a_ctl)->last = new;
	return (1);
}

void			ft_init_dst(t_ctl **ctl)
{
	t_node	*check;
	int		i;
	
	i = 0;
	if ((*ctl)->size == 0)
		return ;
	check = (*ctl)->first;
	while (check)
	{	
		check->dst_top = 0;
		check->dst_bottom = 0;
		check->dst_bottom += ((*ctl)->size - i);
		check->dst_top += i;
		check = check->next;
		i++;
	}
}

int				ft_fill_node(t_node **node, t_ctl **a_ctl, char **args)
{
	int			i;

	i = 1;
	(*a_ctl)->first = *node;
	while (args[i])
	{
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
	ft_init_dst(a_ctl);
	return (1);
}
