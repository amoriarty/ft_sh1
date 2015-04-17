/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:44:02 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 10:58:52 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_node						*newnode(char **env)
{
	t_node					*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		ft_puterror("42sh", "Not enought RAM space is available");
	new->v_env = env;
	new->path = getpath(env);
	new->env = ft_getenv(env);
	return (new);
}
