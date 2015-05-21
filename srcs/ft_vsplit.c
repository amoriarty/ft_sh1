/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:18:23 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 16:41:12 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void								ft_vsplit(t_sh *shell, char **split)
{
	int								x;
	int								y;

	y = -1;
	if (!split)
		ft_sherror(NULL, NULL, TRUE);
	while (split[++y])
	{
		x = -1;
		while (split[y][++x])
		{
			if (split[y][x] == '~')
				split[y] = ft_strjoin(shell->home, split[y] + x + 1);
		}
	}
}
