/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:16:26 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/27 17:02:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <limits.h>

typedef struct		s_node
{
	int				data;
	int				index;
	int				dst_top;
	int				dst_bottom;
	int				status;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_ctl
{
	int				size;
	t_node			*first;
	t_node			*last;
}					t_ctl;

typedef struct		s_move
{
	int				pad_a;
	int				pad_b;
	int				ra;
	int				rb;
}					t_move;

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
int					ft_fill_node(t_node **node, t_ctl **a_ctl, char **args);
t_node				*ft_new_node(t_ctl **a_ctl, char *integer);
long long			*ft_verif_data(long long *pnum,
		t_ctl **a_ctl, char *intger);
void				ft_init_index(t_ctl **ctl, t_node *new);
void				ft_push_back(t_node **node, t_node *new);
int					ft_check_duplicate(t_node *diplicate, int num);
void				ft_delcontroller(t_ctl **a_ctl, t_ctl **b_ctl);
void				ft_putnode(t_node *a, t_node *b);
void				ft_putnode_single(t_node *a);
int					ft_init_ctl(t_ctl **a_ctl, t_ctl **b_ctl);
int					ft_is_asort(t_ctl **ctl);
int					ft_is_dsort(t_ctl **ctl);


/*
 ** 				EXIT FUNCTIONS
 */
int					ft_exit_ps(t_ctl **a_ctl, t_ctl **b_ctl);
int					ft_exit_parsing(char ** ints);
int					ft_exit_checker(char *line);

/*
 ** 				CHECKER FUNCTIONS
 */
int					ft_checker(t_ctl **a_ctl, t_ctl **b_ctl);
int					ft_find_op(t_ctl **a_ctl, t_ctl **b_ctl, char *line);

/*
 ** 				PUSHSWAP FUNCTIONS
 */
int					ft_get_medstack(t_ctl **ctl, int part);
void				ft_push_swap(t_ctl *a, t_ctl *b);
void				ft_little_sort(t_ctl **a_ctl, int size_a);
t_node				*ft_get_max_value(t_ctl *ctl);
t_node				*ft_get_min_value(t_ctl *ctl);
void				ft_split_stack(t_ctl **a_ctl, t_ctl **b_ctl, int size);
void				ft_split_part_a(t_ctl **a_ctl, t_ctl **b_ctl, int size);
void				ft_split_part_b(t_ctl **a_ctl, t_ctl **b_ctl, int size);
int					ft_get_stack_part_a(t_ctl *ctl);
int					ft_get_stack_part_b(t_ctl *ctl);
void				ft_quick_sort(t_ctl *a_ctl, t_ctl *b_ctl, int stack_part_b);
void				ft_init_dst(t_ctl **ctl);

/*
 **					OPERATIONS FUNCTIONS
 */
void				ft_swap(t_ctl **ctl);
void				ft_sa(t_ctl **ctl, int ps);
void				ft_sb(t_ctl **ctl, int ps);
void				ft_ss(t_ctl **a, t_ctl **b, int ps);

void				ft_push(t_ctl **src_ctl, t_ctl **dest_ctl);
void				ft_pa(t_ctl **src_ctl, t_ctl **dest_ctl, int ps);
void				ft_pb(t_ctl **src_ctl, t_ctl **dest_ctl, int ps);

void				ft_rotate(t_ctl **ctl);
void				ft_ra(t_ctl **ctl, int ps);
void				ft_rb(t_ctl **ctl, int ps);
void				ft_rr(t_ctl **a, t_ctl **b, int ps);

void				ft_reverse_rotate(t_ctl **ctl);
void				ft_rra(t_ctl **ctl, int ps);
void				ft_rrb(t_ctl **ctl, int ps);
void				ft_rrr(t_ctl **a, t_ctl **b, int ps);
