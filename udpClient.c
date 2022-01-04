#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
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
   
   int l = sizeof (client);

      printf("ENTER string\n");
      scanf("%s", buf);
      sendto(sfd, buf, sizeof(buf), 0, (struct sockaddr *) &server, sizeof (server));
      recvfrom(sfd, buf, 1024, 0, NULL, NULL);
      printf("RECEIVED FROM SERVER:%s\n", buf);

   close(sfd);
}

