#include "libft.h"

void	ft_tabdel(char **tab)
{
	char	**cpy;
	int	i;
	
	cpy = tab;
	i = 0;
	while (cpy[i])
		ft_strdel(&cpy[i++]);	
	ft_strdel(cpy);
}
