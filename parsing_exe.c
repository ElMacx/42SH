/*
** parsing_exe.c for mysh in /home/laffar_a/rendu/PSU_2013_42sh
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Thu May 15 14:36:11 2014 Antoine Laffargue
** Last update Wed May 28 01:46:02 2014 Antoine Laffargue
*/

#include "mysh.h"

void		complete_exe_struct(t_exe *exe, char *str)
{
  int           i;
  int           r_len;
  int           c_len;
  int           token_len;

  i = 0;
  r_len = 1;
  c_len = 1;
  while (str[i] != '\0')
    {
      token_len = 0;
      if (my_strncmp(&str[i], "<<", 2) == 0 ||
          my_strncmp(&str[i], ">>", 2) == 0)
        token_len = 2;
      else if (str[i] == '<' || str[i] == '>')
        token_len = 1;
      if (token_len)
	i += get_redirect(exe, &r_len, &str[i + token_len],
			  str[i] + token_len) + token_len;
      else if (str[i] != ' ' && str[i] != '\t')
	i += get_cmd(exe, &c_len, &str[i]) + token_len;
      else
	i++;
    }
}

int		get_redirect(t_exe *exe, int *r_len, char *str, int type)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    exe->cmd = NULL;
  while (!is_stop_char(&str[i + len]))
    len++;
  if ((exe->redirect =
       realloc(exe->redirect, (*r_len + 1) * sizeof(char*))) == NULL ||
      (exe->type = realloc(exe->type, (*r_len + 1) * sizeof(int))) == NULL)
    return (-(i + len + 1));
  if ((exe->redirect[*r_len - 1] = malloc(len + 1)) == NULL)
    return (-(i + len + 1));
  my_strncpy(exe->redirect[*r_len - 1], &str[i], len);
  exe->type[*r_len - 1] = type;
  exe->type[*r_len] = 0;
  exe->redirect[*r_len] = NULL;
  (*r_len)++;
  return (i + len);
}

int		get_cmd(t_exe *exe, int *c_len, char *str)
{
  int		len;

  len = 0;
  while (!is_stop_char(&str[len]))
    len++;
  if ((exe->cmd = realloc(exe->cmd, (*c_len + 1) * sizeof(char*))) == NULL)
    return (-(len + 1));
  if ((exe->cmd[*c_len - 1] = malloc(len + 1)) == NULL)
    return (-(len + 1));
  my_strncpy(exe->cmd[*c_len - 1], str, len);
  exe->cmd[*c_len] = NULL;
  (*c_len)++;
  return (len);
}

int		is_stop_char(char *str)
{
  if (str[0] == ' ' || str[0] == '\t' ||
      str[0] == '\0' || str[0] == '<' ||
      str[0] == '>' ||
      my_strncmp(str, "<<", 2) == 0 ||
      my_strncmp(str, ">>", 2) == 0)
    return (1);
  return (0);
}
