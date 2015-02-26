/*
** my_sort_wordtab.c for my_sort_wordtab in /home/laffar_a/rendu/Piscine-C-Jour_11/ex_03
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Oct 21 17:45:14 2013 Antoine Laffargue
** Last update Tue Nov 26 20:33:51 2013 Antoine Laffargue
*/

int	my_sort_wordtab(char **tab)
{
  int	i;
  char	*temp;
  char	check;

  check = 1;
  while (check != 0)
    {
      check = 0;
      i = 1;
      while (tab[i] != 0)
	{
	  if (my_strcmp(tab[i - 1], tab[i]) > 0)
	    {
	      temp = tab[i - 1];
	      tab[i - 1] = tab[i];
	      tab[i] = temp;
	      check = 1;
	    }
	  i = i + 1;
	}
    }
  return (0);
}

int	my_sort_wordtab_nocase(char **tab)
{
  int	i;
  char	*temp;
  char	check;

  check = 1;
  while (check != 0)
    {
      check = 0;
      i = 1;
      while (tab[i] != 0)
	{
	  if (my_strcmp(my_strlowcase(tab[i - 1]), my_strlowcase(tab[i])) > 0)
	    {
	      temp = tab[i - 1];
	      tab[i - 1] = tab[i];
	      tab[i] = temp;
	      check = 1;
	    }
	  i = i + 1;
	}
    }
  return (0);
}
