/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:13:23 by alegent           #+#    #+#             */
/*   Updated: 2015/05/23 17:22:37 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void			ft_signal(int n)
{
	if (n == SIGINT)
	{
		ft_putendl_fd("\n42sh: SIGINT.", 2);
		ft_putcolor("$> ", GREEN);
	}
	if (n == SIGSEGV)
		ft_sherror("42sh: SIGSEGV.", NULL, TRUE);
	if (n == SIGTERM)
		ft_putendl_fd("42sh: SIGTERM.", 2);
	if (n == SIGQUIT)
	{
		ft_putendl_fd("\n42sh: SIGQUIT.", 2);
		ft_putcolor("$> ", GREEN);
	}
}

void				ft_handler(void)
{
	signal(SIGINT, ft_signal);
	signal(SIGTERM, ft_signal);
	signal(SIGSEGV, ft_signal);
	signal(SIGQUIT, ft_signal);
}
