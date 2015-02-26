/*
** main.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Mon Dec  9 12:13:00 2013 Antoine Laffargue
** Last update Wed May 28 01:29:19 2014 Antoine Laffargue
*/

#include "mysh.h"

int		prepare_redirect(t_exe *exe, int fd[2], char ***my_env)
{
  char		*limit[2];
  int		ret;
  int		i;
  int		double_redir;

  i = 0;
  limit[0] = NULL;
  limit[1] = NULL;
  while (exe->redirect && exe->redirect[i])
    {
      while ((ret = redirect_handler(exe->redirect[i], exe->type[i],
				     &fd, limit)) == -2)
	my_printf_err("could not alloc\n");
      if (ret != -1)
	double_redir = ret;
      i++;
    }
  if (limit[1])
    double_left_redirect(limit, &fd, double_redir);
  execute_cmd(exe->cmd, fd, my_env);
  return (0);
}

int		prepare_pipe_child(t_pipe *p, int fd[2], char ***my_env)
{
  setsid();
  if (p->next)
    if ((fd[0] = prepare_pipe(p->next, my_env)) == -1)
      return (-1);
  if (!p->prev)
    fd[1] = -1;
  prepare_redirect(&(p->exe), fd, my_env);
  exit(1);
}

int		prepare_pipe(t_pipe *p, char ***my_env)
{
  int		pipefd[2];
  int		fd[2];
  int		ret_pid;
  int		status;

  fd[0] = -1;
  if (!p->next && !p->prev)
    builtin_fct(p->exe.cmd, my_env, 1, &(p->exit_status));
  else
    builtin_fct(p->exe.cmd, my_env, 0, &(p->exit_status));
  if (pipe(pipefd) == -1 || (ret_pid = fork()) == -1)
    return (-1);
  fd[1] = pipefd[1];
  if (ret_pid == 0)
    prepare_pipe_child(p, fd, my_env);
  close(pipefd[1]);
  waitpid(ret_pid, &status, WUNTRACED);
  catch_exit_signal(status, p);
  return (pipefd[0]);
}

int		cmd_loop(char *ret, char ***my_env, int *exit_value)
{
  t_sep		*list;
  int		exit_status;

  if (!(list = parsing_fct(ret)))
    return (0);
  replace_var(list, *my_env);
  while (list)
    {
      if (!list->p->next && !list->p->prev &&
	  my_strcmp(list->p->exe.cmd[0], "exit") == 0)
	{
	  if (list->p->exe.cmd[1])
	    *exit_value = my_getnbr(list->p->exe.cmd[1]);
	  return (1);
	}
      prepare_pipe(list->p, my_env);
      exit_status = list->p->exit_status;
      list = list->next;
      if (list && ((list->prev->separator == 40 && exit_status != 0) ||
		   (list->prev->separator == 126 && exit_status == 0)))
	list = list->next;
    }
  return (0);
}

int		main(__attribute__((unused))int ac,
		     __attribute((unused))char **av, char **env)
{
  char		*ret;
  char		**my_env;
  int		exit_value;

  signal(SIGINT, ctrl_c_fct);
  ret = (void *) 1;
  if (!(my_env = get_env(env)))
    {
      while ((my_env = malloc(1 * sizeof(char*))) == NULL)
	my_printf("could not alloc");
      my_env[0] = NULL;
    }
  while (ret)
    {
      exit_value = 0;
      my_putstr("$> ");
      ret = get_next_line(0);
      if (ret)
	if (cmd_loop(ret, &my_env, &exit_value))
	  return (exit_value);
      free(ret);
    }
  return (0);
}
