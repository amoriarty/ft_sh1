/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 13:08:19 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 13:10:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					ft_flst(t_lst *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ft_flst(lst->next);
	free(lst->entry);
	free(lst);
	lst = NULL;
}
