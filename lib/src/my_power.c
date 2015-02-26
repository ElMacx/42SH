/*
** convert_base.c for convert_base in /home/laffar_a/rendu/Piscine-C-Jour_08/ex_02
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Oct  9 20:38:54 2013 Antoine Laffargue
** Last update Sat Nov 16 18:05:00 2013 Antoine Laffargue
*/

long long	my_power(int nb, int power)
{
  long long	final;
  int		i;

  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  i = 0;
  final = nb;
  while (i < (power - 1))
    {
      final = final * nb;
      i++;
    }
  return (final);
}
