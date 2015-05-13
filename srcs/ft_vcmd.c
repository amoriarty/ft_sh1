#include "ft_sh.h"

void					ft_vcmd(char *cmd)
{
	int				i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_isprint(cmd[i]) && !ft_isblank(cmd[i]))
			ft_sherror("Invalid command, I have to quit.", TRUE);
	}
}
