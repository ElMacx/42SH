/*
** func2.c for my_printf in /home/laffar_a/rendu/PSU_2013_my_printf
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Fri Nov 15 20:02:55 2013 Antoine Laffargue
** Last update Sun May 25 20:06:19 2014 maxime dulin
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int		flag_s_err(char *flag, va_list *arg)
{
  char		*ret;

  ret = va_arg(*arg, char *);
  if (ret == NULL)
    {
      my_putstr_err("(null)");
      return (1);
    }
  my_putstr_err(ret);
  return (0);
}

int		flag_s_maj_err(char *flag, va_list *arg)
{
  char		*ret;
  char		*oct;
  int		zero;
  int		i;

  i = 0;
  ret = va_arg(*arg, char *);
  if (ret == NULL)
    return (1);
  while (ret[i] != '\0')
    {
      if (ret[i] < 32 || ret[i] > 126)
	{
	  my_putchar_err('\\');
	  oct = convert_base(char_to_str(ret[i]), "0123456789", "01234567");
	  zero = 3 - my_strlen(oct);
	  while (zero-- > 0)
	    my_putchar_err('0');
	  my_putstr_err(oct);
	}
      else
	my_putchar_err(ret[i]);
      i++;
    }
  return (0);
}

int		flag_c_err(char *flag, va_list *arg)
{
  unsigned char	ret;

  ret = (unsigned char)va_arg(*arg, int);
  if (ret > 191)
    ret = 191;
  write(2, &ret, 1);
  return (0);
}

int		flag_p_err(char *flag, va_list *arg)
{
  long long	ret_longlong;
  char		*ret;

  ret_longlong = va_arg(*arg, long long);
  if (ret_longlong == 0)
    my_putstr_err("(nil)");
  else
    {
      my_putstr_err("0x");
      ret = longlong_to_str(ret_longlong);
      ret = convert_base(ret, "0123456789", "0123456789abcdef");
      my_putstr_err(ret);
    }
  return (0);
}

int		flag_b_err(char *flag, va_list *arg)
{
  unsigned int	b;
  char		*ret;

  b = va_arg(*arg, unsigned int);
  ret = convert_base(uint_to_str(b), "0123456789", "01");
  my_putstr_err(ret);
  return (0);
}
