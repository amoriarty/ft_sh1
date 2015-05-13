#include "ft_sh.h"

void					ft_sherror(char *error, t_bool i)
{
	if (error)
	{
		ft_putstr_fd("42sh: ", 2);
		ft_putendl_fd(error, 2);
	}
	if (i == TRUE)
		exit(EXIT_FAILURE);
}
