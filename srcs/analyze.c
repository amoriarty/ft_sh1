/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 12:15:24 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 13:04:12 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				analyze(t_node *node, char *cmd)
{
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
	else if (!ft_strncmp(cmd, "pwd", 3))
		ft_putendl(getcwd(NULL, 0));
	else if (*cmd)
		ft_sh(node, cmd);
}
