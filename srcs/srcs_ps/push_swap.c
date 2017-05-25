/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/25 12:59:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_stack_part(t_ctl *ctl)
{
	int		stack_part;
	t_node	*stack;

	stack = ctl->first;
	stack_part = 0;
	while (stack && stack->status != 1)
	{
		stack_part++;
		stack = stack->next;
	}
	return (stack_part);
}

void		ft_debugread(void)
{
	char	line[5];
	int		ret;

	ret = read(0, line, 5);
	line[ret] = '\0';
}

int			ft_push_swap(t_ctl *a_ctl, t_ctl *b_ctl)
{
	int		stack_part;
	int		stack_part_cpy;
	int		stack_part_a;
	int		nbs_sorted;

	while (a_ctl->size != 1)
		ft_split_a(&a_ctl, &b_ctl, a_ctl->size);
	while (b_ctl->size != 0)
	{
		if (b_ctl->first->status == 1)
		{
//			PSTR("ON PUSH DIRECT")	
			ft_pa(&b_ctl, &a_ctl, 1);
//			ft_putnode(a_ctl->first, b_ctl->first);
		}
		else if ((stack_part = ft_get_stack_part(b_ctl)) > 2)
		{
//			PSTR("ON REPUSH SUR A")	
//			ft_putnode(a_ctl->first, b_ctl->first);
//			PSTR("ON RECALCULE UNE MEDIANE SUR NOTRE PORTION DE STACK : ")	
			while ((stack_part = ft_get_stack_part(b_ctl)) > 2)
			{
				stack_part_cpy = stack_part;
				ft_split_part(&a_ctl, &b_ctl, stack_part_cpy);
				if ((stack_part_a = ft_get_stack_part(a_ctl)) > 2)
					ft_split_part(&b_ctl, &a_ctl, stack_part_cpy);
				else
				{
					if ((nbs_sorted = ft_is_asort(&a_ctl) < 2))
						ft_sa(&b_ctl, 1);	
				}
			}
		//	ft_putnode(a_ctl->first, b_ctl->first);
		}
		else
		{
		//	PSTR("ON TRIE DIRECT")
			if ((nbs_sorted = ft_is_dsort(&b_ctl) < 2))
				ft_sb(&b_ctl, 1);	
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_pa(&b_ctl, &a_ctl, 1);
//			ft_putnode(a_ctl->first, b_ctl->first);
		}	
//		ft_debugread();
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_node	*stack_a;
	t_ctl	*a;
	t_ctl	*b;

	stack_a = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if ((ft_init_ctl(&a, &b)) == -1)
		return (ft_exit_ps(&a, &b));
	if ((ft_fill_node(&stack_a, &a, av)) == -1)
		return (ft_exit_ps(&a, &b));
	if ((ft_push_swap(a, b)) == -1)
		return (-1);
	return (0);
}
