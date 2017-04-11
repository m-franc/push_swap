/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/11 18:41:12 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	(void)av;
	if (ac == 1)
		return (ft_exit_pushswap(&a));
	a = NULL;
	b = NULL;
	if ((ft_fill_node(&a, av[1])) == -1)		
		return (ft_exit_pushswap(&a));
	ft_printf("sa\n");
//	gnl = get_next_line(1, &line);
//	if (gnl == -1)
//		return (-1);
//	else if (gnl == 1)
//	{
//		if (ft_strstr(line, "sa"))
//			ft_s(&node);
//	}
	ft_putstrcolor("Avant le push: \n", YELLOW);
	ft_putnode(a);
	ft_p(&a, &b);
	ft_p(&a, &b);
	ft_putstrcolor("Apres le push : \n", YELLOW);
	ENDL
	ft_putstrcolor("node a : \n", GREEN);
	ft_putnode(a);
	ft_putstrcolor("node b : \n", GREEN);
	ft_putnode(b);
	// make operations
	// check result
	return (0);
}
