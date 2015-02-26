/*
** replace_var.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed May  7 14:23:41 2014 Antoine Laffargue
** Last update Fri May 23 17:45:11 2014 Antoine Laffargue
*/

#include "mysh.h"

void		replace_var(t_sep *list, char **my_env)
{
  t_pipe	*p;
  int		i;

  while (list)
    {
      p = list->p;
      while (p)
	{
	  i = 0;
	  while (p->exe.cmd[i])
	    {
	      p->exe.cmd[i] = find_var(p->exe.cmd[i], my_env);
	      i++;
	    }
	  i = 0;
	  if (p->exe.redirect)
	    while (p->exe.redirect[i])
	      {
		p->exe.redirect[i] = find_var(p->exe.redirect[i], my_env);
		i++;
	      }
	  p = p->next;
	}
      list = list->next;
    }
}

char	*find_var(char *str, char **my_env)
{
  int	i;
  int	i2;
  char	*var;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '$')
	{
	  i2 = 0;
	  var = get_var_name(&str[i + 1], my_env);
	  while (str[i + i2] != ' ' && str[i + i2] != '\t' &&
		 str[i + i2] != '\0' && (str[i + i2] != '$' || i2 == 0))
	    i2++;
	  str = create_string(str, var, i, i + i2);
	}
      i++;
    }
  return (str);
}

char	*get_var_name(char *str, char **my_env)
{
  int	i;
  int	var_len;
  char	mem;

  i = 0;
  var_len = 0;
  if (str[0] == '\0')
    return (NULL);
  while (str[var_len] != ' ' && str[var_len] != '\t'
	 && str[var_len] != '\0' && str[var_len] != '$')
    var_len++;
  mem = str[var_len];
  str[var_len] = '=';
  while (my_env[i] && my_strncmp(my_env[i], str, var_len + 1) != 0)
    i++;
  str[var_len] = mem;
  if (my_env[i])
    return (&my_env[i][var_len + 1]);
  else
    return (NULL);
}

char	*create_string(char *str, char *var, int i, int i2)
{
  char	*final;

  if (var == NULL)
    {
      while (i < i2)
	str[i++] = ' ';
      return (str);
    }
  if ((final = malloc(i + my_strlen(var) + my_strlen(&str[i2]) + 2)) == NULL)
    {
      my_printf_err("could not alloc\n");
      return (NULL);
    }
  str[i] = '\0';
  my_strcpy(final, str);
  my_strcat(final, var);
  my_strcat(final, &str[i2]);
  return (final);
}
