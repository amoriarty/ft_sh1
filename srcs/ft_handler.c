/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:13:23 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 16:38:51 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			ft_signal(int n)
{
	if (n == SIGINT)
	{
		ft_putchar(EOL);
		ft_putendl_fd("42sh: SIGINT.", 2);
		ft_putcolor("$> ", GREEN);
	}
	if (n == SIGSEGV)
		ft_sherror("42sh: SIGSEGV.", NULL, TRUE);
	if (n == SIGTERM)
		ft_putendl_fd("42sh: SIGTERM.", 2);
	if (n == SIGHUP)
		ft_putendl_fd("42sh: SIGHUP.", 2);
}

void				ft_handler(void)
{
	signal(SIGINT, ft_signal);
	signal(SIGTERM, ft_signal);
	signal(SIGHUP, ft_signal);
	signal(SIGSEGV, ft_signal);
}
