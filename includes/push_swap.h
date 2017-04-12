/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:16:26 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/12 16:26:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <limits.h>

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_ctl
{
	size_t			size;
	t_node			*first;
	t_node			*last;
}					t_ctl;

// 		COMMON FUNCTIONS
int		ft_exit_pushswap(t_node **node);
int		ft_fill_node(t_node **node, t_ctl **a_ctl, char *ints);
int		ft_fill_first(t_node **node, char *ints, int *pi);
int		ft_fill_next(t_node **node, t_ctl **a_ctl, char *ints, int *pi);
void	ft_putnode(t_node *node);
int		ft_init_ctl(t_ctl **a_ctl, t_ctl **b_ctl);
t_node	*ft_new_node(char *integer, int *pi, t_node *prev);

// OPERATIONS FUNCTIONS
int		ft_s(t_node **node);
int		ft_p(t_node **src, t_node **dest);
