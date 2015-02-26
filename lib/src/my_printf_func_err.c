/*
** func.c for my_printf in /home/laffar_a/rendu/PSU_2013_my_printf
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Nov 14 18:55:23 2013 Antoine Laffargue
** Last update Fri Apr 25 16:21:37 2014 Antoine Laffargue
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int	flag_d_err(char *flag, va_list *arg)
{
  int	d;

  d = va_arg(*arg, int);
  my_put_nbr_err(d);
  return (0);
}

int	flag_o_err(char *flag, va_list *arg)
{
  char	*ret;

  if (*flag == '#')
    my_putchar_err('0');
  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  ret = convert_base(ret, "0123456789", "01234567");
  my_putstr_err(ret);
  return (0);
}

int	flag_u_err(char *flag, va_list *arg)
{
  char	*ret;

  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  my_putstr_err(ret);
  return (0);
}

int	flag_x_err(char *flag, va_list *arg)
{
  char	*ret;

  if (*flag == '#')
    my_putstr_err("0x");
  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  ret = convert_base(ret, "0123456789", "0123456789abcdef");
  my_putstr_err(ret);
  return (0);
}

int	flag_x_maj_err(char *flag, va_list *arg)
{
  char	*ret;

  if (*flag == '#')
    my_putstr_err("0X");
  ret = uint_to_str(va_arg(*arg, unsigned int));
  if (ret == NULL)
    return (1);
  ret = convert_base(ret, "0123456789", "0123456789ABCDEF");
  my_putstr_err(ret);
  return (0);
}
