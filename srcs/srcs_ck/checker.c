/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:30:35 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/11 12:11:03 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_node	*node;

	(void)av;
	if (ac == 1)
		return (ft_exit_pushswap(&node));
	node = NULL;
	if ((ft_fill_node(&node, av[1])) == -1)		
		return (ft_exit_pushswap(&node));
	ft_printf("sa\n");
//	gnl = get_next_line(1, &line);
//	if (gnl == -1)
//		return (-1);
//	else if (gnl == 1)
//	{
//		if (ft_strstr(line, "sa"))
//			ft_s(&node);
//	}
	ft_putstrcolor("Avant le swap : \n", YELLOW);
	ft_putnode(node);
	ft_s(&node);
	ft_putstrcolor("Apres le swap : \n", YELLOW);
	ft_putnode(node);
	// make operations
	// check result
	return (0);
}
