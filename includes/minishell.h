/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:36:42 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/07 14:23:19 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ----------------- */
/*     LIBRAIRIES    */
/* ----------------- */

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include "libft.h"

/* ----------------- */
/*     STRUCTURES    */
/* ----------------- */

typedef struct	s_minishell
{
	char		**env;
	int			has_pipe;
	int			tube[3];
	int			ret;
}				t_minishell;

/* ----------------- */
/*     FUNCTIONS     */
/* ----------------- */

/*
**	ROOT
*/

void	ft_prompt_msg(t_minishell *mini);
char	*get_input(t_minishell *mini);
int		handle_input(t_minishell *mini, char *input);

/*
**	BUILTINS
*/

void	ft_pwd(t_minishell *mini);

/*
**	UTILS
*/

void	exit_shell(t_minishell *minishell);
char	*ft_get_envv(char **env, char *var);

#endif
