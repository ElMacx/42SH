##
## Makefile for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
## 
## Made by Antoine Laffargue
## Login   <laffar_a@epitech.net>
## 
## Started on  Mon Dec  9 13:18:24 2013 Antoine Laffargue
## Last update Wed Feb  4 19:46:48 2015 Maxime DULIN
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

LIB	= -L lib/ -lmy

CFLAGS	= -I include/

SRCS	= main.c \
	  execute_cmd.c \
	  env.c \
	  builtins.c \
	  echo_builtin.c \
	  cd_tools.c \
	  cd_tools_2.c \
	  cd_history.c \
	  setenv_tools.c \
	  signal_tools.c \
	  parsing.c \
	  parsing_exe.c \
	  parsing_error.c \
	  replace_var.c \
	  list_tools.c \
	  redirect.c \
	  error.c

OBJS	= $(SRCS:.c=.o)

DEBUG	= no

ifeq ($(DEBUG), yes)
	CFLAGS	+= -W -Wall -Wextra -g3

endif

all: libmy $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) -l:libmy_malloc_pc-dulin_m.so

libmy:
	make -C ./lib/

clean:
	make -C ./lib/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./lib/ fclean
	$(RM) $(NAME)

re: fclean libmy all

.PHONY: re fclean clean libmy all
