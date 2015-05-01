/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:53:54 by alegent           #+#    #+#             */
/*   Updated: 2015/04/14 11:43:50 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_env							*ft_getenv(char **env)
{
	int							i;
	t_env						*new;

	i = -1;
	new = NULL;
	while (env[++i])
		new = insertenv(new, env[i]);
	return (new);
}
