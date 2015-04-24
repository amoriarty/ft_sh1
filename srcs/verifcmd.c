/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 14:50:52 by alegent           #+#    #+#             */
/*   Updated: 2015/04/22 14:50:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void						verifcmd(char *s)
{
	int					i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isprint(s[i]) && !ft_isblank(s[i]))
			process_error("Invalid command", "I have to quit.", TRUE);
	}
}
