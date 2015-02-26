/*
** my_isneg.c for piscine_jour_03 in /home/laffar_a/rendu/Piscine-C-Jour_03
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Oct  2 12:44:06 2013 Antoine Laffargue
** Last update Wed Oct  2 22:52:56 2013 Antoine Laffargue
*/

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
}
