/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:30:04 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 18:35:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_delcontroller(t_ctl **a_ctl, t_ctl **b_ctl)
{
//	t_node	*a;
//	t_node	*b;

	if (a_ctl)
	{
	/*	a = (*a_ctl)->first;
		if (a)
		{
			while (a)
			{	
				free(a);
				a = a->next;
			}
		}
	*/	free(*a_ctl);
	}
	if (b_ctl)
	{
	/*	b = (*b_ctl)->first;
		if (b)
		{
			while (b)
			{
				free(b);
				b = b->next;
			}
		}
	*/	free(*b_ctl);
	}
}

int			ft_exit_begin(t_ctl **a_ctl, t_ctl **b_ctl)
{
	ft_delcontroller(a_ctl, b_ctl);
//	(void)a_ctl;
//	(void)b_ctl;
	ft_putstrcolor("Error\n", RED);
	return (-1);
}

int			ft_exit_parsing(t_ctl **a_ctl, t_ctl **b_ctl, char **tab)
{
	ft_delcontroller(a_ctl, b_ctl);
//	(void)a_ctl;
//	(void)b_ctl;
	if (ft_tablen(tab) != 0)
		ft_tabdel(tab);
	ft_putstrcolor("Error\n", RED);
	return (-1);
}

int			ft_exit_checker(t_ctl **a_ctl, t_ctl **b_ctl, char *line)
{
	ft_delcontroller(a_ctl, b_ctl);
//	(void)a_ctl;
//	(void)b_ctl;
	if (line)
		ft_strdel(&line);
	ft_putstrcolor("Error\n", RED);
	return (-1);
}
