/*
** my_strlcat.c for ex_01 in /home/laffar_a/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Tue Oct  8 17:12:15 2013 Antoine Laffargue
** Last update Wed Oct  9 10:07:16 2013 Antoine Laffargue
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (size < 0)
    {
      i = size;
    }
  while (dest[i] != '\0' && i < size)
    {
      i = i + 1;
    }
  while (src[i2] != '\0')
    {
      dest[i] = src[i2];
      i = i + 1;
      i2 = i2 + 1;
    }
  dest[i] = '\0';
  return (i);
}
