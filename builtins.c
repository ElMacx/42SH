/*
** builtins.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Dec 11 15:02:20 2013 Antoine Laffargue
** Last update Tue May 27 20:21:07 2014 aufrere guillaume
*/

#include "mysh.h"

int	cd_builtin(char **cmd, char ***my_env)
{
  int	i;
  int	i2;
  int	ret;

  i = 0;
  i2 = 0;
  while ((*my_env)[i] && my_strncmp((*my_env)[i], "PWD=", 4) != 0)
    i++;
  while ((*my_env)[i2] && my_strncmp((*my_env)[i2], "HOME=", 5) != 0)
    i2++;
  if ((*my_env)[i] && (*my_env)[i2])
    {
      if (cmd[1] && my_strncmp(cmd[1], "-", 1) == 0)
	ret = move_to_oldpwd(&(*my_env)[i], my_env);
      else if (cmd[1])
	ret = move_to(cmd[1], &(*my_env)[i], my_env);
      else
	ret = move_to(&(*my_env)[i2][5], &(*my_env)[i], my_env);
    }
  else
    {
      my_printf_err("Environment var home or pwd missing\n");
      return (1);
    }
  return (ret);
}

int	env_builtin(char **my_env)
{
  int	i;

  i = 0;
  while (my_env[i])
    {
      my_printf("%s\n", my_env[i]);
      i++;
    }
  return (1);
}

int	setenv_builtin(char *cmd, char ***my_env)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (cmd)
    {
      while (cmd[i] != '\0' && cmd[i] != '=')
	i++;
      if (i != 0 && cmd[i] == '=' && cmd[i + 1] != '\0')
	{
	  while ((*my_env)[i2] && my_strncmp((*my_env)[i2], cmd, i) != 0)
	    i2++;
	  if ((*my_env)[i2])
	    modif_var(cmd, &(*my_env)[i2]);
	  else
	    add_var(cmd, my_env);
	  return (0);
	}
      else
	my_printf_err("Incorrect var, use like this: var_name=var_value\n");
    }
  else
    my_printf_err("setenv: Too few arguments\n");
  return (1);
}

int	unsetenv_builtin(char *cmd, char ***my_env)
{
  int	i;
  int	i2;
  int	size;

  i = 0;
  if (cmd)
    {
      while ((*my_env)[i])
	{
	  i2 = 0;
	  while ((*my_env)[i] && (*my_env)[i][i2] && (*my_env)[i][i2++] != '=');
	  if (my_strncmp((*my_env)[i], cmd, i2 - 1) == 0)
	    {
	      free((*my_env)[i]);
	      (*my_env)[i] = NULL;
	      return (0);
	    }
	  i++;
	}
      size = clean_env(my_env, i);
      *my_env = my_realloc_tab(*my_env, size * sizeof(char *));
    }
  else
    my_printf_err("unsetenv: Too few arguments\n");
  return (1);
}

int	exit_builtin(char **cmd)
{
  if (!cmd[1])
    exit(0);
  else
    exit(my_getnbr(cmd[1]));
}
