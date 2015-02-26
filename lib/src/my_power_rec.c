/*
** my_power_rec.c for piscine_jour_05 in /home/laffar_a/rendu/Piscine-C-Jour_05
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Fri Oct  4 15:29:06 2013 Antoine Laffargue
** Last update Sat Nov 16 17:32:34 2013 Antoine Laffargue
*/

int		my_power_rec(long long nb, long long power)
{
  long long	result;
  long long	return_value;

  if (power == 0)
      return (1);
  if (power < 0)
      return (0);
  return_value = my_power_rec(nb, (power - 1));
  result = nb * return_value;
  if ((result / nb) == return_value)
      return (result);
  else
      return (0);
}
