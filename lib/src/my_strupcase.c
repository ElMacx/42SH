/*
** my_strupcase.c for ex_07 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_07
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 16:49:39 2013 Antoine Laffargue
** Last update Mon Oct  7 19:34:24 2013 Antoine Laffargue
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
