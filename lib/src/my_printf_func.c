/*
** func.c for my_printf in /home/laffar_a/rendu/PSU_2013_my_printf
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Nov 14 18:55:23 2013 Antoine Laffargue
** Last update Sun Nov 17 19:53:38 2013 Antoine Laffargue
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int	flag_d(char *flag, va_list *arg)
{
  int	d;

  d = va_arg(*arg, int);
  my_put_nbr(d);
  return (0);
}

int	flag_o(char *flag, va_list *arg)
{
  char	*ret;

  if (*flag == '#')
    my_putchar('0');
  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  ret = convert_base(ret, "0123456789", "01234567");
  my_putstr(ret);
  return (0);
}

int	flag_u(char *flag, va_list *arg)
{
  char	*ret;

  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  my_putstr(ret);
  return (0);
}

int	flag_x(char *flag, va_list *arg)
{
  char	*ret;

  if (*flag == '#')
    my_putstr("0x");
  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  ret = convert_base(ret, "0123456789", "0123456789abcdef");
  my_putstr(ret);
  return (0);
}

int	flag_x_maj(char *flag, va_list *arg)
{
  char	*ret;

  if (*flag == '#')
    my_putstr("0X");
  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  ret = convert_base(ret, "0123456789", "0123456789ABCDEF");
  my_putstr(ret);
  return (0);
}
