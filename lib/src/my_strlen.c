/*
** my_strlen.c for piscine_jour_04 in /home/laffar_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Oct  3 12:03:32 2013 Antoine Laffargue
** Last update Sun Nov 17 19:45:48 2013 Antoine Laffargue
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
