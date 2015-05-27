/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:11:11 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 14:26:48 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					ft_fork(t_sh *shell, char *cmd)
{
	char				*path;
	char				**env;
	char				**split;
	pid_t				pid;

	if ((pid = fork()) == ERROR)
		ft_sherror(NULL, NULL, FALSE);
	else if (pid == 0)
	{
		if (cmd[0] == '/')
		{
			path = ft_strsub(cmd, 0, ft_len(cmd, ' '));
			cmd = ft_strrchr(path, '/');
		}
		ft_vsplit(shell, (split = ft_strsplit(cmd, ' ')));
		if (!(path = (cmd[0] != '/') ? ft_gpath(shell, cmd) : path)
				|| (execve(path, split, (env = ft_cenv(shell->env))) == -1))
			ft_sherror("Command not found.", cmd, TRUE);
	}
	else
		wait(NULL);
}
