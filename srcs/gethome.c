/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gethome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 16:23:30 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 16:58:08 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				*gethome(t_env *env)
{
	t_env			*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->entry, "HOME", 4))
			return (ft_strchr(tmp->entry, '=') + 1);
		tmp = tmp->next;
	}
	return (NULL);
}
