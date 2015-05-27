/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:15:58 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 11:48:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char									*ft_tcmd(char *cmd)
{
	int									i;
	int									x;
	char								*new;
	static int							begin;

	i = 0;
	x = 0;
	new = ft_strnew(ft_strlen(cmd) + 1);
	while (cmd[i] && ft_isblank(cmd[i]))
		i++;
	(begin) ? new[x++] = ' ' : begin++;
	while (cmd[i] && ft_isprint(cmd[i]))
		new[x++] = cmd[i++];
	if (cmd[i])
		return (ft_strjoin(new, ft_tcmd(cmd + i)));
	begin = 0;
	return (new);
}
