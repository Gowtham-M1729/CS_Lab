
#include <stdio.h>
#include <stdlib.h>
#include<sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>
#include<string.h>
int main ()
{
	int num;
	pid_t pid;
	pid = getpid();
	pid = fork();
	key_t key = ftok("shmfile",65);
	// shmget returns an identifier in shmid
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	// shmat to attach to shared memory
	char *str = (char*)shmat(shmid,(void*)0,0);
	if (pid < 0) 
	{
		perror("fork() failure\n");
		return 1;
	}
	// Child process
	if (pid == 0) 
	{
		printf("This is child process\n");
		execlp("./largeshmget1","largeshmget1",NULL);
	} 
	else 
	{ 	// Parent process
		printf("\nParent waiting\n"); 
		wait(NULL);
		printf("Finished waiting\n");
		printf("Data read from memory:\n%s\n",str);    
		shmdt(str);
		shmctl(shmid,IPC_RMID,NULL);
	}
	return 0;
}
