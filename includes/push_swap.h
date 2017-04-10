#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

typedef struct		s_node
{
	int		data;
	struct s_node	*next;
	struct s_node	*previous;
}			t_node;

int		ft_exit_ck(t_node **node);
int		ft_fill_node(t_node **node, char *ints, int *pi, t_node *prev);
