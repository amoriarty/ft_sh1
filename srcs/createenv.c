/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:38:20 by alegent           #+#    #+#             */
/*   Updated: 2015/05/13 13:38:54 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char					**createenv(t_node *node)
{
	int					i;
	t_env				*env;
	char				**new;

	i = -1;
	env = node->env;
	if (!(new = (char **)malloc(sizeof(char *) * lstlen(env) + 1)))
		process_error(NULL, "Malloc return an error.", TRUE);
	while (env)
	{
		new[++i] = ft_strdup(env->entry);
		env = env->next;
	}
	new[i] = NULL;
	return (new);
}
