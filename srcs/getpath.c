/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:44:54 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 10:50:23 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_env						*ft_getpath(char **path)
{
	int						i;
	t_env						*new;

	i = -1;
	new = NULL;
	while (path[++i])
		new = insertenv(new, path[i]);
	return (new);
}

t_env							*getpath(t_env *env)
{
	t_env						*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->entry, "PATH=", 5))
			return (ft_getpath(ft_strsplit(ft_strchr(tmp->entry, '=') + 1, ':')));
		tmp = tmp->next;
	}
	return (NULL);
}
