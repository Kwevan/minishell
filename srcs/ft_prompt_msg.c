/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:06:43 by kgouacid          #+#    #+#             */
/*   Updated: 2020/11/27 17:34:01 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_editcwd(t_minishell *minishell, char *cwd)
{
	if (minishell->curr_dir)
		free(minishell->curr_dir);
	minishell->curr_dir = ft_strdup(cwd);
}

void	ft_prompt_msg(t_minishell *minishell)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd && minishell->curr_dir)
		cwd = ft_strdup(minishell->curr_dir);
	ft_putstr_fd(cwd, 2);
	ft_putstr_fd(" $ ", 2);
	ft_editcwd(minishell, cwd);
	ft_strdel(&cwd);
}
