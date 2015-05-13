/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:44:54 by alegent           #+#    #+#             */
/*   Updated: 2015/05/13 13:49:16 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_env						*ft_getpath(char **path)
{
	int								i;
	t_env							*new;

	i = -1;
	new = NULL;
	while (path[++i])
		new = insertenv(new, path[i]);
	return (new);
}

t_env								*getpath(t_env *env)
{
	t_env							*tmp;
	char							**split;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->entry, "PATH=", 5))
		{
			split = ft_strsplit(ft_strchr(tmp->entry, '=') + 1, ':');
			return (ft_getpath(split));
		}
		tmp = tmp->next;
	}
	return (NULL);
}
