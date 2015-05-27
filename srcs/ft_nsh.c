/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:15:13 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 11:35:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void				ft_norme(t_sh *shell, char **env)
{
	char				*tmp;
	char				**split;

	shell->env = ft_glst(env);
	if (!(tmp = ft_genv(shell->env, "PATH")))
		shell->path = NULL;
	else if ((split = ft_strsplit(tmp, ':')))
	{
		shell->path = ft_glst(split);
		ft_fctab(split);
		free(tmp);
	}
}

t_sh					*ft_nsh(char **env)
{
	t_sh				*new;
	char				*tmp;
	char				**split;

	tmp = NULL;
	split = NULL;
	if (!(new = (t_sh *)malloc(sizeof(t_sh))))
		ft_sherror(NULL, NULL, TRUE);
	if (env)
	{
		ft_norme(new, env);
		new->home = ft_genv(new->env, "HOME");
	}
	else
	{
		new->env = NULL;
		new->path = NULL;
		new->home = NULL;
	}
	return (new);
}
