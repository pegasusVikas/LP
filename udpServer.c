#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>

int main() {
   int sfd, cfd;
   char buf[1024];
   struct sockaddr_in server, client;
   sfd = socket(AF_INET, SOCK_DGRAM, 0);

   server.sin_family = AF_INET;
   server.sin_port = htons(5007);
   inet_aton("127.0.0.1", &server.sin_addr);
   int b = bind(sfd, (struct sockaddr *) &server, sizeof (server));
   printf("BIND VALUE:%d\n", b);
   int l = sizeof (client);
 
      recvfrom(sfd, buf, 1024, 0, (struct sockaddr *) &client, &l);
      
      sendto(sfd, buf, sizeof(buf), 0, (struct sockaddr *) &client, sizeof (client));
      printf("MESSAGE FROM CLIENT:%s\n", buf);

   close(sfd);
}

