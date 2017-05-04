/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/04 12:17:42 by mfranc           ###   ########.fr       */
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
		ft_putnode(FIRST((*a_ctl)), NULL);
		SIZE((*a_ctl))++;
		LAST((*a_ctl)) = new;
	}
	ft_tabdel(ints);
	return (1);
}

int				ft_arg_got_one_int(t_ctl **a_ctl, char *arg)
{
	t_node		*new;

	if (!(new = ft_new_node(a_ctl, arg)))
		return (-1);
	SIZE((*a_ctl))++;
	LAST((*a_ctl)) = new;
	return (1);
}

void			ft_init_dst(t_ctl **a_ctl)
{
	t_node	*check;
	int		i;
	
	i = 0;
	check = FIRST((*a_ctl));
	while (check)
	{	
		DST_BOTTOM(check) += (SIZE((*a_ctl)) - i);
		DST_TOP(check) += i;
		check = NEXT(check);
		i++;
	}
}

int				ft_fill_node(t_node **node, t_ctl **a_ctl, char **args)
{
	int			i;

	i = 1;
	FIRST((*a_ctl)) = *node;
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
