/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:35:16 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/07 14:35:17 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		handle_input(t_minishell *mini, char *input)
{
	char	**commands;
	int		ret;

	commands = ft_split_quote(input, ";");
	free(input);
	ret = 0; //à supprimer
	(void)mini; // à supprimer
	//ret = ft_exec_commands(mini, commands);
	ft_putstr_fd("ici handle input\n", 1);// à supprimer
	ft_putstr2(commands); // à supprimer
	return (ret);
}
