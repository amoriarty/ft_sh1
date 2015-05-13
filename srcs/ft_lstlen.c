#include "ft_sh.h"

size_t						ft_lstlen(t_lst *lst)
{
	size_t					i;
	t_lst					*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
