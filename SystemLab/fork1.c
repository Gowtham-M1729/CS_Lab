// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the
// child process is running. The child process
// becomes orphan.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	// Create a child process	
	int pid = fork();

	if (pid > 0){
	    
	     printf("I'am Parent my id is %d\n",getpid());
		printf("in parent process\n");
		 //wait(NULL);
		}

	// Note that pid is 0 in child process
	// and negative if fork() fails
	else if (pid==0)
	{   //printf("Parent  id is %d\n",getppid());
		//sleep(1);
		 sleep(4);
		printf("I'am Child my id is %d\n",getpid());
	   printf("My parent's Id is %d\n",getppid());
		printf("in child process");
	}

	return 0;
}

