#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
int fd1,fd2;
char buf[20];
fd1=open("./sample.txt",O_RDONLY|O_CREAT,0666);
fd2=open("./copy.txt",O_WRONLY|O_CREAT,0666);
read(fd1,buf,sizeof(buf));
write(fd2,buf,sizeof(buf));
close(fd1);
close(fd2);
}
