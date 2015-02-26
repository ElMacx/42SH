/*
** setenv_tools.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Tue Dec 17 16:20:09 2013 Antoine Laffargue
** Last update Wed Mar  5 23:01:45 2014 Antoine Laffargue
*/

#include "mysh.h"

int	add_var(char *cmd, char ***my_env)
{
  int   i;

  i = 0;
  while ((*my_env)[i++]);
  MALLOC_CHECK_INT(*my_env = my_realloc_tab(*my_env, (i + 1) * sizeof(char*)));
  MALLOC_CHECK_INT((*my_env)[i - 1] = malloc(my_strlen(cmd) + 1));
  my_strcpy((*my_env)[i - 1], cmd);
  (*my_env)[i] = NULL;
  return (0);
}

int	modif_var(char *cmd, char **var)
{
  free(*var);
  MALLOC_CHECK_INT(*var = malloc(my_strlen(cmd) + 1));
  my_strcpy(*var, cmd);
  return (0);
}
