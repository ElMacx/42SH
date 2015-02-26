/*
** my_printf.c for my_printf in /home/laffar_a/rendu/PSU_2013_my_printf
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Tue Nov 12 16:47:29 2013 Antoine Laffargue
** Last update Sun May 25 20:05:32 2014 maxime dulin
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int		check_flags(char c)
{
  int		i;
  char		*flags;
  char		check;

  i = 0;
  check = 0;
  flags = "#$*0-.+lLjzt%diouxXsScpb";
  while (flags[i] != '\0' && check == 0)
    {
      if (c == flags[i] || (c >= 48 && c <= 57))
	check = 1;
      i = i + 1;
    }
  if (!check)
    return (0);
  else if (check && i < 12)
    return (1);
  else if (check && i >= 12)
    return (2);
}

int		find_flags(char *flags, char *ret_flag)
{
  int		i;
  int		ret;
  int		i2;

  i = 0;
  i2 = 0;
  ret = 0;
  while ((ret = check_flags(flags[i])) == 1)
    i = i + 1;
  i++;
  if (ret == 0)
    return (0);
  else if (ret == 2)
    {
      while (i2 < i)
	{
	  ret_flag[i2] = flags[i2];
	  i2 = i2 + 1;
	}
      ret_flag[i2] = '\0';
      return (i);
    }
}

int		read_flags(char **flags, char *ret_flag)
{
  int		read_len;

  if (**flags == '%' && *(*flags + 1) != '%')
    {
      read_len = find_flags(*flags + 1, ret_flag);
      *flags = *flags + read_len;
      if (read_len == 0)
	my_putchar('%');
      return (read_len);
    }
  else if (**flags == '%' && *(*flags + 1) == '%')
    *flags++;
  else
    my_putchar(**flags);
  return (0);
}

void		init_fct(char *char_flag, int (**fct)(char *, va_list *arg))
{
  char_flag[0] = 'd';
  char_flag[1] = 'i';
  char_flag[2] = 'o';
  char_flag[3] = 'u';
  char_flag[4] = 'x';
  char_flag[5] = 'X';
  char_flag[6] = 's';
  char_flag[7] = 'S';
  char_flag[8] = 'c';
  char_flag[9] = 'p';
  char_flag[10] = 'b';
  char_flag[11] = '\0';
  fct[0] = &flag_d;
  fct[1] = &flag_d;
  fct[2] = &flag_o;
  fct[3] = &flag_u;
  fct[4] = &flag_x;
  fct[5] = &flag_x_maj;
  fct[6] = &flag_s;
  fct[7] = &flag_s_maj;
  fct[8] = &flag_c;
  fct[9] = &flag_p;
  fct[10] = &flag_b;
}

int		my_printf(char *flags, ...)
{
  va_list	arg;
  char		*ret_flag;
  char		char_flag[12];
  int		(*fct[11])(char *flag, va_list *arg);
  int		i;

  init_fct(char_flag, fct);
  if ((ret_flag = malloc(my_strlen(flags) * sizeof(*ret_flag))) == NULL)
    return (1);
  va_start(arg, flags);
  while (flags && *flags)
    {
      i = 0;
      if (read_flags(&flags, ret_flag))
	{
	  while (char_flag[i] != '\0' && *flags != char_flag[i++]);
	  if (fct[i - 1](ret_flag, &arg) == 1)
	    return (1);
	}
      flags = flags + 1;
    }
  va_end(arg);
  free(ret_flag);
  return (0);
}
