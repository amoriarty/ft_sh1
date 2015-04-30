/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 12:05:23 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 12:05:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				ft_sig(int n)
{
	ft_putchar(EOL);
	if (n == SIGSEGV)
		ft_putstr_fd("42sh: Segmentation Fault.", 2);
	if (n == SIGINT)
	{
		ft_putstr_fd("42sh: Interruption.\n", 2);
		ft_putcolor("$>", GREEN);
	}
	if (n == SIGTERM)
		ft_putstr_fd("42sh: Terminated.", 2);
	ft_putchar((n == SIGINT) ? ' ' : EOL);
}
