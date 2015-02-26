/*
** my_strcapitalize.c for ex_09 in /home/laffar_a/rendu/Piscine-C-Jour_06/ex_09
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct  7 16:49:39 2013 Antoine Laffargue
** Last update Tue Oct  8 14:13:20 2013 Antoine Laffargue
*/

void	check_position_capitalize(char *str, int i, char cap)
{
  char	check;

  check = 0;
  if (str[i - 1] < 48 || str[i - 1] > 57)
    {
      if (str[i - 1] < 97 || str[i - 1] > 122)
	{
	  if (str[i - 1] < 65 || str[i - 1] > 90)
	    {
	      check = 1;
	      if (cap == 0)
		{
		  str[i] = str[i] - 32;
		}
	    }
	}
    }
  if (check == 0 && cap == 1)
    {
      str[i] = str[i] + 32;
    }
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	{
	  if (i == 0)
	    {
	      str[i] = str[i] - 32;
	    }
	  else
	    {
	      check_position_capitalize(str, i, 0);
	    }
	}
      else if (str[i] >= 65 && str[i] <= 90)
	{
	  check_position_capitalize(str, i, 1);
	}
      i = i + 1;
    }
  return (str);
}
