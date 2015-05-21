/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vaccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:17:55 by alegent           #+#    #+#             */
/*   Updated: 2015/05/21 17:31:15 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					ft_vaccess(char *cmd, char *path)
{
	if (!access(path, F_OK) && access(path, X_OK))
		ft_sherror("Permission denied.", cmd, TRUE);
	if (!path || access(path, F_OK))
		ft_sherror("Command not found.", cmd, TRUE);
}
