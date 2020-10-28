/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:16 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/27 19:38:31 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		handle_input(t_minishell *mini)
{
	char	**commands;
	int		ret;

	ret = 0;
	if (!(commands = ft_split_quote(mini->input, ";")))
		exit_shell(mini);
	free(mini->input);
	ft_exec_commands(mini, commands);
	return (ret);
}
