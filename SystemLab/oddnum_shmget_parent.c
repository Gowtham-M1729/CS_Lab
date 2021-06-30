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
		printf("Enter upper limit\n");
		scanf("%d",&num);
		int length = snprintf( NULL, 0, "%d", num );
		char* st = malloc( length + 1 );
		snprintf( st, length + 1, "%d", num );
		char *args[]={"./oddshmget2",st,NULL};
		execvp(args[0],args);
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
