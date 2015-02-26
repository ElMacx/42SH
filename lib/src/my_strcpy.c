/*
** my_strcpy.c for ex_01 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 09:48:40 2013 Antoine Laffargue
** Last update Mon Nov 18 21:13:36 2013 Antoine Laffargue
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
