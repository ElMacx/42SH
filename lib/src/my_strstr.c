/*
** my_strstr.c for ex_04 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 13:04:29 2013 Antoine Laffargue
** Last update Wed Oct 30 23:07:40 2013 Antoine Laffargue
*/
#include <stdlib.h>

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  char	found;
  char	*p_return;
  int	i2;

  i = 0;
  while (str[i] != '\0')
    {
      i2 = 0;
      if (str[i] == to_find[i2])
	{
	  p_return = &str[i];
	  while (str[i] == to_find[i2] && to_find[i2] != '\0')
	    {
	      i = i + 1;
	      i2 = i2 + 1;
	    }
	  if (to_find[i2] == '\0')
	      return p_return;
	  p_return = NULL;
	}
      i = i + 1;
    }
  return (p_return);
}
