/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:36:42 by afoulqui          #+#    #+#             */
/*   Updated: 2020/10/28 16:42:30 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** -----------------
**     LIBRAIRIES
** -----------------
*/

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

/*
** -----------------
**     STRUCTURES
** -----------------
*/

typedef struct	s_minishell
{
	char		**env;
	char		*input;
	int			has_pipe;
	int			tube[3];
	int			ret;
	pid_t		pid;
	int			status;
}				t_minishell;

typedef struct	s_cmd
{
	char		**args;
	char		*cmd;
	int			argc;
}				t_cmd;

/*
** -----------------
**     FUNCTIONS
** -----------------
*/

/*
**	ROOT
*/

void			ft_prompt_msg(t_minishell *mini);
void			get_input(t_minishell *mini);
int				handle_input(t_minishell *mini);

/*
**	COMMANDS
*/

void			get_cmds(char **commands);
t_cmd			*parse_pipe_cmds(char *cmd);
t_cmd			parse_pieces_cmds(char *cmd);

/*
** EXEC
*/

void			ft_exec_commands(t_minishell *mini, char **commands);
void			ft_exec_command(t_minishell *mini, char **command);
int				exec_bin(t_minishell *minishell, char **command);
int				exec_builtin(t_minishell *minishell, char **command);

/*
**	BUILTINS
*/

void			ft_pwd(t_minishell *mini);
void			ft_echo(char **cmd);


/*
**  PARSER
*/

char			**ft_parse(t_minishell *mini, char **words);
int				ft_strlen_quotes(char *word);

/*
**  REDIR
*/

void			ft_pipe_redir(t_minishell *mini, char **cmd);

/*
**	UTILS
*/

void			exit_shell(t_minishell *minishell);
char			*ft_get_envv(t_minishell *mini, char **env, char *var);
int				ft_countstrarr(char **arr);
char			*ft_removequotes(char *str);

#endif
