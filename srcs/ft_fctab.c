/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:10:47 by alegent           #+#    #+#             */
/*   Updated: 2015/05/19 10:10:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void									ft_fctab(char **tab)
{
	int									i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}
