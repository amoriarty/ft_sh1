#include "ft_sh.h"

void					ft_fork(t_sh *shell, char *cmd)
{
	char				*path;
	char				**env;
	char				**split;
	pid_t				pid;

	if ((pid = fork()) == ERROR)
		ft_sherror(NULL, FALSE);
	else if (pid == 0)
	{
		ft_vsplit(shell, (split = ft_strsplit(cmd, ' ')));
		if (!(path = ft_gpath(shell, cmd))
				|| (execve(path, split, (env = ft_cenv(shell->env))) == -1))
			ft_sherror("Command not found.", TRUE);
	}
	else
		wait(NULL);
}
