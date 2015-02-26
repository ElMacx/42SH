/*
** execute_cmd.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Tue Dec 10 11:03:03 2013 Antoine Laffargue
** Last update Tue May 27 20:41:12 2014 aufrere guillaume
*/

#include "mysh.h"

int             check_env(char **cmd, char ***my_env)
{
  char          **pwd;
  char          **home;
  int           ret;

  ret = 0;
  pwd = get_pwd(*my_env);
  home = get_home(*my_env);
  if (cmd[1])
    {
      if (*pwd)
        ret = cd_builtin(cmd, my_env);
      else
        {
          if (!*home)
            create_home(my_env);
          home = get_home(*my_env);
          create_pwd(*home, my_env);
        }
    }
  else
    ret = check_env_2(cmd, my_env, home);
  return (ret);
}

int		builtin_fct(char **cmd, char ***my_env, int mode, int *ret)
{
  if (mode <= 1 && my_strcmp(*cmd, "cd") == 0)
    *ret = check_env(cmd, my_env);
  if (mode <= 1 && my_strcmp(*cmd, "setenv") == 0)
    *ret = setenv_builtin(cmd[1], my_env);
  if (mode <= 1 && my_strcmp(*cmd, "unsetenv") == 0)
    *ret = unsetenv_builtin(cmd[1], my_env);
  if (mode == 2 && my_strcmp(*cmd, "env") == 0)
    *ret = env_builtin(*my_env);
  if (mode == 2 && my_strcmp(*cmd, "echo") == 0)
    *ret = echo_builtin(cmd);
  if (mode >= 1 && my_strcmp(*cmd, "exit") == 0)
    exit_builtin(cmd);
  if (my_strcmp(*cmd, "cd") == 0 ||
      my_strcmp(*cmd, "setenv") == 0 ||
      my_strcmp(*cmd, "unsetenv") == 0 ||
      my_strcmp(*cmd, "env") == 0 ||
      my_strcmp(*cmd, "exit") == 0 ||
      my_strcmp(*cmd, "echo") == 0)
    return (1);
  return (0);
}

char		*create_bin_path(char *cmd, char **path)
{
  int		i;
  char		*bin_path;

  i = 0;
  while (cmd[i] != '\0')
    if (cmd[i++] == '/' && access(cmd, F_OK) == 0)
      return (cmd);
  i = 0;
  while (path && path[i])
    {
      MALLOC_CHECK_INT(bin_path = malloc(my_strlen(path[i])
					 + my_strlen(cmd) + 2));
      my_strcpy(bin_path, path[i]);
      my_strcat(bin_path, "/");
      my_strcat(bin_path, cmd);
      if (access(bin_path, F_OK) == 0)
        return (bin_path);
      i++;
    }
  return (NULL);
}

int		execute_cmd(char **cmd, int *fd, char ***my_env)
{
  char		**path;

  if (cmd[0] == NULL)
    return (0);
  path = get_path(*my_env);
  if (fd[0] != -1)
    if (dup2(fd[0], 0) == -1)
      {
	my_printf_err("error on dup\n");
	exit(1);
      }
  if (fd[1] != -1)
    if (dup2(fd[1], 1) == -1)
      {
	my_printf_err("error on dup\n");
	exit(1);
      }
  exec_fct(path, cmd, my_env);
  if (path)
    {
      free(*path);
      free(path);
    }
  return (0);
}

void		exec_fct(char **path, char **cmd, char ***my_env)
{
  char		*bin_path;
  int		ret;

  if (!builtin_fct(cmd, my_env, 2, &ret))
    {
      if (bin_path = create_bin_path(cmd[0], path))
        {
          execve(bin_path, cmd, *my_env);
          my_printf_err("cannot access '%s'\n", bin_path);
	  ret = 1;
        }
      else
	{
	  my_printf_err("'%s' command not found\n", *cmd);
	  ret = 1;
	}
    }
  else
    exit(ret);
  exit(ret);
}
