/*
** my_strlowcase.c for ex_08 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_08
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 16:49:39 2013 Antoine Laffargue
** Last update Tue Nov 26 20:37:25 2013 Antoine Laffargue
*/

#include <stdlib.h>

char	*my_strlowcase(char *str)
{
  int	i;
  char	*temp;

  i = 0;
  if ((temp = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
	{
	  temp[i] = str[i] + 32;
	}
      else
	{
	  temp[i] = str[i];
	}
      i = i + 1;
    }
  temp[i] = '\0';
  return (temp);
}
