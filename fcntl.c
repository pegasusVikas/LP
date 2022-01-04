#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main(){
int fd;
fd = open("./sample.txt",O_WRONLY);
int flag1 = fcntl(fd,F_GETFL);
printf("%d\n",flag1);
int flag2 = fcntl(fd,F_SETFL,O_APPEND);
int flag3 = fcntl(fd,F_GETFL);
printf("%d\n",flag3);
close(fd);
}
