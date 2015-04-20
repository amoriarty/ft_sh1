/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:14:48 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 13:15:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void							multicmd(t_node *node, char *cmd)
{
	int							i;
	char						**split;

	i = -1;
	split = ft_strsplit(trimcmd(cmd), ';');
	while (split[++i])
		analyze(node, trimcmd(split[i]));
}
