/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:16 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/07 15:59:34 by kgouacid         ###   ########.fr       */
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
	ret = 0; //à supprimer
	(void)mini; // à supprimer
	//ret = ft_exec_commands(mini, commands);
	ft_putstr_fd("ici handle input\n", 1);// à supprimer
	ft_putstr2(commands); // à supprimer
	free(commands);
	return (ret);
}
