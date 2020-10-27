

#include "minishell.h"

void	ft_exec_command(t_minishell *mini, char **command)
{
	(void)mini;
	ft_putstr_fd("\n[ starting ft_exec_command ]\n", 1);
	ft_putstr2(command);
	ft_putstr_fd("\n[ end of ft_exec_command ]\n", 1);
}
