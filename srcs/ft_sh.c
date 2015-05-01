/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 12:17:35 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 11:07:20 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char						*findpath(t_node *node, char *cmd)
{
	char						*tmp;
	t_env						*path;

	tmp = NULL;
	path = node->path;
	while (path)
	{
		tmp = ft_strjoin(ft_strjoin(path->entry, "/"), cmd);
		if (!access(tmp, F_OK) && !access(tmp, X_OK))
			return (tmp);
		if (!access(tmp, F_OK) && access(tmp, X_OK))
			process_error(cmd, "Permission denied.", TRUE);
		path = path->next;
	}
	return (NULL);
}

static char						*currentdir(char *cmd)
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
	char						**env;
	char						**split;
	pid_t						pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (cmd[0] == '.')
			path = currentdir(ft_strchr(cmd, '/') + 1);
		else
			path = findpath(node, ft_strsub(cmd, 0, ft_len(cmd, ' ')));
		split = ft_strsplit(cmd, ' ');
		verifsplit(node->env, split);
		if (!path || execve(path, split, (env = createenv(node))) == ERROR)
			process_error(cmd, "Command not found.", TRUE);
		ft_free(split);
		ft_free(env);
	}
}
