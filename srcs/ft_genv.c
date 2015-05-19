/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:13:16 by alegent           #+#    #+#             */
/*   Updated: 2015/05/19 10:13:17 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char					*ft_genv(t_lst *lst, char *entry)
{
	t_lst				*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->entry, entry, ft_len(entry, '=')))
			return (ft_strdup(ft_strchr(tmp->entry, '=') + 1));
		tmp = tmp->next;
	}
	return (NULL);
}
