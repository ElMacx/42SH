/*
** my_putchar.c for my_putchar in /home/laffar_a/Desktop/Temp
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Oct  9 09:54:11 2013 Antoine Laffargue
** Last update Fri Apr 25 16:02:44 2014 Antoine Laffargue
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}
