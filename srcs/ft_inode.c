#include "ft_sh.h"

void					ft_inode(t_lst **lst, char *entry)
{
	t_lst				*tmp;

	if (!(*lst))
		*lst = ft_nlst(entry);
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_nlst(entry);
	}
}
