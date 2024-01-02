#ifndef MICROSHELL_H
# define MICROSHELL_H

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env);
int cd(char **av, int i);
int executor(char **av, char **env, int i);
int err(char *str);

#endif
