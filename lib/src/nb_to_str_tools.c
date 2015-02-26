/*
** tool.c for my_printf in /home/laffar_a/rendu/PSU_2013_my_printf
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Fri Nov 15 00:33:16 2013 Antoine Laffargue
** Last update Mon Nov 18 11:42:09 2013 Antoine Laffargue
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*int_to_str(int nb)
{
  int	i;
  int	divisor;
  char	*final;

  i = 0;
  divisor = 1;
  while ((nb / divisor) >= 10)
    {
      divisor = divisor * 10;
      i++;
    }
  if ((final = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (divisor >= 10)
    {
      final[i] = nb / divisor + 48;
      nb = nb - (nb / divisor) * divisor;
      i++;
      divisor = divisor / 10;
    }
  final[i] = nb + 48;
  final[i + 1] = '\0';
  return (final);
}

char	*longlong_to_str(long long nb)
{
  int	i;
  long long	divisor;
  char	*final;

  i = 0;
  divisor = 1;
  while ((nb / divisor) >= 10)
    {
      divisor = divisor * 10;
      i++;
    }
  if ((final = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (divisor >= 10)
    {
      final[i] = nb / divisor + 48;
      nb = nb - (nb / divisor) * divisor;
      i++;
      divisor = divisor / 10;
    }
  final[i] = nb + 48;
  final[i + 1] = '\0';
  return (final);
}

char	*uint_to_str(unsigned int nb)
{
  int	i;
  int	divisor;
  char	*final;

  i = 0;
  divisor = 1;
  while ((nb / divisor) >= 10)
    {
      divisor = divisor * 10;
      i++;
    }
  if ((final = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (divisor >= 10)
    {
      final[i] = nb / divisor + 48;
      nb = nb - (nb / divisor) * divisor;
      i++;
      divisor = divisor / 10;
    }
  final[i] = nb + 48;
  final[i + 1] = '\0';
  return (final);
}

char	*char_to_str(char nb)
{
  int	i;
  int	divisor;
  char	*final;

  i = 0;
  divisor = 1;
  while ((nb / divisor) >= 10)
    {
      divisor = divisor * 10;
      i++;
    }
  if ((final = malloc(4)) == NULL)
    return (NULL);
  i = 0;
  while (divisor >= 10)
    {
      final[i] = nb / divisor + 48;
      nb = nb - (nb / divisor) * divisor;
      i++;
      divisor = divisor / 10;
    }
  final[i] = nb + 48;
  final[i + 1] = '\0';
  return (final);
}
