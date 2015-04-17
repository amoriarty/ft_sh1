/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:49:51 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 10:49:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_env						*newenv(void)
{
	t_env					*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		ft_puterror("42sh", "Not enought RAM space is available.");
	new->entry = NULL;
	new->next = NULL;
	return (new);
}
