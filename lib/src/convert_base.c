/*
** convert_base.c for convert_base in /home/laffar_a/rendu/Piscine-C-Jour_08/ex_02
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Wed Oct  9 20:38:54 2013 Antoine Laffargue
** Last update Sun May 25 20:05:15 2014 maxime dulin
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

char		*neg_test(char *nbr, char *neg)
{
  int		i;
  char		*return_value;

  return_value = malloc(my_strlen(nbr));
  i = 0;
  if (nbr[0] == '-')
    {
      while (nbr[i + 1] != '\0')
	{
	  return_value[i] = nbr[i + 1];
	  i = i + 1;
	}
      return_value[i] = '\0';
      *neg = 1;
      return (return_value);
    }
  else
    {
      *neg = 0;
      return (nbr);
    }
}

int		check_position(char nbr, char *base)
{
  int		i;

  i = 0;
  while (nbr != base[i])
    {
      i = i + 1;
    }
  return (i);
}

long long      	base_to_b10(char *nbr, char *base_from)
{
  int		base;
  int		i;
  long long	result;
  int		length;
  long long	temp_nb;

  i = 0;
  result = 0;
  base = my_strlen(base_from);
  length = my_strlen(nbr) - 1;
  while (nbr[i] != '\0')
    {
      temp_nb = check_position(nbr[i], base_from);
      result = result + (temp_nb * my_power(base, length - i));
      i = i + 1;
    }
  return (result);
}

char		*b10_to_base(long long b_10, char *base_to, char neg)
{
  int		i;
  int		base;
  char		c;
  char		*str;
  char		check;

  i = 0;
  check = 0;
  if ((str = malloc(80)) == NULL)
    return (NULL);
  base = my_strlen(base_to);
  while (check == 0)
    {
      if (b_10 < base)
	check = 1;
      c = b_10 % base;
      b_10 = b_10 / base;
      str[i] = base_to[c];
      i = i + 1;
    }
  if (neg == 1)
    my_strcat(str, "-");
  str[i + 1] = '\0';
  my_revstr(str);
  return (str);
}

char		*convert_base(char *nbr, char *base_from, char *base_to)
{
  long long	b_10;
  char		*number;
  char		neg;
  char		*p_neg;
  char		*nbr_temp;

  p_neg = &neg;
  nbr = neg_test(nbr, p_neg);
  b_10 = base_to_b10(nbr, base_from);
  number = b10_to_base(b_10, base_to, neg);
  return (number);
}
