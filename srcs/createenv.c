#include "ft_sh.h"

char					**createenv(t_node *node)
{
	int				i;
	t_env				*env;
	char				**new;

	i = -1;
	env = node->env;
	if (!(new = (char **)malloc(sizeof(char *) * lstlen(env) + 1)))
		process_error(NULL, "Malloc return an error. I can't create an env variable.", TRUE);
	while (env)
	{
		new[++i] = ft_strdup(env->entry);
		env = env->next;
	}
	new[i] = NULL;
	return (new);
}
