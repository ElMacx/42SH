/*
** to_tab.c for my_lin in /home/dulin_m/rendu/lem_in/My_lib
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Mon Apr 28 18:28:24 2014 maxime dulin
** Last update Wed May 21 19:35:03 2014 maxime dulin
*/

#include "mysh.h"

int     tab_len(char *str, char c)
{
  int   i;
  int   ct;

  ct = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	ct++;
      i++;
    }
  return (ct);
}

int     how_alloc(char *str, char c, int i)
{
  int   ct;

  ct = 0;
  while (str[i++] != c && str[i])
    ct++;
  return (ct);
}

char    **to_tab(char *str, char c)
{
  char  **tab;
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * (tab_len(str, c) + 2))) == NULL)
    return (NULL);
  while (i < strlen(str))
    {
      k = 0;
      if ((tab[j] = malloc(sizeof(char) * (how_alloc(str, c, i) + 2))) == NULL)
	return (NULL);
      while (str[i] && str[i] != c)
      	{
      	  tab[j][k] = str[i];
      	  k++;
      	  i++;
      	}
      tab[j++][k] = 0;
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
