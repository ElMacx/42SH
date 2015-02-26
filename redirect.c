/*
** redirect.c for minishell2 in /home/laffar_a/rendu/PSU_2013_minishell2
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Thu Mar  6 17:22:51 2014 Antoine Laffargue
** Last update Sun May 25 19:48:41 2014 maxime dulin
*/

#include "mysh.h"

int	redirect_handler(char *str, int type, int **fd, char *limit[2])
{
  if (type == 63 || type == 64)
    (*fd)[1] = right_redirect(str, type);
  else if (type == 61)
    {
      (*fd)[0] = simple_left_redirect(str);
      return (0);
    }
  else if (type == 62)
    {
      if (limit[1])
	{
	  if (limit[0])
	    free(limit[0]);
	  limit[0] = limit[1];
	}
      if ((limit[1] = malloc(my_strlen(str) + 1)) == NULL)
	return (-2);
      my_strcpy(limit[1], str);
      return (1);
    }
  return (-1);
}

int	right_redirect(char *file, int type)
{
  int	fd;

  if (type == 63)
    fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0666);
  if (type == 64)
    fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0666);
  if (fd == -1)
    {
      if (access(file, F_OK) == 0)
	my_printf_err("Failed to open '%s'\n", file);
      else
	my_printf_err("'%s' No such file or directory\n", file);
      exit(1);
    }
  return (fd);
}

int	simple_left_redirect(char *file)
{
  int	fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    {
      if (access(file, F_OK) == 0)
	my_printf_err("Failed to open '%s'\n", file);
      else
	my_printf_err("'%s' No such file or directory\n", file);
      exit(1);
    }
  return (fd);
}

int	double_left_redirect(char *limit[2], int **fd, int mode)
{
  char	*ret;
  char	*final;
  int	len;

  final = NULL;
  len = 0;
  if (limit[0])
    my_printf("> ");
  while (limit[0] && (ret = get_next_line(0)) && my_strcmp(ret, limit[0]) != 0)
    my_printf("> ");
  my_printf("> ");
  while ((ret = get_next_line(0)) && my_strcmp(ret, limit[1]) != 0)
    {
      if ((final = my_realloc_str(final,
				  len + my_strlen(ret) + 2)) == NULL)
	return (-1);
      my_strcpy(&final[len], ret);
      len = my_strlen(final);
      final[len++] = '\n';
      final[len] = '\0';
      my_printf("> ");
    }
  if (mode)
    double_left_redirect_fork(final, fd);
  return (0);
}

int	double_left_redirect_fork(char *final, int **fd)
{
  int	pid;
  int	pipefd[2];

  if (pipe(pipefd) == -1)
    {
      my_printf_err("error on pipe\n");
      exit(1);
    }
  pid = fork();
  if (pid == -1)
    {
      my_printf_err("error on fork\n");
      exit(1);
    }
  if (pid == 0)
    {
      close(pipefd[0]);
      write(pipefd[1], final, my_strlen(final));
      exit(0);
    }
  free(final);
  close(pipefd[1]);
  (*fd)[0] = pipefd[0];
  return (0);
}
