//no pots declarar nmacros ni llibreria (#define)

//arg != 2 -> retorna Wrong num arg exit(1)
//si socket, bind, listen va malament -> retona fatal eror exit(1)
//si no pots guardar mem -> retorna fatal error exit(1)
//non bloking bind
//bind i socket en localhost

//si el client no llegeix el msg NO el pots desconectar

//el fd que rebs del socket (crec) ha d'estar preparat per fer recv o send per bloquejar, si select no s'ha cridat abans del recv o send. pero si el select esta abans del recv o send no boqueja res. ????

// client té id, el primer client id = 0, segon cli id = 1, ... 
// mgs s'envia a tos els clients conectats al servidor "server: client %d just arrived\n" %d es subtitues per el id del client, 0, 1, 2
// clients han de poder enviar msg al seerver, no chal check que s'envia
// msg pot tenir varis \n, devant de cada linea ha d'anar client %d
// client id = 3 es deconecta del servidor s'envia un msg a tots els clients conectats al servidor : "server: client %d just left\n"

// send utilitzar nomes quan el socket esta connectat. send( no te flags com args) pero write si.

//macros:
	//FD_ZERO() --> nateja el conjunt (no nateja el fd)
	//DF_SET() --> afegeix el fd al conjunt en el que hi ha altres clients
	//FD_CLR() --> elimina el fd del conjunt
	//FD_ISSET() --> mira si un fd es part del set(conjunt) al enviar msg puc fer un loop del per conprovar si es part del set i enviar msg sino hoo es surt del loop ino envia res pero seguiria en el loop del set, de socketfd. util despres de selects() ns com va exactament

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
