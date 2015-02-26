/*
** get_next_line.c for get_next_line in /home/laffar_a/rendu/get_next_line-2018-laffar_a
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Nov 18 11:16:10 2013 Antoine Laffargue
** Last update Sun Mar  2 04:51:03 2014 Antoine Laffargue
*/

#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"

char		*my_strcpy_gnl(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int		check_new_line(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	return (-1);
      i++;
    }
  return (i);
}

char		*my_realloc(int size, int actual_size, char *str)
{
  char		*tmp;

  if (str == NULL)
    {
      str = malloc(size);
      str[0] = '\0';
      return (str);
    }
  if ((tmp = malloc(actual_size + 1)) == NULL)
    return (NULL);
  my_strcpy_gnl(tmp, str);
  free(str);
  if ((str = malloc(size)) == NULL)
    return (NULL);
  my_strcpy_gnl(str, tmp);
  free(tmp);
  return (str);
}

int		store_next_line(char *final, char **next_line)
{
  int		i;

  i = 0;
  while (final[i] != '\n' && final[i] != '\0')
    i++;
  if (final[i] == '\n')
    {
      if ((*next_line = malloc(BUFFER_SIZE + 1)) == NULL)
	return (1);
      final[i] = '\0';
      my_strcpy_gnl(*next_line, &final[i + 1]);
    }
  else
    if (*next_line != NULL)
      {
	free(*next_line);
	*next_line = NULL;
      }
  return (0);
}

char		*get_next_line(const int fd)
{
  int		ret;
  int		final_len;
  char		*final;
  static char	*next_line;

  ret = 1;
  if ((final = malloc(BUFFER_SIZE + 1)) == NULL || BUFFER_SIZE <= 0)
    return (NULL);
  final[0] = '\0';
  if (next_line != NULL)
    my_strcpy_gnl(final, next_line);
  while ((final_len = check_new_line(final)) != -1 && ret != 0)
    {
      final = my_realloc(final_len + BUFFER_SIZE + 1, final_len, final);
      if (final == NULL)
	return (NULL);
      ret = read(fd, &final[final_len], BUFFER_SIZE);
      if (ret == -1 || (ret == 0 && final_len == 0))
	return (NULL);
      final[final_len + ret] = '\0';
    }
  if (store_next_line(final, &next_line))
    return (NULL);
  return (final);
}
