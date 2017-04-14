/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 19:22:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_op(t_ctl **a_ctl, t_ctl **b_ctl, char *line)
{
	if (ft_strstr(line, SA))
		ft_swap(a_ctl);
	else if (ft_strstr(line, SB))
		ft_swap(b_ctl);
	else if (ft_strstr(line, SS))
		ft_sswap(a_ctl, b_ctl);
	else if (ft_strstr(line, PA))
		ft_push(b_ctl, a_ctl);
	else if (ft_strstr(line, PB))
		ft_push(a_ctl, b_ctl);
	else if (ft_strstr(line, RA))
		ft_rotate(a_ctl);
	else if (ft_strstr(line, RB))
		ft_rotate(b_ctl);
	else if (ft_strstr(line, RR))
		ft_rrotate(a_ctl, b_ctl);
	else if (ft_strstr(line, RRA))
		ft_reverse_rotate(a_ctl);
	else if (ft_strstr(line, RRB))
		ft_reverse_rotate(b_ctl);
	else if (ft_strstr(line, RRR))
		ft_rreverse_rotate(a_ctl, b_ctl);
	else
		return (-1);
	return (1);
}

int			ft_checker(t_ctl **a_ctl, t_ctl **b_ctl)
{
	int		gnl;
	char	*line;

	while ((gnl = get_next_line(1, &line)) == 1)
	{
		if ((ft_find_op(a_ctl, b_ctl, line)) == -1)
			return (ft_exit_pushswap(a_ctl, b_ctl, line));
		ft_strdel(&line);
		ft_putstrcolor("STACK A : \n", GREEN);
		ft_putnode((*a_ctl)->first);
		ft_putstrcolor("STACK B : \n", GREEN);
		ft_putnode((*b_ctl)->first);
	}
	if (gnl == -1)
		return (ft_exit_pushswap(a_ctl, b_ctl, NULL));
	if (ft_verif_pushswap(a_ctl) == (*a_ctl)->size)
		ft_printf("{red}OK %S{eoc}\n", 0x1F60E);
	else
		ft_printf("{green}KO %S{eoc}\n", 0x1F61E);
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
	//	ft_putstrcolor("Avant le push: \n", YELLOW);
	//	ft_printf("taille de ma liste : {green}%zu{eoc}\n", a_ctl->size);
	//	ft_printf("dernier element de ma liste : {green}%d{eoc}\n", a_ctl->last->data);
	//	ft_rr(&a_ctl);
	//	ft_p(&a_ctl, &b_ctl);
	//	ft_p(&a_ctl, &b_ctl);
	//	ft_p(&a_ctl, &b_ctl);
	//	ft_p(&a_ctl, &b_ctl);
	//	ft_p(&a_ctl, &b_ctl);
	//	ft_p(&a_ctl, &b_ctl);
	//	ft_putstrcolor("Apres le push : \n", YELLOW);
	//	ft_putstrcolor("node a : \n", GREEN);
	//	ft_putnode(a_ctl->first);
	//	ft_putstrcolor("node b : \n", GREEN);
	//	ft_putnode(b_ctl->first);
	// make operations
	// check result
	return (0);
}
