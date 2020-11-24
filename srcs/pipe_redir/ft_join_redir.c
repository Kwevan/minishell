/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:16:48 by kwe               #+#    #+#             */
/*   Updated: 2020/11/23 15:26:27 by kwe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_minishell(t_minishell *mini, char *cmd, t_redir *redir)
{
	ft_strdel(&redir->redir_fname);
	ft_strdel(&redir->redir_cmd);
	ft_strdel(&cmd);
	ft_putendl_fd("Error malloc", 2);
	exit_shell(mini, 1);
}

void	ft_join_redir(t_minishell *mini, t_redir *redir2, char *redir, int max)
{
	int		i;
	char	*to_join;
	char	*new;

	i = 0;
	while (redir[i] && (redir[i] == ' '))
		i++;
	while (redir[i] && redir[i] != ' ')
		i++;
	if (redir[i] == '\0')
		return ;
	to_join = ft_strndup(redir + i, max - redir2->start - i);
	if (!to_join && ((max - redir2->start - i) > 0))
		end_minishell(mini, redir, redir2);
	new = ft_strjoin(redir2->redir_cmd, to_join);
	if (!new)
		end_minishell(mini, redir, redir2);
	ft_strdel(&redir2->redir_cmd);
	redir2->redir_cmd = new;
	ft_strdel(&to_join);
}
