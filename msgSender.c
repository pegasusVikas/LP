#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<sys/types.h>

struct msgbuf{
	long mtype;
	char msgtxt[100];
};

int main(){
struct msgbuf msg;
int msgid;
key_t key=10;
msg.mtype=1;
printf("enter message\n");
scanf("%s",msg.msgtxt);
if((msgid=msgget(key,0666|IPC_CREAT))==-1)
	perror("key generation fail");

if(msgsnd(msgid,&msg,sizeof(msg),0)==-1)
	perror("message send fail");
else
	printf("%s\n",msg.msgtxt);
}
