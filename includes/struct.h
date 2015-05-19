/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:10:59 by alegent           #+#    #+#             */
/*   Updated: 2015/05/19 10:11:00 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef char						t_bool;
typedef struct stat					t_stat;
typedef struct s_lst					t_lst;
typedef struct s_sh					t_sh;

struct							s_lst
{
	char						*entry;
	t_lst						*next;
};

struct							s_sh
{
	t_lst						*env;
	t_lst						*path;
	char						*home;
};

#endif
