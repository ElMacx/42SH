/*
** env.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Tue Dec 10 11:29:36 2013 Antoine Laffargue
** Last update Sun May 25 20:34:44 2014 maxime dulin
*/

#include "mysh.h"

char	**get_env(char **env)
{
  int	i;
  char	**my_env;

  i = 0;
  if (*env)
    {
      while (env[i++]);
      MALLOC_CHECK(my_env = malloc(i * sizeof(char *)));
      my_env[--i] = NULL;
      while (i != 0)
	{
	  MALLOC_CHECK(my_env[i - 1] = malloc(my_strlen(env[i - 1]) + 1));
	  my_strcpy(my_env[i - 1], env[i - 1]);
	  i--;
	}
      return (my_env);
    }
  else
    my_printf_err("[Warning]: Running without environnement !\n");
  return (NULL);
}

char	**get_path(char **my_env)
{
  char	**path;
  char	*path_str;
  int	i;

  i = 0;
  while (my_env[i] && my_strncmp(my_env[i], "PATH=", 5) != 0)
    i++;
  if (my_env[i])
    {
      MALLOC_CHECK(path_str = malloc(my_strlen(my_env[i]) + 1));
      my_strcpy(path_str, &my_env[i][5]);
      path = my_str_to_wordtab(path_str, ':', -1);
      return (path);
    }
  return (NULL);
}

char	**get_pwd(char **my_env)
{
  int   i;

  i = 0;
  while (my_env[i] && my_strncmp(my_env[i], "PWD=", 4) != 0)
    i++;
  return (&my_env[i]);
}

char	**get_home(char **my_env)
{
  int   i;

  i = 0;
  while (my_env[i] && my_strncmp(my_env[i], "HOME=", 5) != 0)
    i++;
  return (&my_env[i]);
}

int	clean_env(char ***my_env, int env_size)
{
  int	size;
  int	i;

  size = 0;
  i = 0;
  while (i < env_size)
    {
      if (!(*my_env)[i])
	{
	  (*my_env)[i] = (*my_env)[i + 1];
	  (*my_env)[i + 1] = NULL;
	}
      i++;
    }
  while ((*my_env)[size++]);
  return (size);
}
