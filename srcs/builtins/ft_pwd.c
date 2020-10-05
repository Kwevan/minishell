/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:52:03 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/05 13:13:23 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_minishell *mini)
{
	char	*cwd;

	cwd = ft_get_envv(mini->env, "PWD");
	if (cwd)
	{
		ft_putendl_fd(cwd, 1);
		mini->ret = 0;
	}
	else
		mini->ret = 1;
}
