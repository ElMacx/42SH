/*
²²** my_strncat.c for ex_01 in /home/laffar_a/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Tue Oct  8 14:34:50 2013 Antoine Laffargue
** Last update Thu Oct 10 18:54:59 2013 Antoine Laffargue
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	dest_len;

  dest_len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[dest_len] = src[i];
      i = i + 1;
      dest_len = dest_len + 1;
    }
  dest[dest_len] = '\0';
  return (dest);
}
