#include "push_swap.h"

int	ft_exit_ck(char *error, t_node **node)
{
	// free if exist
	ft_printf("{grey}Error : {red}%s{eoc}\n" error);
	return (-1);
}

int	main(int ac, char **av)
{
	t_node	*node;

	if (ac == 1)
		ft_exit_ck("No datas sent", &node);

	return (0);
}
