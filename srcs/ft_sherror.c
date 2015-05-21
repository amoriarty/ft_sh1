/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sherror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:15:52 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 16:35:08 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					ft_sherror(char *error, char *cmd, t_bool i)
{
	if (error)
	{
		ft_putstr_fd("42sh: ", 2);
		if (cmd)
		{
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": ", 2);
		}
		ft_putendl_fd(error, 2);
	}
	if (i == TRUE)
		exit(EXIT_FAILURE);
}
