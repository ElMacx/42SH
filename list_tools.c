/*
** list_tools.c for mysh in /home/laffar_a/rendu/PSU_2013_42sh
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Thu May 15 13:43:22 2014 Antoine Laffargue
** Last update Sun May 25 19:59:15 2014 maxime dulin
*/

#include "mysh.h"

t_sep		*add_sep(t_sep *list, t_pipe *p, int separator)
{
  t_sep		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    {
      my_printf_err("could not alloc\n");
      return (NULL);
    }
  if (list)
    list->next = new;
  new->separator = separator;
  new->p = p;
  new->prev = list;
  new->next = NULL;
  return (new);
}

t_pipe		*add_pipe(t_pipe *list)
{
  t_pipe	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    {
      my_printf_err("could not alloc\n");
      return (NULL);
    }
  new->exe.cmd = NULL;
  new->exe.redirect = NULL;
  new->exe.type = NULL;
  if (list)
    list->prev = new;
  new->prev = NULL;
  new->next = list;
  return (new);
}
