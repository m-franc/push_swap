/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 19:33:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/29 17:31:09 by mfranc           ###   ########.fr       */
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
			return (ft_exit_parsing(&ints));
		(*a_ctl)->size++;
		(*a_ctl)->last = new;
	}
	ft_tabdel(&ints);
	return (1);
}

int				ft_arg_got_one_int(t_ctl **a_ctl, char *arg)
{
	t_node		*new;

	if (!(new = ft_new_node(a_ctl, arg)))
		return (ft_exit_parsing(NULL));
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

int				ft_fill_node(t_ctl **a_ctl, char **args)
{
	int			i;

	i = 1;
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
