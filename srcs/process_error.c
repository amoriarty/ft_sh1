#include "ft_sh.h"

void			process_error(char *cmd, char *error, int xit)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(ft_strsub(cmd, 0, ft_len(cmd, ' ')), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
	if (xit == TRUE)
		exit(EXIT_FAILURE);
}
