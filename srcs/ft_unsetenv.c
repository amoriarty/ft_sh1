/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 13:53:18 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 11:44:18 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

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
			node->env = node->env->next;
			t = node->env;
			return ;
		}
		if (prec && !ft_strncmp(t->entry, tmp, ft_len(tmp, '=')))
		{
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

	if (!(tmp = ft_strchr(cmd, ' ')) || !(++tmp) || !(*tmp) || !ft_isprint(*tmp))
	{
		process_error(NULL, "usage: unsetenv [VAR]", FALSE);
		return ;
	}
	facto(node, tmp);
}
