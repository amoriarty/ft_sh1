/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:15:07 by alegent           #+#    #+#             */
/*   Updated: 2015/05/19 10:15:08 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_lst						*ft_nlst(char *entry)
{
	t_lst					*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		ft_sherror(NULL, TRUE);
	new->entry = ft_strdup(entry);
	new->next = NULL;
	return (new);
}
