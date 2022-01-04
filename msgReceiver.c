#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<string.h>
struct msgbuf{
long msgtype;
char msgtxt[100];
};
void main(){
struct msgbuf msg;
int msgid;
key_t key = 10;

if((msgid=msgget(key,0666))==-1)
	perror("msgid generation error");

if(msgrcv(msgid,&msg,sizeof(msg),1,0)==-1)
	perror("error in sending message\n");
else
	printf("received: %s\n",msg.msgtxt);


}
