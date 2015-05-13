#include "ft_sh.h"

void					ft_env(t_lst *env)
{
	t_lst				*tmp;

	tmp = env;
	while (tmp)
	{
		ft_putendl(tmp->entry);
		tmp = tmp->next;
	}
}
