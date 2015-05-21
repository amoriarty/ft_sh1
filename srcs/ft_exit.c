/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 12:14:34 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 16:37:07 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					ft_exit(char *cmd)
{
	char				*tmp;
	int				e;

	tmp = NULL;
	if (!ft_strcmp(cmd, "exit"))
		exit(EXIT_SUCCESS);
	else
	{
		tmp = ft_strchr(cmd, ' ') + 1;
		e = ft_atoi(tmp);
		if (!ft_strcmp(tmp, ft_itoa(e)))
			exit(e);
		else
			ft_sherror("Exit can't return this value", tmp, FALSE);
	}
}
