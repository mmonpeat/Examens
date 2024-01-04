#ifndef MICROSHELL_H
# define MICROSHELL_H

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

# define E_EXIT  1
# define ERROR   -1

typedef struct s_micro
{
  int i;
  int num_pross;
  int pid;
  int fd[2];
  int tmp_fd;
} t_micro;

int main(int ac, char **av, char **env);
void is_cd(char **av, char **env);
int no_pipe(t_micro *sh, char **av, char **env);
int is_pipe(t_micro *sh, char *av, char **env);
int ft_executor(t_micro *sh, char **av, char **env);
int fd_putstr(int fd, char *str);

#endif
