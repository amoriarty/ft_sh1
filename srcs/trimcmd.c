/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:15:24 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 13:15:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char								*trimcmd(char *cmd)
{
	int								i;
	char							*new;
	static int						begin;

	i = 0;
	new = ft_strnew(ft_strlen(cmd) + 1);
	while (*cmd && ft_isblank(*cmd))
		cmd++;
	if (begin == 0)
		begin++;
	else
		new[i++] = ' ';
	while (*cmd && ft_isprint(*cmd))
		new[i++] = *(cmd++);
	if (*cmd)
		return (ft_strjoin(new, trimcmd(cmd)));
	begin = 0;
	return (new);
}
