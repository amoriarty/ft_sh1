#include "ft_sh.h"

void					ft_vaccess(char *path)
{
	if (!access(path, F_OK) && access(path, X_OK))
		ft_sherror("Permission denied.", TRUE);
	if (access(path, F_OK))
		ft_sherror("Command not found.", TRUE);
}
