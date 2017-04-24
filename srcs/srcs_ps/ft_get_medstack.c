/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_medstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:58:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/24 18:53:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_medstack(t_ctl **ctl)
{
	int		median;
	int		*tab;
	size_t	i;

	if (!(tab = ft_list_to_inttab(ctl)))
		return (INT_MIN);
	ft_printf("taille du tableau : {cyan}%d{eoc}\n", SIZE((*ctl)));
	i = 0;
	ft_sort_int_tab(tab, SIZE((*ctl)));
	while (i < SIZE((*ctl)))
		i++;	
	median = ft_get_median(tab, SIZE((*ctl)));
	free(tab);
	return (median);
}
