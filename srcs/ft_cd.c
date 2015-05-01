/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 16:17:55 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 10:16:43 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char					*factopwd(char *pwd, char *tmp)
{
	char					*tmp1;

	while (*(++tmp))
	{
		tmp1 = ft_strrchr(pwd, '/');
		tmp += (*tmp == '/' || (*tmp == '.' && *(tmp + 1) == '/')) ? 1 : 0;
		if (!ft_strncmp(tmp, "..", 2))
		{
			ft_bzero(tmp1, ft_strlen(tmp1));
			tmp += 2;
		}
		if (ft_isprint(*tmp) && *tmp != '/')
		{
			pwd = ft_strjoin(ft_strjoin(pwd, "/"),
					ft_strsub(tmp, 0, ft_len(tmp, '/')));
			tmp += ft_len(tmp, '/');
		}
	}
	return (pwd);
}

static char					*getnewpwd(t_node *node, char *pwd, char *cmd)
{
	char			*tmp;

	if (!(tmp = ft_strchr(cmd, ' ')))
		return (gethome(node->env));
	if (*(tmp + 1) == '~')
		return (ft_strjoin(gethome(node->env), (tmp + 2)));
	else if (!ft_strcmp(tmp + 1, "-"))
		return (getoldpwd(node));
	else if (*(tmp + 1) == '/')
		return (ft_strdup(tmp + 1));
	return (factopwd(pwd, tmp));
}

static void					sete(t_env *env, char *pwd, char *oldpwd)
{
	t_env			*t;

	t = env;
	while (t)
	{
		if (!ft_strncmp(t->entry, "PWD", 3))
		{
			free(t->entry);
			t->entry = ft_strjoin("PWD=", pwd);
		}
		if (!ft_strncmp(t->entry, "OLDPWD", 6))
		{
			free(t->entry);
			t->entry = ft_strjoin("OLDPWD=", oldpwd);
		}
		t = t->next;
	}
}

void						ft_cd(t_node *node, char *cmd)
{
	char			*pwd;
	char			*oldpwd;
	char			**error;

	error = ft_strsplit(cmd, ' ');
	if (error[2])
	{
		process_error(NULL, "usage: cd [PATH]", FALSE);
		return ;
	}
	oldpwd = getcwd(NULL, 0);
	pwd = getnewpwd(node, oldpwd, cmd);
	if (chdir(pwd) == ERROR)
	{
		process_error(pwd, "No such directory.", FALSE);
		return ;
	}
	sete(node->env, pwd, oldpwd);
}
