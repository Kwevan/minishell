/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:36:42 by afoulqui          #+#    #+#             */
/*   Updated: 2020/09/30 17:56:44 by afoulqui         ###   ########.fr       */
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
}				t_minishell;

/* ----------------- */
/*     FUNCTIONS     */
/* ----------------- */

/*
**	UTILS 
*/

void	exit_shell(t_minishell *minishell);
void	ft_freestrarr(char **arr);

#endif