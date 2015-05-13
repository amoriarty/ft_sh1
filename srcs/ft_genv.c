#include "ft_sh.h"

char					*ft_genv(t_lst *lst, char *entry)
{
	t_lst				*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->entry, entry, ft_len(entry, '=')))
			return (ft_strdup(ft_strchr(tmp->entry, '=') + 1));
		tmp = tmp->next;
	}
	return (NULL);
}
