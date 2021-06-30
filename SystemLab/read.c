#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char buf[30];
	int fd1 = open("sample.txt", O_RDONLY );
    int n=read(fd1,buf,sizeof(buf));
	write(1,buf,n);
	exit(0);
}
