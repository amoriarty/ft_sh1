#include "ft_sh.h"

static void			ft_signal(int n)
{
	if (n == SIGINT)
	{
		ft_putchar(EOL);
		ft_putendl("42sh: SIGINT.");
		ft_putcolor("$> ", GREEN);
	}
	if (n == SIGSEGV)
		ft_sherror("42sh: SIGSEGV.", TRUE);
	if (n == SIGTERM)
		ft_putendl("42sh: SIGTERM.");
	if (n == SIGHUP)
		ft_putendl("42sh: SIGHUP.");
}

void				ft_handler(void)
{
	signal(SIGINT, ft_signal);
	signal(SIGTERM, ft_signal);
	signal(SIGHUP, ft_signal);
	signal(SIGSEGV, ft_signal);
}
