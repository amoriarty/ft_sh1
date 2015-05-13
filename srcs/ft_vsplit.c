#include "ft_sh.h"

void					ft_vsplit(t_sh *shell, char **split)
{
	int				x;
	int				y;

	y = -1;
	if (!split)
		ft_sherror(NULL, TRUE);
	while (split[++y])
	{
		x = -1;
		while (split[y][++x])
		{
			if (split[y][x] == '~')
				split[y] = ft_strjoin(shell->home, split[y] + x + 1);
		}
	}
}
