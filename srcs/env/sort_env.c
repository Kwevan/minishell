/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:41:05 by afoulqui          #+#    #+#             */
/*   Updated: 2020/11/17 17:41:55 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sort_env(char **env, int len)
{
	int		ord;
	int		i;
	char	*tmp;

	ord = 0;
	while (env && ord == 0)
	{
		ord = 1;
		i = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
				ord = 0;
			}
			i++;
		}
		len--;
	}
}

void		print_sortenv(t_minishell *minishell)
{
	int		i;
	int		j;
	int		argc;
	char	**tmp;

	argc = ft_countstrarr(minishell->env);
	tmp = (char **)ft_calloc(sizeof(char *), argc + 1);
	i = 0;
	j = 0;
	while (i < argc)
	{
		tmp[j] = ft_strdup(minishell->env[i]);
		i++;
		j++;
	}
	sort_env(tmp, ft_countstrarr(tmp));
	i = 0;
	while (i < argc)
	{
		ft_putstr_fd(tmp[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	ft_freestrarr(tmp);
	minishell->ret = 0;
}