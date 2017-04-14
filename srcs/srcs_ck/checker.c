/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 12:15:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_node	*a;
	t_ctl	*a_ctl;
	t_ctl	*b_ctl;

	(void)av;
	if (ac == 1)
		return (ft_exit_pushswap(&a));
	a = NULL;
	a_ctl = NULL;
	b_ctl = NULL;
	if ((ft_init_ctl(&a_ctl, &b_ctl)) == -1)
		return (-1);
	if ((ft_fill_node(&a, &a_ctl, av)) == -1)		
		return (ft_exit_pushswap(&a));
//	gnl = get_next_line(1, &line);
//	if (gnl == -1)
//		return (-1);
//	else if (gnl == 1)
//	{
//		if (ft_strstr(line, "sa"))
//			ft_s(&node);
//	}
	ft_putstrcolor("Avant le push: \n", YELLOW);
	ft_printf("taille de ma liste : {green}%zu{eoc}\n", a_ctl->size);
	ft_printf("dernier element de ma liste : {green}%d{eoc}\n", a_ctl->last->data);
	ft_putnode(a_ctl->first);
	ft_rr(&a_ctl);
	ft_rr(&a_ctl);
	ft_rr(&a_ctl);
//	ft_p(&a_ctl, &b_ctl);
//	ft_p(&a_ctl, &b_ctl);
//	ft_p(&a_ctl, &b_ctl);
//	ft_p(&a_ctl, &b_ctl);
//	ft_p(&a_ctl, &b_ctl);
//	ft_p(&a_ctl, &b_ctl);
	ft_putstrcolor("Apres le push : \n", YELLOW);
	ft_putstrcolor("node a : \n", GREEN);
	ft_putnode(a_ctl->first);
	ft_putstrcolor("node b : \n", GREEN);
	ft_putnode(b_ctl->first);
	// make operations
	// check result
	return (0);
}
