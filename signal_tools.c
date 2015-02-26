/*
** signal_tools.c for mysh in /home/laffar_a/rendu/PSU_2013_minishell1
**
** Made by Antoine Laffargue
** Login   <laffar_a@epitech.net>
**
** Started on  Thu Dec 19 15:47:13 2013 Antoine Laffargue
** Last update Wed May 28 09:00:14 2014 maxime dulin
*/

#include "mysh.h"

void	ctrl_c_fct()
{
  write(0, "\n", 1);
  my_printf("$> ");
}

void	catch_exit_signal_2(int status, t_pipe *p)
{
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
    my_printf_err("Segmentation fault\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGHUP)
    my_printf_err(RED"Hangup\t%s\n"DEFAULT, p->exe.cmd[0]);
}

void	catch_exit_signal(int status, t_pipe *p)
{
  catch_exit_signal_2(status, p);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
    my_printf_err(RED"Quit\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGILL)
    my_printf_err(RED"Illegal Instruction\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGIOT ||
			      WTERMSIG(status) == SIGABRT))
    my_printf_err(RED"Aborted\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGKILL)
    my_printf_err(RED"Killed\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGBUS)
    my_printf_err(RED"Bus Error\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE)
    my_printf_err(RED"Floating Point Exception\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSTKFLT)
    my_printf_err(RED"Stack Fault\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGUSR1)
    my_printf_err(RED"User Signal 1\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGUSR2)
    my_printf_err(RED"User Signal 2\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGTERM)
    my_printf_err(RED"Terminated\t%s\n"DEFAULT, p->exe.cmd[0]);
  if (WIFEXITED(status) || WIFSIGNALED(status))
    p->exit_status = status;
}
