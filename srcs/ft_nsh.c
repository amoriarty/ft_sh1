/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:15:13 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 11:23:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

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
		new->env = ft_glst(env);
		if (!(tmp = ft_genv(new->env, "PATH")))
			new->path = NULL;
		else if ((split = ft_strsplit(tmp, ':')))
			new->path = ft_glst(split);
		new->home = ft_genv(new->env, "HOME");
		free(tmp);
		ft_fctab(split);
	}
	else
	{
		new->env = NULL;
		new->path = NULL;
		new->home = NULL;
	}
	return (new);
}
