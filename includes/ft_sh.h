/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:46:47 by alegent           #+#    #+#             */
/*   Updated: 2015/04/29 10:19:15 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include "libft.h"
# include "struct.h"
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# define CANCEL "\033[0;m"
# define GREEN "\033[0;32;40m"

char					*ft_genv(t_lst *lst, char *entry);
char					**ft_cenv(t_lst *env);
char					*ft_gpath(t_sh *shell, char *cmd);
char					*ft_gcmd(char *cmd);
char					*ft_tcmd(char *cmd);
void					ft_inode(t_lst **lst, char *entry);
void					ft_vcmd(char *cmd);
void					ft_fctab(char **tab);
void					ft_mcmd(t_sh *shell, char *cmd);
void					ft_fork(t_sh *shell, char *cmd);
void					ft_vaccess(char *path);
void					ft_vsplit(t_sh *shell, char **split);
void					ft_analyze(t_sh *shell, char *cmd);
void					ft_sherror(char *error, t_bool i);
void					ft_env(t_lst *env);
void					ft_senv(t_lst *env, char *cmd);
void					ft_uenv(t_lst *env, char *cmd);
void					ft_cd(t_sh *shell, char *cmd);
void					ft_handler(void);
size_t					ft_len(char *entry, char c);
size_t					ft_lstlen(t_lst *lst);
t_sh					*ft_nsh(char **env);
t_lst					*ft_nlst(char *entry);
t_lst					*ft_glst(char **from);

#endif
