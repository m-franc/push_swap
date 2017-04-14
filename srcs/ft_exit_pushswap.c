/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:30:04 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/14 18:35:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_exit_pushswap(t_ctl **a_ctl, t_ctl **b_ctl, char *line)
{
	//free if exist
	(void)a_ctl;
	(void)b_ctl;
	(void)line;
	ft_putstrcolor("Error\n", RED);
	return (-1);
}
