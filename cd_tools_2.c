/*
** cd_tools_2.c for  in /home/aufrer_g/rendu/42sh
** 
** Made by aufrere guillaume
** Login   <aufrer_g@epitech.net>
** 
** Started on  Tue May 27 20:26:41 2014 aufrere guillaume
** Last update Tue May 27 20:27:07 2014 aufrere guillaume
*/

#include "mysh.h"

int     check_env_2(char **cmd, char ***my_env, char **home)
{
  int   ret;

  ret = 1;
  if (*home)
    ret = cd_builtin(cmd, my_env);
  else
    create_home(my_env);
  return (ret);
}
