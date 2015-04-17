#include "ft_sh.h"

void			multicmd(t_node *node, char *cmd)
{
	int		i;
	char		**split;

	i = -1;
	split = ft_strsplit(trimcmd(cmd), ';');
	while (split[++i])
		analyze(node, trimcmd(split[i]));
}
