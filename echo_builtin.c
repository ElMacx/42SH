/*
** echo_builtin.c for 42sh in /home/laffar_a/Documents/42sh
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Sun May 25 02:33:08 2014 Antoine Laffargue
** Last update Tue May 27 20:25:40 2014 aufrere guillaume
*/

#include "mysh.h"

int	echo_builtin(char **cmd)
{
  int	i;
  int	mode;

  i = 1;
  while (cmd[i])
    {
      if (i == 1)
	mode = get_mode(cmd[i]);
      if (mode == 4)
	{
	  echo_help();
	  exit(0);
	}
      if (mode && i == 1)
	i++;
      if (write_string(cmd[i], mode) == -1)
	exit(0);
      if (cmd[i + 1])
	my_putchar(' ');
      i++;
    }
  if (mode != 2)
    my_printf("\n");
  return (0);
}

int	get_mode(char *str)
{
  if (my_strcmp("-E", str) == 0)
    return (1);
  if (my_strcmp("-n", str) == 0)
    return (2);
  if (my_strcmp("-e", str) == 0)
    return (3);
  if (my_strcmp("--help", str) == 0)
    return (4);
  return (0);
}

int	write_string(char *str, int mode)
{
  int	i;
  char	c;

  i = 0;
  c = 0;
  while (str[i] != '\0')
    {
      if (mode == 3)
	c = get_char_value(&str[i]);
      if (c == -2)
	return (-1);
      if (mode != 3 || c == -1)
        c = str[i];
      else if (c)
	i++;
      my_putchar(c);
      i++;
    }
  return (0);
}

char	get_char_value(char *str)
{
  if (my_strncmp("\\\\", str, 2) == 0)
    return ('\\');
  if (my_strncmp("\\a", str, 2) == 0)
    return ('\a');
  if (my_strncmp("\\b", str, 2) == 0)
    return ('\b');
  if (my_strncmp("\\c", str, 2) == 0)
    return (-2);
  if (my_strncmp("\\e", str, 2) == 0)
    return ('\e');
  if (my_strncmp("\\f", str, 2) == 0)
    return ('\f');
  if (my_strncmp("\\n", str, 2) == 0)
    return ('\n');
  if (my_strncmp("\\r", str, 2) == 0)
    return ('\r');
  if (my_strncmp("\\t", str, 2) == 0)
    return ('\t');
  if (my_strncmp("\\v", str, 2) == 0)
    return ('\v');
  return (-1);
}

void	echo_help()
{
  my_printf("NAME\n\techo - display a line of text\n\n");
  my_printf("SYNOPSIS\n\techo [SHORT-OPTION]...");
  my_printf(" [STRING]...\n\techo LONG-OPTION\n\n");
  my_printf("\techo LONG-OPTION\n\n");
  my_printf("DESCRIPTION\n\tEcho the STRING(s) to standard output.\n\n");
  my_printf("\t-n\tdo not output the trailing newline\n");
  my_printf("\t-e\tenable interpretation of backslash escapes\n");
  my_printf("\t-E\tdisable interpretation of backslash escapes (default)\n");
  my_printf("\t--help\tdisplay this help and exit\n\n");
  my_printf("\tIf -e is in effect, the following sequences are");
  my_printf(" recognized:\n\n");
  my_printf("\t\\\\\tbackslash\n");
  my_printf("\t\\a\talert (BEL)\n");
  my_printf("\t\\b\tbackspace\n");
  my_printf("\t\\c\tproduce no further output\n");
  my_printf("\t\\e\tescape\n");
  my_printf("\t\\f\tform feed\n");
  my_printf("\t\\n\tnew line\n");
  my_printf("\t\\r\tcarriage return\n");
  my_printf("\t\\t\thorizontal tab\n");
  my_printf("\t\\v\tvertical tab\n\n");
}
