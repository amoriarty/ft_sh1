/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:46:47 by alegent           #+#    #+#             */
/*   Updated: 2015/05/13 13:43:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include "libft.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# define CANCEL "\033[0;m"
# define GREEN "\033[0;32;40m"
# define CLS 12

typedef struct stat				t_stat;
typedef struct s_node			t_node;
typedef struct s_env			t_env;

struct							s_node
{
	t_env						*env;
	t_env						*path;
	char						*home;
};

struct							s_env
{
	char						*entry;
	t_env						*next;
};

t_node							*newnode(char **env);
t_env							*newenv(void);
t_env							*insertenv(t_env *begin, char *entry);
t_env							*getpath(t_env *env);
t_env							*ft_getenv(char **env);
void							ft_env(t_env *env);
char							*getcmd(char *cmd);
void							ft_sig(int n);
void							analyze(t_node *node, char *cmd);
void							ft_sh(t_node *node, char *cmd);
int								ft_len(char *s, char c);
void							ft_setenv(t_node *node, char *cmd);
void							ft_unsetenv(t_node *node, char *cmd);
void							ft_cd(t_node *node, char *cmd);
char							*gethome(t_env *env);
void							process_error(char *cmd, char *error, int xit);
void							multicmd(t_node *node, char *cmd);
char							*trimcmd(char *cmd);
void							verifcmd(char *s);
void							verifsplit(t_node *node, char **split);
char							*getoldpwd(t_node *node);
int								lstlen(t_env *e);
char							**createenv(t_node *node);
void							ft_free(char **f);

#endif
