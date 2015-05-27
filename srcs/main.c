/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:18:41 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 12:29:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int										main(int ac, char **av, char **env)
{
	t_sh								*sh;
	char								*cmd;
	char								*tmp;

	(void)av;
	cmd = NULL;
	if (ac != 1)
		ft_sherror("please don't feed me !", NULL, TRUE);
	sh = ft_nsh(env);
	ft_handler();
	while (42)
	{
		if (ft_vcmd((cmd = ft_gcmd(NULL))))
		{
			tmp = ft_tcmd(cmd);
			(ft_strchr(cmd, ';')) ? ft_mcmd(sh, cmd) : ft_analyze(sh, tmp);
			if (tmp)
				free(tmp);
		}
		free(cmd);
	}
	return (EXIT_SUCCESS);
}
