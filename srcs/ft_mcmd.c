/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:14:45 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 13:31:56 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void								ft_mcmd(t_sh *shell, char *cmd)
{
	int								i;
	char							**split;

	i = -1;
	split = ft_strsplit(cmd, ';');
	while (split[++i])
		ft_analyze(shell, ft_tcmd(split[i]));
	ft_fctab(split);
}
