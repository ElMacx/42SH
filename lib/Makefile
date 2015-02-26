##
## Makefile for lib in /home/laffar_a/rendu/Piscine-C-lib/my
## 
## Made by Antoine Laffargue
## Login   <laffar_a@epitech.net>
## 
## Started on  Mon Oct 21 10:29:46 2013 Antoine Laffargue
## Last update Sun May 25 20:10:00 2014 maxime dulin
##

NAME	= libmy.a

SRCPATH	= src/

CFLAGS  = -I ../include/

SRCS	= $(SRCPATH)my_putchar.c \
	  $(SRCPATH)my_isneg.c \
	  $(SRCPATH)my_put_nbr.c \
	  $(SRCPATH)my_swap.c \
	  $(SRCPATH)my_putstr.c \
	  $(SRCPATH)my_strlen.c \
	  $(SRCPATH)my_getnbr.c \
	  $(SRCPATH)my_sort_int_tab.c \
	  $(SRCPATH)my_power.c \
	  $(SRCPATH)my_square_root.c \
	  $(SRCPATH)my_is_prime.c \
	  $(SRCPATH)my_find_prime_sup.c \
	  $(SRCPATH)my_strcpy.c \
	  $(SRCPATH)my_strncpy.c \
	  $(SRCPATH)my_revstr.c \
	  $(SRCPATH)my_strstr.c \
	  $(SRCPATH)my_strcmp.c \
	  $(SRCPATH)my_strncmp.c \
	  $(SRCPATH)my_strupcase.c \
	  $(SRCPATH)my_strlowcase.c \
	  $(SRCPATH)my_strcapitalize.c \
	  $(SRCPATH)my_str_isalpha.c \
	  $(SRCPATH)my_str_isnum.c \
	  $(SRCPATH)my_str_islower.c \
	  $(SRCPATH)my_str_isupper.c \
	  $(SRCPATH)my_str_isprintable.c \
	  $(SRCPATH)my_showstr.c \
	  $(SRCPATH)my_showmem.c \
	  $(SRCPATH)my_strcat.c \
	  $(SRCPATH)my_strncat.c \
	  $(SRCPATH)my_strlcat.c \
	  $(SRCPATH)my_printf.c \
	  $(SRCPATH)my_printf_func.c \
	  $(SRCPATH)my_printf_func2.c \
	  $(SRCPATH)my_printf_err.c \
	  $(SRCPATH)my_printf_func_err.c \
	  $(SRCPATH)my_printf_func2_err.c \
	  $(SRCPATH)nb_to_str_tools.c \
	  $(SRCPATH)convert_base.c \
	  $(SRCPATH)my_realloc.c \
	  $(SRCPATH)my_str_to_wordtab.c \
	  $(SRCPATH)my_sort_wordtab.c \
	  $(SRCPATH)get_next_line.c \
	  $(SRCPATH)to_tab.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
