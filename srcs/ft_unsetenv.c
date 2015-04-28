/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 13:53:18 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 13:20:54 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void					ft_setchar(char **env, char *cmd)
{
	int						i;

	i = 0;
	while (!ft_strncmp(env[i], cmd, ft_len(cmd, '=')))
		i++;
	ft_bzero(env[i], ft_strlen(env[i]));
}

static void					facto(t_node *node, char *tmp)
{
	t_env					*t;
	t_env					*prec;

	t = node->env;
	prec = NULL;
	while (t)
	{
		if (!prec && !ft_strncmp(t->entry, tmp, ft_len(tmp, '=')))
		{
			node->path = (!ft_strncmp(t->entry, "PATH", 4)) ? NULL : node->path;
			node->env = node->env->next;
			return ;
		}
		if (prec && !ft_strncmp(t->entry, tmp, ft_len(tmp, '=')))
		{
			node->path = (!ft_strncmp(t->entry, "PATH", 4)) ? NULL : node->path;
			prec->next = t->next;
			return ;
		}
		prec = t;
		t = t->next;
	}
}

void						ft_unsetenv(t_node *node, char *cmd)
{
	char					*tmp;

	if (!(tmp = ft_strchr(cmd, ' ')) || !(*(tmp++)) || !ft_isprint(*tmp))
	{
		process_error(NULL, "usage: unsetenv [VAR]", FALSE);
		return ;
	}
	ft_setchar(node->v_env, tmp);
	facto(node, tmp);
}
