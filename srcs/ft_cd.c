/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 16:17:55 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 13:13:37 by alegent          ###   ########.fr       */
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
	{
		ft_bzero(ft_strrchr(pwd, '/'), ft_strlen(ft_strrchr(pwd, '/')));
		return (pwd);
	}
	else if (*(tmp + 1) == '/')
		return (ft_strdup(tmp + 1));
	return (factopwd(pwd, tmp));
}

static void					setchar(char **env, char *pwd, char *oldpwd)
{
	int				i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
			env[i] = ft_strjoin("PWD=", pwd);
		if (!ft_strncmp(env[i], "OLDPWD", 6))
			env[i] = ft_strjoin("OLDPWD=", oldpwd);
	}
}

static void					sete(t_env *env, char *pwd, char *oldpwd)
{
	t_env			*t;

	t = env;
	while (t)
	{
		if (!ft_strncmp(t->entry, "PWD", 3))
			t->entry = ft_strjoin("PWD=", pwd);
		if (!ft_strncmp(t->entry, "OLDPWD", 6))
			t->entry = ft_strjoin("OLDPWD=", oldpwd);
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
	setchar(node->v_env, pwd, oldpwd);
	sete(node->env, pwd, oldpwd);
}
