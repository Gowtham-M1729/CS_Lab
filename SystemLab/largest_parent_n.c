#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>

#include<sys/mman.h>
#include<string.h>
int main ()
{
	int num;
	pid_t pid;
        //pid = getpid();
	pid = fork();
	int shmfd = shm_open("sharedmemory",O_CREAT|O_RDWR,0666);
	ftruncate(shmfd,4096);
	char *str = mmap(0,4096,PROT_WRITE,MAP_SHARED,shmfd,0);
	if (pid < 0)
	{
	perror("fork() failure\n");
	return 1;
	}
	// Child process
	if (pid == 0)
	{
	printf("This is child process\n");
	
	execlp("./largeshmopen1","largeshmopen1",NULL);
	}
	else
	{ // Parent process
	printf("\nParent waiting\n");
	wait(NULL);
	printf("Finished waiting\n");
	printf("Data read from memory:\n%s\n",(char*)str);
	shm_unlink("sharedmemory");
	}
	return 0;
}
