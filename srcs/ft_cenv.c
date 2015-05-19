/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:10:17 by alegent           #+#    #+#             */
/*   Updated: 2015/05/19 10:10:25 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char							**ft_cenv(t_lst *env)
{
	int							i;
	char						**new;
	t_lst						*tmp;

	i = 0;
	tmp = env;
	if (!(new = (char **)malloc(sizeof(char *) + 1)))
		ft_sherror(NULL, TRUE);
	while (tmp)
	{
		new[i++] = ft_strdup(tmp->entry);
		tmp = tmp->next;
	}
	new[i] = 0;
	return (new);
}
