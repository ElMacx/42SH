/*
** my_swap.c for piscine_jour_04 in /home/laffar_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Oct  3 10:50:35 2013 Antoine Laffargue
** Last update Mon Dec  2 18:51:58 2013 Antoine Laffargue
*/

int	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
