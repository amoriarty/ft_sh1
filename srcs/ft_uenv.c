/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:16:54 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 16:40:09 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_bool					ft_verif(char *cmd)
{
	char								*tmp;

	if (!(tmp = ft_strchr(cmd, ' ')) || ft_strchr(tmp + 1, ' '))
	{
		ft_sherror("usage: unsetenv [VAR]", NULL, FALSE);
		return (FAILURE);
	}
	return (SUCCESS);
}

void						ft_uenv(t_sh *shell, char *cmd)
{
	char								*t;
	t_lst								*prec;
	t_lst								*tmp;

	if (ft_verif(cmd))
	{
		tmp = shell->env;
		prec = NULL;
		t = ft_strchr(cmd, ' ') + 1;
		if (!ft_strncmp(t, "PATH", 4))
			ft_flst((&(shell->path)));
		while (tmp)
		{
			if (!prec && !ft_strncmp(tmp->entry, t, ft_len(t, '=')))
			{
				shell->env = shell->env->next;
				return ;
			}
			if (prec && !ft_strncmp(tmp->entry, t, ft_len(t, '=')))
			{
				prec->next = tmp->next;
				return ;
			}
			prec = tmp;
			tmp = tmp->next;
		}
	}
}
