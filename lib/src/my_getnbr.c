/*
** my_getnbr.c for piscine_jour_04 in /home/laffar_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Oct  3 16:45:57 2013 Antoine Laffargue
** Last update Tue Nov 12 13:46:13 2013 Antoine Laffargue
*/

int	power_ten(int p)
{
  int	i;
  int	power;

  power = 1;
  i = 0;
  while (i < (p-1))
    {
      power = power * 10;
      i = i + 1;
    }
  return (power);
}

int	test_neg(char *str, int *i)
{
  int	neg;

  neg = 0;
  while (str[*i] == '+' || str[*i] == '-')
    {
      if (str[*i] == '-')
	neg = neg + 1;
      *i = *i + 1;
    }
  if ((neg % 2) != 0)
    neg = 1;
  return (neg);
}

int	verify_size(int str, int neg)
{
  if (str > 0 && neg == 1)
    return (1);
  if (str < 0 && neg != 1)
    return (1);
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	neg;
  int	length;
  int	return_int;
  int	x;

  i = 0;
  neg = 0;
  return_int = 0;
  neg = test_neg(str, &i);
  length = my_strlen(str);
  while (str[i] >= 48 && str[i] <= 57)
    {
      x = power_ten(length - i);
      return_int = return_int + ((str[i] - 48) * x);
      i = i + 1;
    }
  return_int = return_int / x;
  if (neg == 1)
    return_int = return_int * -1;
  if (verify_size(return_int, neg))
    return (0);
  return (return_int);
}
