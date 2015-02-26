/*
** my_strncmp.c for ex_06 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_06
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 15:53:16 2013 Antoine Laffargue
** Last update Sat Jan  4 04:41:19 2014 Antoine Laffargue
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  char	diff;

  diff = 0;
  i = 0;
  if (my_strlen(s1) < n && my_strlen(s2) >= my_strlen(s1))
    return (-1);
  if (my_strlen(s2) < n && my_strlen(s1) >= my_strlen(s2))
    return (1);
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      diff = s1[i] - s2[i];
      if (diff != 0)
	return (diff);
      i = i + 1;
    }
  return (diff);
}
