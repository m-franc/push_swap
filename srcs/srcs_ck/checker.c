/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/21 17:30:32 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_op(t_ctl **a_ctl, t_ctl **b_ctl, char *line)
{
	if (ft_strnstr(SA, line, 2))
		ft_swap(a_ctl);
	else if (ft_strnstr(SB, line, 2))
		ft_swap(b_ctl);
	else if (ft_strnstr(SS, line, 2))
		ft_sswap(a_ctl, b_ctl);
	else if (ft_strnstr(PA, line, 2))
		ft_push(b_ctl, a_ctl);
	else if (ft_strnstr(PB, line, 2))
		ft_push(a_ctl, b_ctl);
	else if (ft_strnstr(RA, line, 2))
		ft_rotate(a_ctl);
	else if (ft_strnstr(RB, line, 2))
		ft_rotate(b_ctl);
	else if (ft_strnstr(RR, line, 2))
		ft_rrotate(a_ctl, b_ctl);
	else if (ft_strnstr(RRA, line, 3))
		ft_reverse_rotate(a_ctl);
	else if (ft_strnstr(RRB, line, 3))
		ft_reverse_rotate(b_ctl);
	else if (ft_strnstr(RRR, line, 3))
		ft_rreverse_rotate(a_ctl, b_ctl);
//	else
//		return (-1);
	return (1);
}

int			ft_checker(t_ctl **a_ctl, t_ctl **b_ctl)
{
	int		gnl;
	char	*line;
	int		i = 0;

	while ((gnl = get_next_line(0, &line)) == 1)
	{	
		if ((ft_find_op(a_ctl, b_ctl, line)) == -1)
			return (ft_exit_pushswap(a_ctl, b_ctl, line));
		ft_strdel(&line);
		ft_putnode((*a_ctl)->first, (*b_ctl)->first);
		i++;
	}
	if (gnl == -1)
		return (ft_exit_pushswap(a_ctl, b_ctl, NULL));
	ft_printf("{grey}%i{eoc} operations.\n", i);
	if (ft_verif_pushswap(a_ctl) == (*a_ctl)->size)
		ft_putstrcolor("OK !\n", GREEN);
	else
		ft_putstrcolor("KO !\n", RED);
	return (1);
}

int			main(int ac, char **av)
{
	t_node	*a;
	t_ctl	*a_ctl;
	t_ctl	*b_ctl;

	a = NULL;
	a_ctl = NULL;
	b_ctl = NULL;
	if (ac == 1)
		return (ft_exit_pushswap(&a_ctl, &b_ctl, NULL));
	if ((ft_init_ctl(&a_ctl, &b_ctl)) == -1)
		return (-1);
	if ((ft_fill_node(&a, &a_ctl, av)) == -1)		
		return (ft_exit_pushswap(&a_ctl, &b_ctl, NULL));
	if ((ft_checker(&a_ctl, &b_ctl)))
		return (-1);
	return (0);
}
