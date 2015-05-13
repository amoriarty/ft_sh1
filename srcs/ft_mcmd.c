#include "ft_sh.h"

void						ft_mcmd(t_sh *shell, char *cmd)
{
	int					i;
	char					**split;

	i = -1;
	split = ft_strsplit(cmd, ';');
	while (split[++i])
		ft_analyze(shell, split[i]);
	ft_fctab(split);
}
