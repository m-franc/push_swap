/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:53:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/27 16:54:11 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		*ft_verif_data(long long *pnum, t_ctl **a_ctl, char *integer)
{
	t_node		*check;

	check = FIRST((*a_ctl));
	if (ft_ilen(ft_atoi(integer), 10) != (int)ft_strlen(integer))
		return (NULL);
	if (ft_atoi(integer) == 0 && integer[0] != '0')
		return (NULL);
	*pnum = ft_atoi(integer);
	if (*pnum > INT_MAX || *pnum < INT_MIN)
		return (NULL);
	check = FIRST((*a_ctl));
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
	check = FIRST((*a_ctl));
	ft_init_index(check, new);
	check = FIRST((*a_ctl));
	if (!check)
		ft_push_back(&(FIRST((*a_ctl))), new);
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

void			ft_init_index(t_node *check, t_node *new)
{
	int			i;
	t_node		*tmp;

	tmp = check;
	i = 0;
	if (!new->prev)
	{
		INDEX(new) = i;
		return ;
	}
	while (tmp)
	{
		if (DATA(tmp) < DATA(new))
			i++;
		else if (DATA(tmp) > DATA(new))
			INDEX(tmp) += 1;
		tmp = tmp->next;
	}
	INDEX(new) = i;
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
		while (tmp && tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		new->prev = prev;
		tmp->next = new;
	}
}
