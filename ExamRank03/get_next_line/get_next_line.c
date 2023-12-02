
//totes les funcions
int main(void)
{
        int fd = open("test.txt", O_RDONLY);
        if (fd < 0)
                return (0);
        char *line = "";
        int i = 1;
        while (line)
        {
                line = get_next_line(fd);
                printf("num[%d]: %s\n", i++, line);
                free(line);
        }
        free(line);
        return (0);
}

char *get_next_line(int fd)
{
        static char *buf = NULL;
        char *line = NULL;
        int bt = 1;

        if (fd < 0 || BUFFER_SIZE <= 0)
        {
                if (buf)
                        return(clear(&buf, NULL));
                return (NULL);
        }
        if (!buf)
                buf = ft_calloc(1, 1);
        if (!buf)
                return(clear(&buf, NULL));
        buf = read_fd(fd, buf, bt);
        if (!buf)
                return (NULL);
        line = ft_line(buf, line);
        if (!line || *line == '\0')
                return (clear(&buf, &line));
        buf = next_buf(buf);
        return (line);
}

char *read_fd(int fd, char *buf, int bt)
{
        char *tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        if (!tmp)
                return (clear(&buf, &tmp));
        while (bt > 0)
        {
                bt = read(fd, tmp, BUFFER_SIZE);
                if (bt < 0)
                        return (clear(&buf, &tmp));
                tmp[bt] = '\0';
                buf = pt_join(buf, tmp);
                if (!buf)
                        return (NULL);
                if (ft_strchr(tmp, '\n'))
                        break;
        }
        clear(&tmp, NULL);
        return(buf);
}

char *ft_line(char *buf, char *line)
{
        int len = 0;
        if (!buf[len])
                return(NULL);
        while (buf[len] && buf[len] != '\n')
                len++;
        if (buf[len] == '\n')
                len++;
        line = ft_calloc(len + 1, sizeof(char));
        if (!line)
                return (NULL);
        len = 0;
        while (buf[len] && buf[len] != '\n')
        {
                line[len] = buf[len];
                len++;
        }
        if (buf[len] == '\n')
                line[len] = '\n';
        return (line);
}

char *next_buf(char *buf)
{
        int len = 0;
        int i = 0;

        while(buf[len] && buf[len] != '\n')
                len++;
        if (!buf[len])
                return (clear(&buf, NULL));
        char *new = ft_calloc(ft_strlen(buf) - len + 1, sizeof(char));
        if (!new)
                return(clear(&buf, NULL));
        len++;
        while (buf[len])
                new[i++] = buf[len++];
        clear(&buf, NULL);
        return (new);
}

char *pt_join(char *buf, char *rd)
{
        char *tmp = ft_strjoin(buf, rd);
        if (!tmp)
                return (clear(&buf, &rd));
        clear(&buf, NULL);
        return (tmp);
}
char *ft_strjoin(char *s1, char *s2)
{
        char *new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
        if (!new)
                return (NULL);
        int i = 0;
        int j = 0;
        while (s1[i])
                new[i++] = s1[j++];
        j = 0;
        while (s2[i])
                new[i++] = s2[j++];
        new[i] = '\0';
        return (new);
}

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
char *ft_strchr(char *str, char c)
{
        int i = 0;
        while (str[i])
        {
                if (str[i] == c)
                        return (&str[i]);
                i++;
        }
        if (c == '\0')
                return (str);
        return (NULL);
}

void *ft_calloc(int count, int size)
{
        int i = 0;
        int len = count * size;
        void *mem = malloc(len);

        if (!mem)
                return (0);
        while (i < len)
                ((char *)mem)[i++] = 0;
        return (mem);

}

int ft_strlen(char *str)
{
        int i = 0;
        while(str[i])
                i++;
        return (i);
}
