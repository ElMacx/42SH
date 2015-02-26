/*
** my_printf.c for my_printf in /home/laffar_a/rendu/PSU_2013_my_printf
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Tue Nov 12 16:47:29 2013 Antoine Laffargue
** Last update Sun May 25 20:05:44 2014 maxime dulin
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int		read_flags_err(char **flags, char *ret_flag)
{
  int		read_len;

  if (**flags == '%' && *(*flags + 1) != '%')
    {
      read_len = find_flags(*flags + 1, ret_flag);
      *flags = *flags + read_len;
      if (read_len == 0)
	my_putchar_err('%');
      return (read_len);
    }
  else if (**flags == '%' && *(*flags + 1) == '%')
    *flags++;
  else
    my_putchar_err(**flags);
  return (0);
}

void		init_fct_err(char *char_flag, int (**fct)(char *, va_list *arg))
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
  fct[0] = &flag_d_err;
  fct[1] = &flag_d_err;
  fct[2] = &flag_o_err;
  fct[3] = &flag_u_err;
  fct[4] = &flag_x_err;
  fct[5] = &flag_x_maj_err;
  fct[6] = &flag_s_err;
  fct[7] = &flag_s_maj_err;
  fct[8] = &flag_c_err;
  fct[9] = &flag_p_err;
  fct[10] = &flag_b_err;
}

int		my_printf_err(char *flags, ...)
{
  va_list	arg;
  char		*ret_flag;
  char		char_flag[12];
  int		(*fct[11])(char *flag, va_list *arg);
  int		i;

  init_fct_err(char_flag, fct);
  if ((ret_flag = malloc(my_strlen(flags) * sizeof(*ret_flag))) == NULL)
    return (1);
  va_start(arg, flags);
  while (flags && *flags)
    {
      i = 0;
      if (read_flags_err(&flags, ret_flag))
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
