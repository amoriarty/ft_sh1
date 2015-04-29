/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getoldpwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:17:03 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 10:18:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char					*getoldpwd(t_node *node)
{
	t_env				*tmp;

	tmp = node->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->entry, "OLDPWD=", 7))
			return (ft_strchr(tmp->entry, '=') + 1);
		tmp = tmp->next;
	}
	return (NULL);
}
