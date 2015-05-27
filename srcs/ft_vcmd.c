/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:18:10 by alegent           #+#    #+#             */
/*   Updated: 2015/05/27 11:57:26 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_bool							ft_vcmd(char *cmd)
{
	int								i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_isprint(cmd[i]) && !ft_isblank(cmd[i]))
		{
			ft_sherror("Invalid command", NULL, FALSE);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
