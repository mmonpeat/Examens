#include "microshell.h"

#include <stdio.h>

int main (int ac, char **av, char **env)
{
	int i = 0;
	int status = 0;

	if (ac > 1)
	{
		while (av[i] && av[i + 1])
		{
			av += i;
			printf("av: %s\n", *av);
			i = 0;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))//pq no || ??
				i++;
			printf("av: %s\n", *av);
			if (strcmp(av[i], "cd")
				status = cd(av, i);
			else if (i)
				status = executor(av, env, i);
		}
	}
	return (status);
}

int cd(char **av, int i)
{
	if ( i != 2)
		return (error("error: cd: bad arguments\n");
	else if (chdir(av[1]) == -1)
		return (error("error: cd: connot change directory to ", error(av[1]), error(av[1]);
	return (0);
}

int executor(char **av, int i)
{
	int fd[2];
	int status;
	int has_pipe = av[i] && !strcmp(av[i], "|");
	/*
	int is_pipe(char **av, int i)
	{
		if (av[1] && !strcmp(av[i], "|");	
			return (1);
		return (0);
	}
	int has_pipe = is_pipe(av, i);
	*/
	if (has_pipe && pipe(fd) == -1)//si hi ha una pipe, crea la pipe amb pipe()
		return (error("error: fatal\n"));
	
	int pid = fork();
	if (pid == 0)
	{
		av[i] = 0;//Afegim un 0 al final del array d'arguments per indicar el final de la comanda
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1] == -1))
				return (error("error: fatal\n"));
		execve(*av, av, env);
		return (error("error: cannot execute ", error(*av), error("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error("error: fatal\n");
	return (WIFEXITED(status) && WEXITSTATUS(status));
	//La macro WIFEXITED comprova si el procés fill ha finalitzat normalment, i WEXITSTATUS proporciona el codi de sortida del procés fill.
}

int error(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}
