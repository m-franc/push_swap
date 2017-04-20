#include "push_swap.h"

int		ft_parse_arg(t_node **a, t_ctl **a_ctl, char **av)
{
	int	nb_args;
	char	**ints;

	if (!(ints = ft_strsplit(av[1], ' ')))
		return (-1);
	nb_args = ft_tablen(ints);
	if (nb_args == 1)
	{
		if (!(*a = ft_new_node(ints[0], NULL)))
			return (-1);
		if (!(ft_fill_node(a, a_ctl, av)))
			return (-1);
	}
	else
	{
		if (!(ft_fill_node(a, a_ctl, ints)))
			return (-1);
	}
	ft_tabdel(ints);
	return (1);
}
