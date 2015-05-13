#include "ft_sh.h"

char					*ft_gcmd(char *cmd)
{
	char				*next;

	next = NULL;
	ft_putcolor((cmd) ? "> " : "$> ", GREEN);
	if (get_next_line(0, &next) == 0)
		exit(EXIT_FAILURE);
	if (next[ft_strlen(next) - 1] == '\\')
	{
		next[ft_strlen(next) - 1] = 0;
		return (ft_gcmd(ft_strjoin(cmd, next)));
	}
	return ((cmd) ? ft_strjoin(cmd, next) : next);
}
