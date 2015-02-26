/*
** my_put_nbr.c for my_put_nbr in /home/laffar_a/rendu/lib/src
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Fri Apr 25 16:08:24 2014 Antoine Laffargue
** Last update Fri Apr 25 16:11:05 2014 Antoine Laffargue
*/

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  if (nb > 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + 48);
}

void	my_put_nbr_err(int nb)
{
  if (nb < 0)
    {
      my_putchar_err('-');
      nb *= -1;
    }
  if (nb > 10)
    {
      my_put_nbr_err(nb / 10);
      my_put_nbr_err(nb % 10);
    }
  else
    my_putchar_err(nb + 48);
}
