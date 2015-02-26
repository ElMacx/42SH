/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/laffar_a/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Oct 10 21:50:32 2013 Antoine Laffargue
** Last update Fri Apr 25 16:50:08 2014 Antoine Laffargue
*/

#include <stdlib.h>

int	count_words(char *str, char separator1, char separator2)
{
  int	i;
  int	nbr_words;

  i = 0;
  nbr_words = 0;
  while (str && str[i] != '\0')
    {
      while ((str[i] == separator1 || str[i] == separator2) && str[i] != '\0')
	str[i++] = '\0';
      while (str[i] != separator1 && str[i] != separator2 && str[i] != '\0')
	i++;
      if (str[i] != '\0' || str[i - 1] != '\0')
	nbr_words++;
    }
  return (nbr_words);
}

char	**my_str_to_wordtab(char *str, char separator1, char separator2)
{
  int	i;
  int	i2;
  int	nbr_words;
  char	**tab;

  i = 0;
  i2 = 0;
  nbr_words = count_words(str, separator1, separator2);
  if ((tab = malloc((nbr_words + 1) * sizeof(char *))) == NULL)
      return (NULL);
  while (nbr_words)
    {
      while (str[i] == '\0')
	i++;
      tab[i2] = &str[i];
      while (str[i] != '\0')
	i++;
      nbr_words--;
      i2++;
    }
  tab[i2] = NULL;
  return (tab);
}
