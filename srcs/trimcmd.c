#include "ft_sh.h"

char			*trimcmd(char *cmd)
{
	int		i;
	char		*new;
	static int	begin;

	i = 0;
	new = ft_strnew(ft_strlen(cmd) + 1);
	while (*cmd && ft_isblank(*cmd))
		cmd++;
	if (begin == 0)
		begin++;
	else
		new[i++] = ' ';
	while (*cmd && ft_isprint(*cmd))
		new[i++] = *(cmd++);
	if (*cmd)
		return (ft_strjoin(new, trimcmd(cmd)));
	begin = 0;
	return (new);
}
