/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vaccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:17:55 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 12:46:23 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					ft_vaccess(char *path)
{
	if (!path || access(path, F_OK))
		ft_sherror("Command not found.", TRUE);
	if (!access(path, F_OK) && access(path, X_OK))
		ft_sherror("Permission denied.", TRUE);
}
