/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 13:20:58 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 13:45:35 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			ft_setchar(char **env, char *cmd)
{
	int				i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], cmd, ft_len(cmd, '=')))
		{
			env[i] = ft_strdup(cmd);
			return ;
		}
	}
}

void				ft_setenv(t_node *node, char *cmd)
{
	char			*tmp;
	t_env			*t;

	tmp = ft_strchr(cmd, ' ') + 1;
	ft_setchar(node->v_env, tmp);
	t = node->env;
	while (t)
	{
		if (!ft_strncmp(t->entry, tmp, ft_len(tmp, '=')))
		{
			t->entry = ft_strdup(tmp);
			if (!ft_strncmp(t->entry, "PATH", 4))
				node->path = getpath(node->v_env);
			return ;
		}
		t = t->next;
	}
	node->env = insertenv(node->env, tmp);
}
