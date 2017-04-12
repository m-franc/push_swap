/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:27:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/12 16:00:38 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_init_ctl(t_ctl **a_ctl, t_ctl **b_ctl)
{
	if (!(*a_ctl = (t_ctl*)malloc(sizeof(t_ctl))))
		return (-1);
	if (!(*b_ctl = (t_ctl*)malloc(sizeof(t_ctl))))
		return (-1);
	(*a_ctl)->first = NULL;
	(*b_ctl)->first = NULL;
	(*a_ctl)->last = NULL;
	(*b_ctl)->last = NULL;
	(*a_ctl)->size = 0;
	(*b_ctl)->size = 0;
	return (1);
}
