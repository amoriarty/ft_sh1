/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:49:16 by alegent           #+#    #+#             */
/*   Updated: 2015/05/13 13:46:46 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int							main(int ac, char **av, char **env)
{
	char					*cmd;
	t_node					*e;

	(void)av;
	if (ac != 1)
		ft_puterror("42sh", "usage: ./ft_minishell[n]");
	e = newnode(env);
	while (42)
	{
		signal(SIGINT, ft_sig);
		signal(SIGTERM, ft_sig);
		signal(SIGHUP, ft_sig);
		signal(SIGSEGV, ft_sig);
		cmd = getcmd(NULL);
		verifcmd(cmd);
		if (ft_strchr(cmd, ';'))
			multicmd(e, cmd);
		else
			analyze(e, trimcmd(cmd));
		free(cmd);
	}
	return (EXIT_SUCCESS);
}
