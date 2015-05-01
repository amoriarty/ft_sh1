/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 12:11:55 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 12:11:56 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void			verifsplit(t_node *node, char **split)
{
	int		x;
	int		y;

	y = -1;
	while (split[++y])
	{
		x = -1;
		while (split[y][++x])
		{
			if (split[y][x] == '~')
				split[y] = ft_strjoin(node->home, split[y] + x + 1);
		}
	}
}
