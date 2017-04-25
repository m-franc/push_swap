/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/25 12:04:01 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_op(t_ctl **a_ctl, t_ctl **b_ctl, char *line)
{
	if (ft_strnstr(SA, line, 2))
		ft_sa(a_ctl);
	else if (ft_strnstr(SB, line, 2))
		ft_sb(b_ctl);
	else if (ft_strnstr(SS, line, 2))
		ft_ss(a_ctl, b_ctl);
	else if (ft_strnstr(PA, line, 2))
		ft_pa(b_ctl, a_ctl);
	else if (ft_strnstr(PB, line, 2))
		ft_pb(a_ctl, b_ctl);
	else if (ft_strnstr(RA, line, 2))
		ft_ra(a_ctl);
	else if (ft_strnstr(RB, line, 2))
		ft_rb(b_ctl);
	else if (ft_strnstr(RR, line, 2))
		ft_rr(a_ctl, b_ctl);
	else if (ft_strnstr(RRA, line, 3))
		ft_rra(a_ctl);
	else if (ft_strnstr(RRB, line, 3))
		ft_rrb(b_ctl);
	else if (ft_strnstr(RRR, line, 3))
		ft_rrr(a_ctl, b_ctl);
//	else
//		return (-1);
	return (1);
}

int			ft_checker(t_ctl **a_ctl, t_ctl **b_ctl)
{
	int		gnl;
	char	*line;
	int		i;

	// MODIFIER LA MANIERE DE COMPTER LES OPERATIONS
	i = 0;
	while ((gnl = get_next_line(0, &line)) == 1)
	{	
		if ((ft_find_op(a_ctl, b_ctl, line)) == -1)
			return (ft_exit_checker(a_ctl, b_ctl, line));
		ft_strdel(&line);
//		ft_putnode((*a_ctl)->first, (*b_ctl)->first);
		i++;
	}
	if (gnl == -1)
		return (ft_exit_checker(a_ctl, b_ctl, NULL));
	ft_putnode((*a_ctl)->first, (*b_ctl)->first);
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
		return (0);
	if ((ft_init_ctl(&a_ctl, &b_ctl)) == -1)
		return (ft_exit_begin(&a_ctl, &b_ctl));
	if ((ft_parse_arg(&a, &a_ctl, av)) == -1)		
		return (-1);
	if ((ft_checker(&a_ctl, &b_ctl)))
		return (-1);
	return (0);
}
