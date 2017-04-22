/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:16:26 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/22 18:28:55 by mfranc           ###   ########.fr       */
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

# define FIRST(x) (x->first)
# define NEXT(x) (x->first->next)
# define PREV(x) (x->first->prev)
# define LAST(x) (x->last)
# define SIZE(x) (x->size)
# define DATA(x) (x->data)

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/*
**					COMMON FUNCTIONS
*/
int					ft_fill_node(t_node **node, t_ctl **a_ctl, char **ints);
int					ft_parse_arg(t_node **a, t_ctl **a_ctl, char **av);
t_node				*ft_new_node(char *integer, t_node *prev);
int					ft_check_duplicate(t_node *diplicate, char *ints);
void			ft_delcontroller(t_ctl **a_ctl, t_ctl **b_ctl);
void				ft_putnode(t_node *a, t_node *b);
int					ft_init_ctl(t_ctl **a_ctl, t_ctl **b_ctl);
size_t				ft_verif_pushswap(t_ctl **ctl);


/*
 ** 				EXIT FUNCTIONS
 */
int				ft_exit_begin(t_ctl **a_ctl, t_ctl **b_ctl);
int				ft_exit_parsing(t_ctl **a_ctl, t_ctl **b_ctl, char ** ints);
int				ft_exit_checker(t_ctl **a_ctl, t_ctl **b_ctl, char *line);

/*
 ** 				CHECKER FUNCTIONS
 */
int					ft_checker(t_ctl **a_ctl, t_ctl **b_ctl);
int					ft_find_op(t_ctl **a_ctl, t_ctl **b_ctl, char *line);

/*
 ** 				PUSHSWAP FUNCTIONS
 */

int					*ft_list_to_inttab(t_ctl **cpy);

/*
 **					OPERATIONS FUNCTIONS
 */
void				ft_swap(t_ctl **ctl);
void				ft_sa(t_ctl **ctl);
void				ft_sb(t_ctl **ctl);
void				ft_ss(t_ctl **a, t_ctl **b);

void				ft_push(t_ctl **src_ctl, t_ctl **dest_ctl);
void				ft_pa(t_ctl **src_ctl, t_ctl **dest_ctl);
void				ft_pb(t_ctl **src_ctl, t_ctl **dest_ctl);

void				ft_rotate(t_ctl **ctl);
void				ft_ra(t_ctl **ctl);
void				ft_rb(t_ctl **ctl);
void				ft_rr(t_ctl **a, t_ctl **b);

void				ft_reverse_rotate(t_ctl **ctl);
void				ft_rra(t_ctl **ctl);
void				ft_rrb(t_ctl **ctl);
void				ft_rrr(t_ctl **a, t_ctl **b);
