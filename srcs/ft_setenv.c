/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 13:20:58 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 11:57:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			ft_setchar(t_node *node, char *cmd)
{
	int				i;

	i = -1;
	while (node->v_env[++i])
	{
		if (!ft_strncmp(node->v_env[i], cmd, ft_len(cmd, '=')))
		{
			node->v_env[i] = ft_strdup(cmd);
			if (!ft_strncmp(node->v_env[i], "PATH=", 5))
				node->path = getpath(node->v_env);
			return ;
		}
	}
	node->v_env[i] = ft_strdup(cmd);
	if (!ft_strncmp(cmd, "PATH=", 5))
		node->path = getpath(node->v_env);
}

void				ft_setenv(t_node *node, char *cmd)
{
	char			*tmp;
	t_env			*t;

	if (!(tmp = ft_strchr(cmd, ' ') + 1))
		return ;
	ft_setchar(node, tmp);
	t = node->env;
	while (t)
	{
		if (!ft_strncmp(t->entry, tmp, ft_len(tmp, '=')))
		{
			t->entry = ft_strdup(tmp);
			return ;
		}
		t = t->next;
	}
	node->env = insertenv(node->env, tmp);
}
