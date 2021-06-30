#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<fcntl.h>
int main(){
  char buf[30];
  int n,l,fd;
  fd=open("Seek",O_RDWR);
  n=read(fd,buf,10);
  write(1,buf,n);
  printf("\n");
  lseek(fd,10,SEEK_CUR);
  n=read(fd,buf,10);
  write(1,buf,n);
  printf("\n");
  lseek(fd,10,SEEK_SET);
  n=read(fd,buf,10);
  write(1,buf,n);
  printf("\n");
  /*
  lseek(fd,1,SEEK_CUR);
  n=read(fd,buf,1);
  write(1,buf,n);
  printf("\n");
  lseek(fd,0,SEEK_SET);
  n=read(fd,buf,2);
  write(1,buf,n);
  printf("\n");*/
  lseek(fd,-11,SEEK_END);
  n=read(fd,buf,10);
  write(1,buf,n);
  printf("\n");
  lseek(fd,10,SEEK_CUR);
  n=read(fd,buf,10);
  write(1,buf,n);
  
return 0;
}
