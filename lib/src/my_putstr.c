/*
** my_putstr.c for piscine_jour_04 in /home/laffar_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Oct  3 11:32:11 2013 Antoine Laffargue
** Last update Fri Apr 25 16:02:01 2014 Antoine Laffargue
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int     my_putstr_err(char *str)
{
  int   i;

  i = 0;
  while (str && str[i] != '\0')
    {
      my_putchar_err(str[i]);
      i = i + 1;
    }
  return (0);
}
