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

void				ft_setenv(t_node *node, char *cmd)
{
	char			*tmp;
	char			**error;
	t_env			*t;

	error = NULL;
	if (!(tmp = ft_strchr(cmd, ' ') + 1) || !ft_strchr(cmd, '=')
			|| ((error = ft_strsplit(tmp, ' ')) && error[1]))
	{
		if (error)
			ft_free(error);
		process_error(NULL, "usage: setenv [VAR=VALUE]", FALSE);
		return ;
	}
	t = node->env;
	while (t)
	{
		if (!ft_strncmp(t->entry, tmp, ft_len(tmp, '=')))
		{
			free(t->entry);
			t->entry = ft_strdup(tmp);
			return ;
		}
		t = t->next;
	}
	node->env = insertenv(node->env, tmp);
}
