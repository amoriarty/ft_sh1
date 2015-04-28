#include "ft_sh.h"

void			verifsplit(t_env *e, char **split)
{
	int		x;
	int		y;

	y = -1;
	while (split[++y])
	{
		x = -1;
		while (split[y][++x])
		{
			if (split[y][x] == '~')
				split[y] = ft_strjoin(gethome(e), split[y] + x + 1);
		}
	}
}
