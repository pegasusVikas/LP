#include<sys/*.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<stdlib.h>

int main(){
struct stat st;
struct passwd *pw;
struct group *gr;
if(stat("Text.txt",&st)<0)
	printf("stat error");
if(S_ISREG(st.st_mode))
	printf("-");
else if(S_ISDIR(st.st_mode))
	printf("d");
else if(S_ISBLK(st.st_mode))
	printf("b");
else if(S_ISCHR(st.st_mode))
	printf("c");
else if(S_ISFIFO(st.st_mode))
	printf("p");
else if(S_ISLNK(st.st_mode))
	printf("l");
else if(S_ISSOCK(st.st_mode))
	printf("s");

if(S_IRUSR&st.st_mode)
	printf("r");
else
	printf("-");

if(S_IWUSR&st.st_mode)
	printf("w");
else
	printf("-");

if(S_IXUSR&st.st_mode)
	printf("x");
else
	printf("-");

if(S_IRGRP&st.st_mode)
	printf("r");
else
	printf("-");

if(S_IWGRP&st.st_mode)
	printf("w");
else
	printf("-");

if(S_IXGRP&st.st_mode)
	printf("x");
else
	printf("-");

if(S_IROTH&st.st_mode)
	printf("r");
else
	printf("-");

if(S_IWOTH&st.st_mode)
	printf("w");
else
	printf("-");

if(S_IXOTH&st.st_mode)
	printf("x");
else
	printf("-");

printf("%d",(int)st.st_nlink);
pw = getpwuid(st.st_uid);
gr = getgrgid(st.st_gid);
printf("%s",pw->pw_name);
printf("%s",gr->gr_name);
printf("%ld",(long)st.st_size);
printf("%s",ctime(&st.st_ctime));
printf("\n");
}
