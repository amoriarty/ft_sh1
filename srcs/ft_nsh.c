#include "ft_sh.h"

t_sh					*ft_nsh(char **env)
{
	t_sh				*new;
	char				*tmp;
	char				**split;

	tmp = NULL;
	split = NULL;
	if (!(new = (t_sh *)malloc(sizeof(t_sh))))
		ft_sherror(NULL, TRUE);
	new->env = ft_glst(env);
	tmp = ft_genv(new->env, "PATH");
	split = ft_strsplit(tmp, ':');
	new->path = ft_glst(split);
	new->home = ft_genv(new->env, "HOME");
	free(tmp);
	ft_fctab(split);
	return (new);
}
