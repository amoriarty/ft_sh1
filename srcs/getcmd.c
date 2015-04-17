/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 11:49:38 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 12:01:36 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char						*getcmd(char *cmd)
{
	char					*next;

	ft_putstr((!cmd) ? "$> " : "> ");
	if ((get_next_line(0, &next) == 0))
		exit(EXIT_SUCCESS);
	if (next[ft_strlen(next) - 1] == '\\')
	{
		next[ft_strlen(next) - 1] = 0;
		return (getcmd(ft_strjoin(cmd, next)));
	}
	return (ft_strjoin(cmd, next));
}
