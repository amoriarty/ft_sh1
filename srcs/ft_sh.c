/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 12:17:35 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 10:30:39 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char						*findpath(t_node *node, char *cmd)
{
	int							i;
	char						*tmp;

	i = -1;
	tmp = NULL;
	while (node->path && node->path[++i])
	{
		tmp = ft_strjoin(ft_strjoin(node->path[i], "/"), cmd);
		if (!access(tmp, F_OK) && !access(tmp, X_OK))
			return (tmp);
		if (!access(tmp, F_OK) && access(tmp, X_OK))
			process_error(cmd, "Permission denied.", TRUE);
	}
	return (NULL);
}

static char						*minimal(char *cmd)
{
	char						*path;

	path = ft_strjoin(ft_strjoin(getcwd(NULL, 0), "/"), cmd);
	if (!access(path, F_OK) && !access(path, X_OK))
		return (path);
	if (!access(path, F_OK) && access(path, X_OK))
		process_error(cmd, "Permission denied.", TRUE);
	process_error(cmd, "No such file or directory", TRUE);
	return (NULL);
}

void							ft_sh(t_node *node, char *cmd)
{
	char						*path;
	char						**split;
	pid_t						pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (cmd[0] == '.')
			path = minimal(ft_strchr(cmd, '/') + 1);
		else
			path = findpath(node, ft_strsub(cmd, 0, ft_len(cmd, ' ')));
		split = ft_strsplit(cmd, ' ');
		verifsplit(node->env, split);
		if (!path || execve(path, split, node->v_env) == ERROR)
			process_error(cmd, "Command not found.", TRUE);
		free(cmd);
	}
}
