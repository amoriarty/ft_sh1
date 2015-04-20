#include "ft_sh.h"

void						verifcmd(char *s)
{
	int					i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isprint(s[i]) && !ft_isblank(s[i]))
			process_error("Invalid command", "I have to quit.", TRUE);
	}
}
