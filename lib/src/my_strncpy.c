/*
** my_strncpy.c for ex_02 in /home/laffar_a/rendu/Piscine-C-Jour_06
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 11:31:16 2013 Antoine Laffargue
** Last update Mon Oct  7 19:28:22 2013 Antoine Laffargue
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (i <= n)
    {
      dest[i] = '\0';
    }
  return (dest);
}
