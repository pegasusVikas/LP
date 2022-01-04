#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	int s_sockfd, c_sockfd;
	socklen_t size;
	char msg[50];
	struct sockaddr_in serversoc, clientsoc;
	s_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serversoc.sin_family = AF_INET;
	serversoc.sin_port = htons(5001);
	serversoc.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(s_sockfd, (struct sockaddr*) &serversoc, sizeof(serversoc));
	listen(s_sockfd, 10);
	c_sockfd = accept(s_sockfd, (struct sockaddr*) &clientsoc, &size);
	recv(c_sockfd, msg, 50, 0);
	printf("%s", msg);
	send(c_sockfd, "Hello from server\n", 50, 0);
	close(c_sockfd);
}
