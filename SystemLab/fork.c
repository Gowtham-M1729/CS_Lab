#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 #include <sys/wait.h>
int main()
{
	pid_t child_pid = fork();
	if (child_pid ==0)
	{ printf("In Child Process...\n");
      printf("I'am Child my id is %d\n",getpid());
	  printf("My parent's Id is %d\n",getppid());
	}
		//sleep(50);
	else{
	  sleep(4);
	  //wait(NULL);
	  printf("In Parent Process...\n");
	  printf("I'am Parent my id is %d\n",getpid());
	  printf("My child's Id is %d\n",child_pid);
	  exit(0);
	  }
	  
	return 0;
}
