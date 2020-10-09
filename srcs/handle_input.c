/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:16 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/08 16:23:31 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		handle_input(t_minishell *mini)
{
	char	**commands;
	int		ret;

	if (!(commands = ft_split_quote(mini->input, ";")))
		exit_shell(mini);
	free(mini->input);
	ret = get_cmds(mini, commands);
	free(commands);
	return (ret);
}
