/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 12:15:24 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 10:34:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				analyze(t_node *node, char *cmd)
{
	char			*pwd;

	if (!ft_strcmp(cmd, "exit"))
		exit(EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "env", 3))
		ft_env(node->env);
	else if (!ft_strncmp(cmd, "setenv", 6))
		ft_setenv(node, cmd);
	else if (!ft_strncmp(cmd, "unsetenv", 8))
		ft_unsetenv(node, cmd);
	else if (!ft_strncmp(cmd, "cd", 2))
		ft_cd(node, cmd);
	else if (!ft_strcmp(cmd, "pwd"))
	{
		ft_putendl((pwd = getcwd(NULL, 0)));
		free(pwd);
	}
	else if (*cmd)
		ft_sh(node, cmd);
}
