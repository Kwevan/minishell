/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:21:50 by kwe               #+#    #+#             */
/*   Updated: 2020/12/03 12:38:51 by kwe              ###   ########.fr       */
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
	char		**commands;
	char		*curr_dir;
	int			has_pipe;
	int			tube[3];
	int			pipe[2];
	int			pipe_err;
	int			ret;
	pid_t		pid;
	int			pcount;
	int			*pids;
}				t_minishell;

typedef struct	s_redir
{
	char		*redir_cmd;
	char		*redir_fname;
	int			redir;
	int			start;
	int			type;
}				t_redir;

/*
** -----------------
**     FUNCTIONS
** -----------------
*/

/*
**	ROOT
*/

void			ft_prompt_msg(t_minishell *minishell);
void			ft_editcwd(t_minishell *minishell, char *cwd);
void			get_input(t_minishell *mini);
void			handle_input(t_minishell *mini);
void			handle_signal(void);

/*
**	ENV
*/

void			add_env(t_minishell *minishell, char *var);
void			remove_env(t_minishell *minishell, char *var);
int				get_env_index(t_minishell *minishell, char *var);
int				ft_isenv(t_minishell *minishell, char *var);
int				check_equality(char *var);
int				ft_isvalidenv(char *env);
void			print_sortenv(t_minishell *minishell);
int				check_plus(char *var);

/*
** EXEC
*/

void			ft_exec_commands(t_minishell *mini);
void			ft_exec_command(t_minishell *mini, char **command);
void			exec_bin(t_minishell *minishell, char **command);
int				exec_builtin(t_minishell *minishell, char **command);
char			*ft_get_bin_path(t_minishell *mini, char *bin);
int				print_errorcmd(char *cmd, int code);

/*
**	BUILTINS
*/

void			ft_pwd(t_minishell *mini);
void			ft_echo(t_minishell *minishell, char **cmd);
void			ft_exit(t_minishell *mini, char **args);
void			ft_cd(t_minishell *minishell, char **cmd);
void			ft_env(t_minishell *minishell);
void			ft_unset(t_minishell *minishell, char **cmd);
void			ft_export(t_minishell *minishell, char **cmd);

/*
**  PARSER
*/

char			**ft_parse(t_minishell *mini, char **words);
int				ft_strlen_quotes(char *word);
void			ft_del_string(char ***p, int i);

/*
**  REDIR
*/

int				ft_pipe_redir(t_minishell *mini, char *cmd);
int				ft_is_pipe_or_redir(char *cmd);
int				ft_check_pipe(t_minishell *mini, char *cmd);
int				ft_redir(t_minishell *mini, char *cmd, int *fd_in);
int				ft_exec_redir(t_minishell *mini, t_redir *redir, int *fd_in);
int				ft_redir_type(char c, char d, int *type, int *i);
int				get_fd(int type, char *fname, t_minishell *mini, int close);
void			ft_join_redir(t_minishell *mini,
					t_redir *redir2, char *redir, int max);
void			ft_add_process(t_minishell *m);

/*
**	UTILS
*/

void			exit_shell(t_minishell *minishell, int status);
char			*ft_get_envv(t_minishell *mini, char **env, char *var);
int				ft_countstrarr(char **arr);
char			*ft_removequotes(char *str);
void			ft_close(int fd);
char			*ft_remove_space(char *str);
int				ft_isallspace(char *s);

void			handle_ctrl_bl(int signal);

#endif
