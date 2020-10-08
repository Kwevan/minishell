/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:56:24 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/07 16:43:01 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_commands(t_minishell *minishell)
{
	int		i;
	char	**splitted_cmds;
	char	**new_cmds;

	new_cmds = NULL;
	i = 0;
	while(minishell->commands[i])
	{
		if (strchr(minishell->commands[i], "|"))
		{
			new_cmds = ft_split(minishell->commands[i], "|");
			ft_putstr_fd("there's some pipes", 1);
		}
		if (strchr(minishell->commands[i], ">") || strchr(minishell->commands[i], "<"))
			ft_putstr_fd("there's some redirections", 1);
		else 
			
		
	}
}