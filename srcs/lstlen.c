#include "ft_sh.h"

int					lstlen(t_env *e)
{
	int				i;
	t_env				*tmp;

	i = 0;
	tmp = e;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
