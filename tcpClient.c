#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

void main() {
	int csfd, dsfd;
	socklen_t size;
	struct sockaddr_in serversoc, clientsoc;
	char msg[50];
	csfd = socket(AF_INET, SOCK_STREAM, 0);
	serversoc.sin_family = AF_INET;
	serversoc.sin_port = htons(5001);
	serversoc.sin_addr.s_addr = htonl(INADDR_ANY);
	connect(csfd, (struct sockaddr *) &serversoc, sizeof(serversoc));
	send(csfd, "Hello from client\n", 50, 0);
	recv(csfd, msg, 50, 0);
	printf("%s", msg);
	close(csfd);
}
