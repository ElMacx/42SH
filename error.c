/*
** error.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Apr 16 11:02:42 2014 Antoine Laffargue
** Last update Wed May 28 01:09:18 2014 Antoine Laffargue
*/

#include "mysh.h"

int	check_cd_error(char *path)
{
  DIR   *dir;

  if (access(path, F_OK) == -1)
    {
      my_printf_err("cd: %s: folder not found\n", path);
      return (0);
    }
  else if (access(path, R_OK) == -1)
    {
      my_printf_err("cd: %s: permisson denied\n", path);
      return (0);
    }
  else if ((dir = opendir(path)) == NULL)
    {
      my_printf_err("cd: %s: is not a folder\n", path);
      return (0);
    }
  else
    if (closedir(dir) == -1)
      my_printf_err("closedir failed\n");
  return (1);
}
