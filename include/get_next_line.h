/*
** get_next_line.h for get_next_line in /home/laffar_a/rendu/get_next_line-2018-laffar_a
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Mon Nov 18 11:16:27 2013 Antoine Laffargue
** Last update Tue Dec  3 17:11:07 2013 Antoine Laffargue
*/

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

#define	BUFFER_SIZE	10

char	*get_next_line(const int fd);
char	*my_strcpy_gnl(char *dest, char *src);
int	check_new_line(char *buff);
char	*my_realloc(int size, int actual_size, char *str);
int	store_next_line(char *final, char **next_line);

#endif
