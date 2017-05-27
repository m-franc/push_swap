/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:53:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 19:25:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		*ft_verif_data(long long *pnum, t_ctl **a_ctl, char *integer)
{
	t_node		*check;

	check = (*a_ctl)->first;
	*pnum = ft_atoi(integer);
	if (ft_ilen(*pnum, 10) != (int)ft_strlen(integer))
		if (((ft_ilen(*pnum, 10) - 1) == (int)ft_strlen(integer))
			&& integer[0] != '0')
			return (NULL);
	if (*pnum == 0 && integer[0] != '0')
		if (ft_strcmp(integer, "+0") != 0)
			return (NULL);
	if (*pnum > INT_MAX || *pnum < INT_MIN)
		return (NULL);
	check = (*a_ctl)->first;
	if ((ft_check_duplicate(check, *pnum)) == -1)
		return (NULL);
	return (pnum);
}

t_node			*ft_new_node(t_ctl **a_ctl, char *integer)
{
	t_node		*new;
	t_node		*check;
	long long	*pnum;
	long long	num;

	num = 0;
	pnum = &num;
	if (!(ft_verif_data(pnum, a_ctl, integer)))
		return (NULL);
	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	new->data = num;
	new->next = NULL;
	ft_init_index(a_ctl, new);
	new->dst_bottom = 0;
	new->dst_top = 0;
	new->status = 0;
	new->prev = NULL;
	check = (*a_ctl)->first;
	if (!check)
		ft_push_back(&(*a_ctl)->first, new);
	else
		ft_push_back(&check, new);
	return (new);
}

int				ft_check_duplicate(t_node *duplicate, int num)
{
	while (duplicate)
	{
		if (num == duplicate->data)
			return (-1);
		duplicate = duplicate->next;
	}
	return (0);
}

void			ft_init_index(t_ctl **ctl, t_node *new)
{
	int			i;
	t_node		*tmp;

	tmp = (*ctl)->first;
	i = 0;
	if ((*ctl)->size == 0)
	{
		new->index = i;
		return ;
	}
	while (tmp)
	{
		if (tmp->data < new->data)
			i++;
		else if (tmp->data > new->data)
			tmp->index += 1;
		tmp = tmp->next;
	}
	new->index = i;
}

void			ft_push_back(t_node **node, t_node *new)
{
	t_node		*tmp;
	t_node		*prev;

	if (!*node)
	{
		*node = new;
		(*node)->prev = NULL;
	}
	else
	{
		tmp = *node;
		prev = tmp;
		while (tmp && tmp->next)
		{
			tmp = tmp->next;
			prev = tmp;
		}
		tmp->next = new;
		new->prev = prev;
	}
}
