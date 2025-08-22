#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

void fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int main(int ac, char **av)
{
	int sockfd, connfd;
	socklen_t addrlen;
	struct sockaddr_in servaddr, cliaddr;
	
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);	
	}
	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		fatal_error();
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal_error();
	else
		printf("Socket successfully binded..\n");

	if (listen(sockfd, 10) != 0)
		fatal_error();
	
	//aquí va el loop?
	while (1)
	{
		addrlen = sizeof(cliaddr);
		connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &addrlen);
		if (connfd < 0)
			fatal_error();
    		else
        		printf("server acccept the client...\n");
		//commenca la comunicació NO??
		printf("comunicat...............mostra sockfd: %d\nstruct servaddr.sin_port: %d\n", sockfd, servaddr.sin_port);
	}
	close(sockfd);
	return (0);
}
