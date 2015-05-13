#include "ft_sh.h"

t_lst					*ft_glst(char **from)
{
	int				i;
	t_lst				*new;

	i = -1;
	new = NULL;
	while (from[++i])
		ft_inode(&new, from[i]);
	return (new);
}
