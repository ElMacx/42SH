/*
** mysh.h for mysh in /home/laffar_a/rendu/PSU_2013_minishell1/include
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Tue Dec 10 11:32:21 2013 Antoine Laffargue
** Last update Wed May 28 01:46:26 2014 Antoine Laffargue
*/

#ifndef _MYSH_H_
# define _MYSH_H_

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include "my.h"
#include "get_next_line.h"

# define MALLOC_CHECK(x) if(!(x)) { my_printf_err("could not alloc"); return (NULL); }
# define MALLOC_CHECK_INT(x) if(!(x)) { my_printf_err("could not alloc"); return (0); }
# define DEFAULT        "\033[0m"
# define HIGHLIGHT      "\033[1m"
# define BLINK          "\033[5m"
# define BLACK          "\033[30m"
# define WHITE          "\033[37m"
# define RED            "\033[31m"
# define BLUE           "\033[34m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define PURPLE         "\033[35m"

typedef struct		s_exe
{
  char			**cmd;
  char			**redirect;
  int			*type;
}			t_exe;

typedef struct		s_alia
{
  int			count;
}			t_alias;


typedef struct		s_pipe
{
  int			exit_status;
  struct s_exe		exe;
  struct s_pipe		*next;
  struct s_pipe		*prev;
}			t_pipe;

typedef struct		s_sep
{
  char			separator;
  struct s_pipe		*p;
  struct s_sep		*next;
  struct s_sep		*prev;
}			t_sep;

int		*g_pid;
int		g_current;

/* main.c */
int		cmd_loop(char *ret, char ***my_env, int *exit_value);
int		prepare_pipe(t_pipe *pipe, char ***my_env);
int		prepare_redirect(t_exe *exe, int fd[2], char ***my_env);
int		prepare_pipe_child(t_pipe *pipe, int fd[2], char ***my_env);

/* execute_cmd.c */
int		execute_cmd(char **cmd, int *fd, char ***my_env);
int		builtin_fct(char **cmd, char ***my_env, int mode, int *ret);
int		check_env(char **cmd, char ***my_env);
void		free_path(char **path);
void		exec_fct(char **path, char **cmd, char ***my_env);

/* redirect.c */
int		right_redirect(char *file, int type);
int		redirect_handler(char *str, int type, int **fd, char *limit[2]);
int		simple_left_redirect(char *file);
int		double_left_redirect(char *limit[2], int **fd, int mode);
int		double_left_redirect_fork(char *final, int **fd);

/* env.c */
char		**get_env(char **env);
char		**get_path(char **my_env);
char		**get_pwd(char **my_env);
char		**get_home(char **my_env);
int		clean_env(char ***my_env, int env_size);

/* replace_var.c */
void		replace_var(t_sep *list, char **my_env);
char		*find_var(char *str, char **my_env);
char		*get_var_name(char *str, char **my_env);
char		*create_string(char *str, char *var, int i, int i2);

/* builtins.c */
int		cd_builtin(char **cmd, char ***my_env);
int		env_builtin(char **my_env);
int		setenv_builtin(char *cmd, char ***my_env);
int		unsetenv_builtin(char *cmd, char ***my_env);
int		exit_builtin(char **cmd);

/* echo_builtin.c */
int		echo_builtin(char **cmd);
int		get_mode(char *str);
int		write_string(char *str, int mode);
char		get_char_value(char *str);
void		echo_help();

/* cd_tools.c */
int		move_to(char *path, char **pwd, char ***my_env);
int		modif_pwd(char *path, char **pwd);
int		create_pwd(char *home, char ***my_env);
int		create_home(char ***my_env);
int		set_home(char *home, char ***my_env);

/* cd_history.c */
int		set_oldpwd(char *pwd, char ***my_env);
int		move_to_oldpwd(char **pwd, char ***my_env);

/* setenv_tools.c */
int		add_var(char *cmd, char ***my_env);
int		modif_var(char *cmd, char **var);

/* signal_tools.c */
void		ctrl_c_fct();
void		catch_exit_signal_2(int status, t_pipe *p);
void		catch_exit_signal(int status, t_pipe *p);

/* parsing.c */
t_sep		*parsing_fct(char *ret);
t_pipe          *create_pipe(char *str);
int             pipe_split(char *str, int i);
int             sep_split(char *str, int i, int *separator);

/* parsing_exe.c */
void		complete_exe_struct(t_exe *exe, char *str);
int             get_redirect(t_exe *exe, int *t_len, char *str, int type);
int             get_cmd(t_exe *exe, int *c_len, char *str);
int             is_stop_char(char *str);

/* list_tools.c */
t_sep           *add_sep(t_sep *list, t_pipe *pipe, int separator);
t_pipe          *add_pipe(t_pipe *list);

/* error.c */
int		check_cd_error(char *path);

/* parsing_error.c */
int		check_token_error(char *str);
void		token_error(char *token, int token_len);
int		is_token(char *str);
void		update_var(char c, int token_len, int *text);

/* is_command.c */
char		*is_command(int, char *, char **);
char		*check_validity(char *, char **);
char		*make_final(char *, char *);

/* cd_tools_2.c */
int             check_env_2(char **cmd, char ***my_env, char **home);

#endif /* _MYSH_H_ */
