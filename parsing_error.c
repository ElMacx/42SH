/*
** parsing_error.c for 42sh in /home/laffar_a/Documents/42sh
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu May 22 12:33:24 2014 Antoine Laffargue
** Last update Sat May 24 12:29:44 2014 Antoine Laffargue
*/

#include "mysh.h"

int     check_token_error(char *str)
{
  int   i;
  int   token_len;
  int   text;

  text = 1;
  while (str[i] != '\0')
    {
      token_len = 0;
      if (str[i] != ' ' && str[i] != '\t' && !(token_len = is_token(&str[i])))
        text = 2;
      if (((str[i] == ';' || str[i] == '&' || str[i] == '|') && text != 2) ||
	  ((str[i] == '<' || str[i] == '>') && !text))
	{
	  token_error(&str[i], token_len);
	  return (-1);
	}
      if (token_len == -1)
	return (-1);
      update_var(str[i], token_len, &text);
      if (token_len > 0)
	i += token_len;
      else
	i++;
    }
  return (0);
}

void    token_error(char *token, int token_len)
{
  my_printf_err("Syntax error near unexpected token '");
  write(2, token, token_len);
  my_printf_err("'\n");
}

int	is_token(char *str)
{
  int	i;

  i = 0;
  if (my_strncmp(str, "&&", 2) == 0 || my_strncmp(str, "||", 2) == 0 ||
      my_strncmp(str, "<<", 2) == 0 || my_strncmp(str, ">>", 2) == 0)
    return (2);
  if (str[i] == ';' || str[i] == '|' || str[i] == '<' || str[i] == '>')
    return (1);
  if (str[i] == '&')
    {
      token_error(str, 1);
      return (-1);
    }
  return (0);
}

void	update_var(char c, int token_len, int *text)
{
  if (token_len > 0 && (c == ';' || c == '&' || c == '|'))
    *text = 1;
  else if (token_len > 0)
    *text = 0;
}
