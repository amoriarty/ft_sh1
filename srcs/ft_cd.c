/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:09:18 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 11:27:21 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_bool							ft_verif(char *cmd)
{
	if (ft_strchr(ft_strchr(cmd, ' ') + 1, ' '))
	{
		ft_sherror("usage: cd [PATH]", NULL, FALSE);
		return (FAILURE);
	}
	return (SUCCESS);
}

static char								*ft_fpwd(char *cmd)
{
	char								*pwd;
	char								*tmp;

	pwd = getcwd(NULL, 0);
	while (*cmd)
	{
		tmp = ft_strrchr(pwd, '/');
		cmd += (*cmd == '/' || (*cmd == '.' && *(cmd + 1) == '/')) ? 1 : 0;
		if (!ft_strncmp(cmd, "..", 2))
		{
			ft_bzero(tmp, ft_strlen(tmp));
			cmd += 2;
		}
		if (ft_isprint(*cmd) && *cmd != '/')
		{
			pwd = ft_strjoin(ft_strjoin(pwd, "/"),
					ft_strsub(cmd, 0, ft_len(cmd, '/')));
			cmd += ft_len(cmd, '/');
		}
		cmd++;
	}
	return (pwd);
}

static char								*ft_gpwd(t_sh *shell, char *cmd)
{
	if (!cmd)
		return (shell->home);
	cmd++;
	if (*cmd == '~')
		return (ft_strjoin(shell->home, cmd + 1));
	else if (!ft_strcmp(cmd, "-"))
		return (ft_genv(shell->env, "OLDPWD"));
	else if (*cmd == '/')
		return (cmd);
	return (ft_fpwd(cmd));
}

void									ft_cd(t_sh *shell, char *cmd)
{
	char								*pwd;
	char								*path;

	if (ft_verif(cmd))
	{
		pwd = getcwd(NULL, 0);
		path = ft_gpwd(shell, ft_strchr(cmd, ' '));
		if (!access(path, F_OK) && access(path, X_OK))
		{
			ft_sherror("Permission denied", ft_strchr(cmd, ' ') + 1, FALSE);
			return ;
		}
		if (chdir(path) == ERROR)
		{
			ft_sherror("No such directory.", ft_strchr(cmd, ' ') + 1, FALSE);
			return ;
		}
		ft_senv(shell, ft_strjoin("setenv OLDPWD=", pwd));
		ft_senv(shell, ft_strjoin("setenv PWD=", path));
	}
}
