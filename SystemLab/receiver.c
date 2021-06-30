#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
int main()
{
 void *psm;
 char buf[10];
 int shmid1;
 //shmid=shmget((key_t)1122, 1024, 0666|IPC_CREAT);
 shmid1=shm_open("OS",O_RDONLY, 0666);
 ftruncate(shmid1,1024);
 psm=mmap(0,1024,PROT_READ, MAP_SHARED, shmid1, 0);
 printf("Key of the shared memory: %d\n",shmid1);
 //psm=shmat(shmid, NULL, 0666);
 printf("process attached at:%p\n",psm);
 //printf("enter some data to write to shared memory\n");
 //read(0,buf,10);
 //sprintf(psm,"%s",buf);
 printf("%s",(char*)psm);
 //shm_unlink("OS");
 shmctl(shmid1,IPC_RMID,NULL);


 return 0;
} 
