/*
** my_str_islower.c for ex_12 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_12
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 19:00:13 2013 Antoine Laffargue
** Last update Mon Oct  7 22:41:35 2013 Antoine Laffargue
*/

int	my_str_islower(char *str)
{
  int	i;
  int	return_value;

  i = 0;
  return_value = 1;
  while (str[i] != '\0')
    {
      if (str[i] < 97 || str[i] > 122)
	{
	  return_value = 0;
	}
      i = i + 1;
    }
  return (return_value);
}
