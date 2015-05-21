/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:12:40 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 17:32:50 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char				*ft_fpath(t_sh *shell, char *cmd)
{
	char				*tmp;
	t_lst				*path;

	tmp = NULL;
	path = shell->path;
	while (path)
	{
		tmp = ft_strjoin(ft_strjoin(path->entry, "/"), cmd);
		if (!access(tmp, F_OK))
			return (tmp);
		path = path->next;
	}
	return (NULL);
}

char					*ft_gpath(t_sh *shell, char *cmd)
{
	char				*path;

	if (cmd[0] == '.' || cmd[0] == '~' || cmd[0] == '/')
	{
		if (cmd[0] == '.')
			path = ft_strjoin(
					ft_strjoin(getcwd(NULL, 0), "/"), ft_strchr(cmd, '/') + 1);
		if (cmd[0] == '~')
			cmd = ft_strjoin(shell->home, cmd);
		if (cmd[0] == '/')
		{
			path = ft_strdup(cmd);
			ft_bzero(ft_strchr(path, ' '), ft_strlen(ft_strchr(path, ' ')));
		}
	}
	else
		path = ft_fpath(shell, ft_strsub(cmd, 0, ft_len(cmd, ' ')));
	ft_vaccess(cmd, path);
	return (path);
}
