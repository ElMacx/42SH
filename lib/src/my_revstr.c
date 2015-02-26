/*
** my_revstr.c for ex_03 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 12:33:39 2013 Antoine Laffargue
** Last update Tue Oct 29 11:18:20 2013 Antoine Laffargue
*/

char	*my_revstr(char *str)
{
  int	i;
  int	i2;
  int	len;
  char	temp;

  len = my_strlen(str);
  i = 0;
  i2 = len - 1;
  while (i < (len / 2))
    {
      temp = str[i2];
      str[i2] = str[i];
      str[i] = temp;
      i = i + 1;
      i2 = i2 - 1;
    }
  return (str);
}
