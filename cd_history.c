/*
** cd_history.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Apr 28 23:25:36 2014 Antoine Laffargue
** Last update Tue Apr 29 17:08:57 2014 Antoine Laffargue
*/

#include "mysh.h"

int	set_oldpwd(char *pwd, char ***my_env)
{
  char	*oldpwd;

  if ((oldpwd = malloc(my_strlen(pwd) + 4)) == NULL)
    {
      my_printf_err("could not alloc\n");
      return (0);
    }
  my_strcpy(oldpwd, "OLD");
  my_strcat(oldpwd, pwd);
  setenv_builtin(oldpwd, my_env);
  return (0);
}

int	move_to_oldpwd(char **pwd, char ***my_env)
{
  int	i;
  char	*path;

  while ((*my_env)[i] && my_strncmp((*my_env)[i], "OLDPWD=", 7) != 0)
    i++;
  if ((*my_env)[i])
    {
      if ((path = malloc(my_strlen(&(*my_env)[i][7]) + 1)) == NULL)
	{
	  my_printf_err("could_not alloc");
	  return (1);
	}
      my_strcpy(path, &(*my_env)[i][7]);
      my_printf("%s\n", &(*my_env)[i][7]);
      move_to(path, pwd, my_env);
    }
  else
    my_printf_err("cd: OLDPWD not set\n");
  return (0);
}
