/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:06:43 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/07 14:27:49 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt_msg(t_minishell *mini)
{
	char	*cwd;

	cwd = ft_get_envv(mini->env, "PWD");
	if (cwd)
	{
		ft_putstr_fd(cwd, 2);
		ft_putstr_fd(" $ ", 2);
	}
}
