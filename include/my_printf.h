/*
** my_printf.h for my_printf in /home/laffar_a/rendu/Piscine-C-include
** 
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
** 
** Started on  Thu Nov 14 17:51:53 2013 Antoine Laffargue
** Last update Fri Apr 25 16:24:50 2014 Antoine Laffargue
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

/* my_printf */
int     check_flags(char c);
int     find_flags(char *flags, char *ret_flag);
int     read_flags(char **flags, char *ret_flag);
void    init_fct(char *char_flag, int (**fct)(char *, va_list *arg));
int     my_printf(char *flags, ...);
char    *int_to_str(int nb);
char    *longlong_to_str(long long nb);
char    *uint_to_str(unsigned int nb);
char    *char_to_str(char nb);
char    *convert_base(char *nbr, char *base_from, char *base_to);
int     flag_d(char *flag, va_list *arg);
int	flag_o(char *flag, va_list *arg);
int	flag_u(char *flag, va_list *arg);
int	flag_x(char *flag, va_list *arg);
int	flag_x_maj(char *flag, va_list *arg);
int	flag_s(char *flag, va_list *arg);
int	flag_s_maj(char *flag, va_list *arg);
int	flag_c(char *flag, va_list *arg);
int	flag_p(char *flag, va_list *arg);
int	flag_b(char *flag, va_list *arg);

/* my_printf_err */
int     my_printf_err(char *flags, ...);
int     read_flags_err(char **flags, char *ret_flag);
void    init_fct_err(char *char_flag, int (**fct)(char *, va_list *arg));
int     flag_d_err(char *flag, va_list *arg);
int     flag_o_err(char *flag, va_list *arg);
int     flag_u_err(char *flag, va_list *arg);
int     flag_x_err(char *flag, va_list *arg);
int     flag_x_maj_err(char *flag, va_list *arg);
int     flag_s_err(char *flag, va_list *arg);
int     flag_s_maj_err(char *flag, va_list *arg);
int     flag_c_err(char *flag, va_list *arg);
int     flag_p_err(char *flag, va_list *arg);
int     flag_b_err(char *flag, va_list *arg);

#endif
