/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_datas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:40:11 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/03 17:40:29 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_update_dst_after_rr(t_ctl *ctl, int padding)
{
	t_node	*tmp;

	tmp = FIRST(ctl);
	while (tmp)
	{
		DST_BOTTOM(tmp) -= padding;
		DST_TOP(tmp) += padding;
		if (DST_BOTTOM(tmp) < 0)
			DST_BOTTOM(tmp) *= -1;
		if (DST_TOP(tmp) < 0)
			DST_TOP(tmp) *= -1;
		tmp = NEXT(tmp);
	}
}

void		ft_update_dst_after_r(t_ctl *ctl, int padding)
{
	t_node	*tmp;

	tmp = FIRST(ctl);
	while (tmp)
	{
		DST_BOTTOM(tmp) += (padding);
		DST_TOP(tmp) -= padding;
		if (DST_BOTTOM(tmp) < 0)
			DST_BOTTOM(tmp) *= -1;
		if (DST_TOP(tmp) < 0)
			DST_TOP(tmp) *= -1;
		tmp = NEXT(tmp);
	}
}
