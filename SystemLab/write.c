#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd1,fd2,n;
    char buf[30];

    fd1 = open("test.txt",O_RDONLY);
    n = read(fd1,buf,2);
    //system("rm target.txt");
    fd2 = open("target.txt",O_CREAT | O_WRONLY,0642);
    printf("Writing into file...\n");
    write(fd2,buf,n);
    
    printf("Finished writing into \"target.txt\" ");

    return 0;
}
