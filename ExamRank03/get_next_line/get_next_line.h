#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//gcc -Wall -Wextra -Werror -g -fsanitize=address -D BUFFER_SIZE=10 get_next_line.c get_next_line.h


char *get_next_line(int fd);
char *read_fd(int fd, char *buf, int bt);
char *pt_join(char *buf, char *rd);
char *ft_line(char *buf, char *line);
char *next_buf(char *buf);
char *ft_strjoin(char *s1, char *s2);
char *clear(char **p1, char **p2);
char *ft_strchr(char *str, char c);
void *ft_calloc(int count, int size);
int ft_strlen(char *str);

#endif
