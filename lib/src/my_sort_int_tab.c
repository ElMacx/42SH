/*
** my_sort_in_tab.c for my_sort_in_tab in /home/laffar_a/Desktop/Temp
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Wed Oct  9 09:43:37 2013 Antoine Laffargue
** Last update Sun Oct 20 19:11:03 2013 Antoine Laffargue
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  char	check;
  int	temp;

  check = 0;
  while (check != 1)
    {
      i = 0;
      check = 1;
      while (i < size)
	{
	  if (tab[i] > tab[i + 1])
	    {
	      temp = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = temp;
	      check = 0;
	    }
	  i = i + 1;
	}
    }
}
