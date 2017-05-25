/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:04:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/25 21:57:56 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_stack_part_b(t_ctl *ctl)
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

int			ft_get_stack_part_a(t_ctl *ctl)
{
	int		stack_part;
	t_node	*stack;

	stack = ctl->first;
	stack_part = 1;
	stack = stack->next;
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
	int		stack_part_b;
	int		stack_part_a;

	while (a_ctl->size != 1)
		ft_split_stack(&a_ctl, &b_ctl, a_ctl->size);
	while (b_ctl->size != 0)
	{
		if (b_ctl->first->status == 1 || b_ctl->size == 1)
		{
			PSTR("ON PUSH DIRECT")	
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_putnode(a_ctl->first, b_ctl->first);
			ft_debugread();
		}
		else if ((stack_part_b = ft_get_stack_part_b(b_ctl)) > 2 && (ft_is_dsort(&b_ctl) >= (size_t)stack_part_b))
		{
			if ((stack_part_a = ft_get_stack_part_a(a_ctl)) > 2 && (ft_is_asort(&a_ctl) >= (size_t)stack_part_a))
			{
				PSTR("ON REMETS LA MOITIE SUR A, NOTAMENT : ")
				ft_split_part_a(&a_ctl, &b_ctl, stack_part_a);
				ft_putnode(a_ctl->first, b_ctl->first);			
				ft_debugread();
			}
			else
			{
				if (ft_is_asort(&a_ctl) < 2)
				{
					PSTR("ON TRIE DIRECT")	
					ft_sa(&b_ctl, 1);	
					ft_putnode(a_ctl->first, b_ctl->first);			
					ft_debugread();
				}
			}
			PSTR("ON PUSH UNE PARTIE DE B A PARTIR DUNE NEW MED : ")
			ft_split_part_b(&a_ctl, &b_ctl, stack_part_b);
			ft_putnode(a_ctl->first, b_ctl->first);
			ft_debugread();
			PSTR("ON REMETS LA MOITIE SUR A, NOTAMENT : ")
			ft_split_part_a(&a_ctl, &b_ctl, stack_part_a);
			ft_putnode(a_ctl->first, b_ctl->first);			
			ft_debugread();
		}
		else
		{
			PSTR("ON TRIE DIRECT")
			if (ft_is_dsort(&b_ctl) < 2)
				ft_sb(&b_ctl, 1);	
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_pa(&b_ctl, &a_ctl, 1);
			ft_putnode(a_ctl->first, b_ctl->first);
			ft_debugread();
		}	

	}
	ft_putnode(a_ctl->first, b_ctl->first);
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
