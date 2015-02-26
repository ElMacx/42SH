/*
** my_realloc_str.c for my_malloc_str in /home/laffar_a/rendu/lib/src
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Tue Nov 26 12:40:07 2013 Antoine Laffargue
** Last update Sat Jan  4 23:53:26 2014 Antoine Laffargue
*/

#include <stdlib.h>

char            *my_realloc_str(char *str, int size)
{
  char          *final;

  if (str == NULL)
    final = malloc(size);
  else
    {
      if ((final = malloc(size)) == NULL)
	return (NULL);
      my_strcpy(final, str);
      free(str);
    }
  return (final);
}

char            **my_realloc_tab(char **tab, int size)
{
  char          **final;
  int		i;

  i = 0;
  if (tab == NULL)
    final = malloc(size);
  else
    {
      if ((final = malloc(size)) == NULL)
	return (NULL);
      while (tab[i])
	{
	  final[i] = tab[i];
	  i++;
	}
      final[i] = NULL;
      free(tab);
    }
  return (final);
}
