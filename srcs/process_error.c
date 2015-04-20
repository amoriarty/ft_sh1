/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:15:10 by alegent           #+#    #+#             */
/*   Updated: 2015/04/18 13:15:15 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void						process_error(char *cmd, char *error, int xit)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(ft_strsub(cmd, 0, ft_len(cmd, ' ')), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
	if (xit == TRUE)
		exit(EXIT_FAILURE);
}
