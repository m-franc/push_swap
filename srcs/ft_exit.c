/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:30:04 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/29 18:03:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_delcontroller(t_ctl **a_ctl, t_ctl **b_ctl)
{
	t_node	*a;
	t_node	*b;

	if (a_ctl)
	{
		a = (*a_ctl)->first;
		if (a)
			while (a)
			{	
				free(a);
				a = a->next;
			}
		free(*a_ctl);
	}
	if (b_ctl)
	{
		b = (*b_ctl)->first;
		if (b)
			while (b)
			{
				free(b);
				b = b->next;
			}
		free(*b_ctl);
	}
}

int			ft_exit_ps(t_ctl **a_ctl, t_ctl **b_ctl)
{
	ft_delcontroller(a_ctl, b_ctl);
	return (-1);
}

int			ft_exit_parsing(char ***tab)
{
	if (ft_tablen(*tab) != 0)
		ft_tabdel(tab);
	ft_putstrcolor("Error\n", RED);
	return (-1);
}

int			ft_exit_checker(char *line)
{
	if (line)
		ft_strdel(&line);
	ft_putstrcolor("Error\n", RED);
	return (-1);
}
