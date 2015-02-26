/*
** buitlin_tools.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Thu Dec 12 11:44:26 2013 Antoine Laffargue
** Last update Sun May 25 22:15:24 2014 maxime dulin
*/

#include "mysh.h"

int	move_to(char *path, char **pwd, char ***my_env)
{
  if (!check_cd_error(path))
    return (0);
  if (chdir(path) == -1)
    my_printf_err("cd: %s: folder not found\n", path);
  else if (my_strncmp(path, "/", 1) == 0)
    {
      set_oldpwd(*pwd, my_env);
      free(*pwd);
      MALLOC_CHECK_INT(*pwd = malloc(my_strlen(path) + 5));
      my_strcpy(*pwd, "PWD=");
      my_strcat(*pwd, path);
    }
  else
    {
      set_oldpwd(*pwd, my_env);
      modif_pwd(path, pwd);
    }
  return (0);
}

int	modif_pwd(char *path, char **pwd)
{
  int	i;
  int	i2;
  char	**path_tab;

  i = 0;
  path_tab = my_str_to_wordtab(path, '/', -1);
  while (path_tab[i])
    {
      i2 = my_strlen(*pwd) - 1;
      if (my_strcmp(path_tab[i], "..") == 0)
	{
	  while ((*pwd)[i2--] != '/');
	  (*pwd)[i2 + 1] = '\0';
	}
      else if (my_strcmp(path_tab[i], ".") != 0)
	{
	  MALLOC_CHECK_INT(*pwd = my_realloc_str(*pwd, my_strlen(*pwd) +
						 my_strlen(path_tab[i]) + 2));
	  if ((*pwd)[my_strlen(*pwd) - 1] != '/')
	    my_strcat(*pwd, "/");
	  my_strcat(*pwd, path_tab[i]);
	}
      i++;
    }
  free(path_tab);
}

int	create_pwd(char *home, char ***my_env)
{
  char	*pwd;

  my_printf_err("PWD variable missing, redirecting home ..\n");
  MALLOC_CHECK_INT(pwd = malloc(my_strlen(home)));
  my_strcpy(pwd, "PWD=");
  my_strcat(pwd, &home[5]);
  setenv_builtin(pwd, my_env);
  my_printf_err("You are now at : %s\nYou can now use cd\n", &pwd[4]);
  return (0);
}

int	create_home(char ***my_env)
{
  char	*home;
  int	check;

  check = 0;
  my_printf_err("No home variable\nplease choose your home (enter a path): ");
  while ((home = get_next_line(0)) && check != 1)
    {
      if (chdir(home) == -1)
	my_printf_err("Wrong path, try again : ");
      else
	{
	  if (set_home(home, my_env))
	    return (1);
	  my_printf_err("Your home is successfully set at %s\n", home);
	  check = 1;
	}
    }
  if (!home)
    {
      set_home("/", my_env);
      my_printf_err("Home set at '/'\n");
    }
  return (0);
}

int	set_home(char *home, char ***my_env)
{
  char	*home_var;

  MALLOC_CHECK_INT(home_var = malloc(my_strlen(home) + 6));
  my_strcpy(home_var, "HOME=");
  my_strcat(home_var, home);
  setenv_builtin(home_var, my_env);
  return (0);
}
