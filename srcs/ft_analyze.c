#include "ft_sh.h"

void					ft_analyze(t_sh *shell, char *cmd)
{
	char				*pwd;

	if (!ft_strcmp(cmd, "exit"))
		exit(EXIT_SUCCESS);
	else if (!ft_strcmp(cmd, "pwd"))
	{
		ft_putendl((pwd = getcwd(NULL, 0)));
		free(pwd);
	}
	else if (!ft_strcmp(cmd, "env"))
		ft_env(shell->env);
	else if (!ft_strncmp(cmd, "setenv", 6))
		ft_senv(shell->env, cmd);
	else if (!ft_strncmp(cmd, "unsetenv", 8))
		ft_uenv(shell->env, cmd);
	else if (!ft_strcmp(cmd, "cd"))
		ft_cd(shell, "cd ~");
	else if (!ft_strncmp(cmd, "cd", 2))
		ft_cd(shell, cmd);
	else
		ft_fork(shell, cmd);
}
