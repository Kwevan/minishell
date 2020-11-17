/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:23:30 by kwe               #+#    #+#             */
/*   Updated: 2020/11/17 22:10:58 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_exec_redir2(t_minishell *mini, char **parsed)
{
		char *bin_path;

      bin_path = NULL;
      if (!exec_builtin(mini, parsed))
     {
         bin_path = ft_get_bin_path(mini, parsed[0]);
          if ((execve(bin_path, parsed, mini->env)) == -1)
              ft_putendl_fd(strerror(errno), 2);
          ft_strdel(&bin_path);
      }
 }

int	ft_exec_redir(t_minishell *mini, int std[2], char *cmd)
{
	mini->pid = fork();
	if (mini->pid == -1)
		ft_putstr_fd("Error: fork", 2);
	else if (mini->pid == 0)
	{
		dup2(std[0], STDIN_FILENO);
		dup2(std[1], STDOUT_FILENO);
		char **splitted = ft_split_quote(cmd, " ");
		char **parsed = ft_parse(mini, splitted);
		ft_exec_redir2(mini, parsed);
		ft_freestrarr(parsed);
		exit(EXIT_SUCCESS);
	}
	else
		wait(&mini->pid);
	return (0);
}
