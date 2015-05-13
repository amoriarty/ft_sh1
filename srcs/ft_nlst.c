#include "ft_sh.h"

t_lst						*ft_nlst(char *entry)
{
	t_lst					*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		ft_sherror(NULL, TRUE);
	new->entry = ft_strdup(entry);
	new->next = NULL;
	return (new);
}
