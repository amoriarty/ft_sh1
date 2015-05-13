#include "ft_sh.h"

void					ft_fctab(char **tab)
{
	int				i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}
