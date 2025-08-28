//#include <sys/socket.h>
//main(ac, av)
//check num arg != 2 -> retorna Wrong num arg exit(1)
//fdsocket = socket() AF_INET 127.0.0.1 SOCK_STREAM, 0 pero tria automaticament TCP, segons les deciscions de sock stream
//bind() .sin_addr.s_addr(atoi (port)) non-blocking all ip. si error fatal err exit 1
//loop infinit
	//listen(sockfd, buffer(num connex que aguanti)) o SOMAXCONN
	//si no funciona alguna fatal error
	//pots usar send i recv (ns que com suposso send per enviar msg, recv ns)
	//accept() i cres el sockaddr_in client abans
	//FD_ZERO() natejar set potser hauria de ser abans loop????
	//if ( !FD_ISSET() fdsocket) no es part dels set
		//FD_SET () affegeix al set
		//enviar msg al grup de "server: client %d just arrived\n" 
		//fer funció send msg == > loop (fd_isset( comprovar tots i enviar als que estiguin)
		//poder enviar msg generals amb funcio send_msg
		// msg pot tenir varis \n, devant de cada linea ha d'anar client %d
	//else if ha marxat o vol maxar desconectar -lo com se que marxa si fa exit o control c?? per borrar-lo faig FD_CLR()
		//s'enviaa a tots els clients "server: client %d just left\n"
//close de sdsocket
//return (0);

#define MAX_CLI 2000
#define MAX_BUF 1000000

typedef struct s_client {
	int id;
	char msg[MAX_BUF];
} t_client;

t_client all[MAX_CLI];
char str[MAX_BUF + 100], rec[MAX_BUF];

int sockfd = -1, maxfd = -1, gid = 0;
fd_set conj, rd, wr;

void err(char *msg)
{
	if (!msg)
		write(2, "Fatal error\n", strlen("Fatal error\n"));
	else
		write(2, msg, strlen(msg));
	if (sockfd != -1)
		close(sockfd);
	exit(1);
}

void send_all(int except)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &wr) && fd != except)
			send(fd, str, strlen(str), 0);
	}
}

int main(int ac, char **av)
{
	int connfd = -1;
	struct sockaddr_in servaddr;
	sockfd = -1;

	if (ac != 2)
		err("Wrong number of arguments\n");
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		err(NULL);
	bzero(&servaddr, sizeof(servaddr));

	FD_ZERO(&conj);
	FD_SET(sockfd, &conj);
	maxfd = sockfd;

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	memset(all, 0, sizeof(all));
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err(NULL);
	if (listen(sockfd, 100) != 0)
		err(NULL);
	while (1)
	{
		conj = rd = wr;
		if (select(maxfd + 1, &rd, &wr, 0, 0) <= 0)
			continue ;
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (!FD_ISSET(fd, &rd))
				continue ;
			if (fd == sockfd)
			{
				struct sockaddr_in cli;
				socklen_t len;
				len = sizeof(cli);
				bzero(&cli, sizeof(cli));
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd < 0)
					continue ;
				all[connfd].id = gid;
				gid++;
				if (maxfd < connfd)
					maxfd = connfd;
				FD_SET(connfd, &conj);
				sprintf(str, "server: client %d just arrived\n", all[connfd].id);
				send_all(connfd);
			} else {
				int ret = recv(fd, rec, 100, 0);
				if (ret <= 0)
				{
					sprintf(str, "server: client %d just left\n", all[fd].id);
					send_all(fd);
					memset(all[fd].msg, '\0', sizeof(all[fd.msg]));
					FD_CLR(fd, &conj);
					close(fd);
					break ;
				} else {
					rec[ret] = '\0';
					for (int i = 0, j = strlen(all[fd].msg); i < ret; i++, j++) 
					{
						all[fd].msg[j] = rec[i];
						if (all[fd].msg[j] == '\n')
						{
							all[fd].msg[j] = '\0';
							sprintf(str, "client %d: %s\n", all[fd].id, all[fd].msg);
							send_all(fd);
							memset(all[fd].msg, '\0', sizeof(all[fd].msg));
							j = -1;
						}
					}
				}
			}

		}
	}
	return (0);
}
