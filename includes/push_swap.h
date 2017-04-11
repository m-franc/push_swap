/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:16:26 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/11 12:05:45 by mfranc           ###   ########.fr       */
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

// 		COMMON FUNCTIONS
int		ft_exit_pushswap(t_node **node);
int		ft_fill_node(t_node **node, char *ints);
int		ft_exit_pushswap(t_node **node);
int		ft_fill_first(t_node **node, char *ints, int *pi);
void	ft_putnode(t_node *node);
t_node	*ft_new_node(char *integer, int *pi, t_node *prev);

// OPERATIONS FUNCTIONS
void	ft_s(t_node **node);
