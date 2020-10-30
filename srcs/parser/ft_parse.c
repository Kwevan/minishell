/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:04:56 by kgouacid          #+#    #+#             */
/*   Updated: 2020/10/29 17:23:08 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_quotes(t_minishell *mini, char **word)
{
	int			i;
	t_quotes	quotes;
	char		*res;
	int			len;

	len = ft_strlen_quotes(*word);
	if (!(res = ft_strnew(len + 1)))
		exit_shell(mini, 1);
	len = 0;
	ft_bzero(&quotes, sizeof(t_quotes));
	i = 0;
	while ((*word)[i] && (ft_quote_open(&quotes, (*word)[i]) != 10))
	{
		if (!(!quotes.dq && (*word)[i] == '"')
			&& !(!quotes.q && (*word)[i] == '\'') && !(quotes.bs))
		{
			res[len] = (*word)[i];
			i++;
			len++;
		}
		else
			i++;
	}
	free(*word);
	*word = res;
}

void	replace_var(t_minishell *mini, char *word,
			int var_name_len, char **parsed)
{
	char *var_name;
	char *var;

	var_name = ft_strndup(word, var_name_len);
	var = ft_get_envv(mini, mini->env, var_name);
	*parsed = ft_strjoin(*parsed, var);
	if (!var_name || !*parsed)
		exit_shell(mini, 1);
}

void	ft_add_char(t_minishell *mini, t_quotes *quotes, char c, char **parsed)
{
	int len;

	len = 0;
	(void)mini;
	if (!(quotes->q && c == '"') && !(quotes->dq && c == '\''))
	{
		len = ft_strlen(*parsed);
		*parsed = ft_realloc(*parsed, len + 1, len + 2);
		(*parsed)[len] = c;
	}
}

void	ft_parse_var(t_minishell *mini, t_quotes *quotes, char **word)
{
	int			i;
	int			j;
	char		*parsed;

	parsed = ft_strdup("");
	i = 0;
	while ((*word)[i] && (*word)[i + 1])
	{
		if (!(quotes->dq) && ((quotes->q || !ft_quote_open(quotes, (*word)[i]))
			&& ((*word)[i] == '$')) && ((*word)[i + 1] != '\"'))
		{
			j = ++i;
			while ((*word)[j] && (ft_isalnum((*word)[j])
				|| (ft_index("_?", (*word)[j]) + 1)))
				j++;
			replace_var(mini, (*word) + i, j - i, &parsed);
			i = j;
		}
		else
			ft_add_char(mini, quotes, (*word)[i++], &parsed);
	}
	free(*word);
	*word = parsed;
}

char	**ft_parse(t_minishell *mini, char **words)
{
	int			i;
	t_quotes	quotes;

	ft_bzero(&quotes, sizeof(t_quotes));
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
			ft_parse_var(mini, &quotes, &words[i]);
		ft_remove_quotes(mini, &words[i]);
		i++;
	}
	return (words);
}
