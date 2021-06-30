#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
#include <sys/wait.h>

int main(int argc , char *argv[] )
{   
    int ans = 0, i, j, k = 2, n;
    char buf[30];
    n = atoi(argv[1]);
    void *psm;
    int shmid;
	pid_t pid;

	if (argc != 2)
	{
		printf("arg missing or exceeding\n");
		exit(0);
	}
	if ( atoi ( argv[1] ) <0 )
	{
		printf("negative number entered %d", atoi(argv[1]));
		exit(0);
	}

	pid=fork();

	if ( pid<0 )
	{
		printf("Failed to create child\n");
		exit(0);
	}

	else if ( pid==0 )
	{  
		printf("Working in Child Process...\nThe Resulting Series Will be:\n");
		
      
        shmid=shmget((key_t)1122, 1024, 0666|IPC_CREAT);
        //psm=mmap(0,1024,PROT_WRITE, MAP_SHARED, shmid1, 0);
        //printf("Key of the shared memory: %d\n",shmid1);
        psm=shmat(shmid, NULL, 0666);
        printf("process attached at:%p\n",psm);
        printf("Enter some data to write to shared memory\n");
        //read(0,buf,10);
        printf("%d ",n);
        sprintf(psm,"%d ",n);
        //psm += strlen(message0);
		psm+=strlen(psm);
		while(n!=1)
		{
		   if(n%2==0)
		   {
		       n=n/2;
		   }
		   else
		   {
		       n=3*n+1;
		   }
		   printf("%d ",n);
		   sprintf(psm,"%d ",n);
		   psm+=strlen(psm);
	   }
	   printf("\n");
	   psm=NULL;
       
	}


	else
	{
		wait(NULL);
		printf("Returned to parent Process...\n");
		shmid=shmget((key_t)1122, 1024, 0666|IPC_CREAT);
		//shmid1=shm_open("OS",O_RDONLY, 0666);
        //ftruncate(shmid1,1024);
        //psm=mmap(0,1024,PROT_READ, MAP_SHARED, shmid1, 0);
        //printf("Key of the shared memory: %d\n",shmid1);
        psm=shmat(shmid, NULL, 0666);
        printf("process attached at:%p\n",psm);
        //printf("enter some data to write to shared memory\n");
        //read(0,buf,10);
        //sprintf(psm,"%s",buf);
        printf("%s ",(char*)psm);
        //shm_unlink("OS");
        shmctl(shmid,IPC_RMID,NULL);
		printf("Done\n");
	}
}

