/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/29 18:00:03 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_op(t_ctl **a_ctl, t_ctl **b_ctl, char *line)
{
	if (ft_strnstr(line, SA, 2))
		ft_sa(a_ctl, 0);
	else if (ft_strnstr(line, SB, 2))
		ft_sb(b_ctl, 0);
	else if (ft_strnstr(line, SS, 2))
		ft_ss(a_ctl, b_ctl, 0);
	else if (ft_strnstr(line, PA, 2))
		ft_pa(b_ctl, a_ctl, 0);
	else if (ft_strnstr(line, PB, 2))
		ft_pb(a_ctl, b_ctl, 0);
	else if (ft_strnstr(line, RA, 2))
		ft_ra(a_ctl, 0);
	else if (ft_strnstr(line, RB, 2))
		ft_rb(b_ctl, 0);
	else if (ft_strnstr(line, RR, 2))
		ft_rr(a_ctl, b_ctl, 0);
	else if (ft_strnstr(line, RRA, 3))
		ft_rra(a_ctl, 0);
	else if (ft_strnstr(line, RRB, 3))
		ft_rrb(b_ctl, 0);
	else if (ft_strnstr(line, RRR, 3))
		ft_rrr(a_ctl, b_ctl, 0);
	else
		return (-1);
	return (1);
}

int			ft_checker(t_ctl **a_ctl, t_ctl **b_ctl)
{
	int		gnl;
	char	*line;
	int		i;

	i = 0;
	while ((gnl = get_next_line(0, &line)) == 1)
	{
		if ((ft_find_op(a_ctl, b_ctl, line)) == -1)
			return (ft_exit_checker(line));
		else
			i++;
		ft_strdel(&line);
	}
	if (gnl == -1)
		return (-1);
	ft_printf("{grey}%i{eoc} operations.\n", i);
	if (ft_is_asort(a_ctl) == (*a_ctl)->size && (*b_ctl)->size == 0)
		ft_putstrcolor("OK !\n", GREEN);
	else
		ft_putstrcolor("KO !\n", RED);
	return (1);
}

int			main(int ac, char **av)
{
	t_ctl	*a_ctl;
	t_ctl	*b_ctl;

	a_ctl = NULL;
	b_ctl = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a_ctl, &b_ctl)) == -1)
		return (ft_exit_ps(&a_ctl, &b_ctl));
	if ((ft_fill_node(&a_ctl, av)) == -1)
		return (ft_exit_ps(&a_ctl, &b_ctl));
	if ((ft_checker(&a_ctl, &b_ctl)))
		return (-1);
	return (0);
}
