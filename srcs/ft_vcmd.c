/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:18:10 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 16:40:55 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void								ft_vcmd(char *cmd)
{
	int								i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_isprint(cmd[i]) && !ft_isblank(cmd[i]))
			ft_sherror("Invalid command, I have to quit.", cmd, TRUE);
	}
}
