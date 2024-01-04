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
  int n_p;
  int pid;
  int fd[2];
  int tmp_fd;
} t_micro;

#endif
