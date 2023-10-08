char *get_next_line(int fd);
char *read_fd(int fd, char *buf, int bt);
char *clear(char **p1, char **p2); 
void *ft_calloc(int count, int size);

char *get_next_line(int fd)
{
	static char *buf = NULL;



	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		//ja s'ha reservat memoria en una crida anterior
		if (buf)
			return(clear(&buf, NULL));
		return(NULL);	
	}
	if (!buf)
		buf = ft_calloc(1, 1);//reservar 1byte de memoria
	if (!buf)
		return(clear(&buf, NULL));

}
/*
Allibera la memòria apuntada pels punters que es passen com a arguments, si aquests punteros no són NULL.

Comprova si p1 és un punter vàlid (no és NULL) i si el que apunta (*p1) no és NULL. Si és així, allibera la memòria apuntada per *p1 amb free i estableix *p1 a NULL per evitar referències a memòria alliberada.
*/
char *clear(char **p1, char **p2)
{
	if (p1 && *p1)
	{
		free(*p1);
		*p1 = NULL;
	}
	if (p2 && *p2)
	{
		free(*p2);
		*p2 = NULL;
	}
	return (NULL);
}
void *ft_calloc(int count, int size)
{
	int len = count * size;
	void *mem = malloc(len);
	if (!mem)
		return (0);
	int i = 0;
	while (i < len)
		((char*)mem)[i++] = 0;
	return (mem);
}
