#include "ft_sh.h"

void					ft_free(char **f)
{
	int				i;

	i = -1;
	while (f[++i])
		free(f[i]);
	free(f);
}
