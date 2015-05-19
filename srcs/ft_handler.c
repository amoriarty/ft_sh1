/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:13:23 by alegent           #+#    #+#             */
/*   Updated: 2015/05/19 10:13:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			ft_signal(int n)
{
	if (n == SIGINT)
	{
		ft_putchar(EOL);
		ft_putendl("42sh: SIGINT.");
		ft_putcolor("$> ", GREEN);
	}
	if (n == SIGSEGV)
		ft_sherror("42sh: SIGSEGV.", TRUE);
	if (n == SIGTERM)
		ft_putendl("42sh: SIGTERM.");
	if (n == SIGHUP)
		ft_putendl("42sh: SIGHUP.");
}

void				ft_handler(void)
{
	signal(SIGINT, ft_signal);
	signal(SIGTERM, ft_signal);
	signal(SIGHUP, ft_signal);
	signal(SIGSEGV, ft_signal);
}
