/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_inttab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:48:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/22 18:41:25 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_list_to_inttab(t_ctl **cpy)
{
	int		*tab;
	int		i;
	t_node	*cursor;
	int		size_tab;

	size_tab = SIZE((*cpy));
	if (!(tab = (int*)malloc(sizeof(int) * (size_tab + 1))))
		return (NULL);
	cursor = FIRST((*cpy));
	i = -1;
	while (++i <= size_tab && cursor)
	{	
		tab[i] = DATA(cursor);
		cursor = cursor->next;
	}
	return (tab);
}
