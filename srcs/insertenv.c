/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:50:27 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 10:50:36 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_env						*insertenv(t_env *begin, char *entry)
{
	t_env					*new;
	t_env					*tmp;

	new = newenv();
	new->entry = ft_strdup(entry);
	if (!begin)
		return (new);
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (begin);
}
