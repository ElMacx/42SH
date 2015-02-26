/*
** my.h for my.h in /home/laffar_a/rendu/Piscine-C-include
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Fri Oct 11 11:15:18 2013 Antoine Laffargue
** Last update Wed May 21 19:56:06 2014 maxime dulin
*/

#ifndef MY_H_
#define MY_H_

void		my_putchar(char);
void		my_putchar_err(char);
int		my_isneg(int);
int		my_put_nbr(int);
int             my_put_nbr_err(int);
int		my_swap(int *, int *);
int		my_putstr(char *);
int		my_putstr_err(char *);
int		my_strlen(char *);
int		my_getnbr(char *);
void		my_sort_int_tab(int *, int);
int		my_power_rec(int, int);
long long       my_power(long long nb, int power);
int		my_square_root(int);
int		my_is_prime(int);
int		my_find_prime_sup(int);
char		*my_strcpy(char *, char *);
char		*my_strncpy(char *, char *, int);
char		*my_revstr(char *);
char		*my_strstr(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_strupcase(char *);
char		*my_strlowcase(char *);
char		*my_strcapitalize(char *);
int		my_str_isalpha(char *);
int		my_str_isnum(char *);
int		my_str_islower(char *);
int		my_str_isupper(char *);
int		my_str_isprintable(char *);
int		my_showstr(char *);
int		my_showmem(char *, int);
char		*my_strcat(char *, char *);
char		*my_strncat(char *, char *, int);
int		my_strlcat(char *, char *, int);
char            *my_realloc_str(char *, int);
char            **my_realloc_tab(char **, int);
char		**my_str_to_wordtab(char *, char, char);
int		count_words(char *);
int		my_sort_wordtab(char **);
int		my_sort_wordtab_nocase(char **);
char		**to_tab(char *, char);

#include <stdarg.h>
#include "my_printf.h"
#include "get_next_line.h"

#endif
