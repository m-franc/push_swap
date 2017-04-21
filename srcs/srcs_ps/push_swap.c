/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/21 18:49:12 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*b;
	size_t	size_a;

	stack_a = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (-1);
	ft_printf("fer\n");
	if ((ft_fill_node(&stack_a, &a, av)) == -1)
		return (ft_exit_pushswap(&a, &b, NULL));
	size_a = a->size;
//	while (ft_verif_pushswap(&a) != size_a)
//	{
		while (a->first)
		{
			if (a->first->data < a->last->data)
			{
				ft_push(&a, &b);
				ft_putendl(PB);
			}
			else
			{
				ft_swap(&a);
				ft_putendl(SA);
			}
			a->first = a->first->next;
		}
//	}
	return (0);
}
