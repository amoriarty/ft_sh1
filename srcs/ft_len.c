#include "ft_sh.h"

size_t						ft_len(char *entry, char c)
{
	size_t					i;

	i = -1;
	while (entry[++i] && entry[i] != c);
	return (i);
}
