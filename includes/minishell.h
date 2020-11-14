
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
	int			has_pipe;
	int			tube[3];
	int			ret;
	pid_t		pid;
	int			status;
}				t_minishell;

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
**	ENV
*/

void			add_env(t_minishell *minishell, char *var);
void			remove_env(t_minishell *minishell, char *var, int len);

/*
** EXEC
*/

void			ft_exec_commands(t_minishell *mini, char **commands);
void			ft_exec_command(t_minishell *mini, char **command);
int				exec_bin(t_minishell *minishell, char **command);
int				exec_builtin(t_minishell *minishell, char **command);
char			*ft_get_bin_path(t_minishell *mini, char *bin);

/*
**	BUILTINS
*/

void			ft_pwd(t_minishell *mini);
void			ft_echo(char **cmd);
void			ft_exit(t_minishell *mini, char **args);
void			ft_cd(t_minishell *minishell, char **cmd);

/*
**  PARSER
*/

char			**ft_parse(t_minishell *mini, char **words);
int				ft_strlen_quotes(char *word);

/*
**  REDIR
*/

int				ft_pipe_redir(t_minishell *mini, char *cmd);
int				ft_is_pipe_or_redir(char *cmd);
int				ft_redir(t_minishell *mini, char *cmd, int *fd_in, int last);
int				ft_exec_redir(t_minishell *mini, int fd, char *redir_fname, char *cmd);


/*
**	UTILS
*/

void			exit_shell(t_minishell *minishell, int status);
char			*ft_get_envv(t_minishell *mini, char **env, char *var);
int				ft_countstrarr(char **arr);
char			*ft_removequotes(char *str);
void			ft_close(int fd);

#endif
