/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_senv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:15:22 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 13:12:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_bool					ft_verif(char *cmd)
{
	char				*tmp;

	if (!(tmp = ft_strchr(cmd, ' ')) || !ft_strchr(cmd, '=')
			|| ft_strchr(tmp + 1, ' '))
	{
		ft_sherror("usage: setenv [VAR=VALUE]", FALSE);
		return (FAILURE);
	}
	return (SUCCESS);
}

void						ft_senv(t_sh *shell, char *cmd)
{
	char				*tmp;
	t_lst				*lst;

	lst = shell->env;
	if (ft_verif(cmd))
	{
		tmp = ft_strchr(cmd, ' ') + 1;
		if (!ft_strncmp(tmp, "PATH=", 5))
			shell->path = ft_glst(ft_strsplit(ft_strchr(tmp, '=') + 1, ':'));
		while (lst)
		{
			if (!ft_strncmp(lst->entry, tmp, ft_len(tmp, '=')))
			{
				free(lst->entry);
				lst->entry = ft_strdup(tmp);
				return ;
			}
			lst = lst->next;
		}
		ft_inode((&(shell->env)), tmp);
	}
}
