/*
** parsing_list.c for minishell2 in /home/laffar_a/rendu/PSU_2013_minishell2/parsing_list
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Mar  5 19:11:19 2014 Antoine Laffargue
** Last update Wed May 28 01:47:01 2014 Antoine Laffargue
*/

#include "mysh.h"

t_pipe		*create_pipe(char *str)
{
  t_pipe	*p;
  int		start;
  int		i;

  i = 0;
  p = NULL;
  while (str[i] != '\0')
    {
      start = i;
      i = pipe_split(str, i);
      p = add_pipe(p);
      if (p == NULL)
	return (NULL);
      complete_exe_struct(&(p->exe), &str[start]);
      if (p->exe.cmd == NULL)
	{
	  my_printf_err("Syntax error\n");
	  return (NULL);
	}
    }
  return (p);
}

int		pipe_split(char *str, int i)
{
  int		token_len;

  token_len = 1;
  while (str[i] != '|' && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    token_len = 0;
  str[i] = '\0';
  return (i + token_len);
}

int		sep_split(char *str, int i, int *separator)
{
  int		token_len;
  int		i2;

  i2 = 0;
  while (str[i] != ';' && my_strncmp(&str[i], "&&", 2) != 0 &&
         my_strncmp(&str[i], "||", 2) != 0 && str[i] != '\0')
    i++;
  if (my_strncmp(&str[i], "&&", 2) == 0 ||
      my_strncmp(&str[i], "||", 2) == 0)
    token_len = 2;
  else if (str[i] != '\0')
    token_len = 1;
  else
    token_len = 0;
  *separator = str[i] + token_len;
  while (i2 < token_len)
    str[i + i2++] = '\0';
  return (i + token_len);
}

t_sep		*parsing_fct(char *ret)
{
  t_sep		*list;
  int		separator;
  int		start;
  int		i;

  i = 0;
  separator = 0;
  list = NULL;
  if (check_token_error(ret) == -1)
    return (NULL);
  while (ret[i] != '\0')
    {
      start = i;
      i = sep_split(ret, i, &separator);
      list = add_sep(list, create_pipe(&ret[start]), separator);
      if (list == NULL)
	return (NULL);
      if (list->p == NULL)
	return (NULL);
    }
  while (list && list->prev)
    list = list->prev;
  return (list);
}
