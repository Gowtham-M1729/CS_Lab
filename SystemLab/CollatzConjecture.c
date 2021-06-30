#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char *argv[] )
{
	pid_t pid;
    printf("arg[0] is %s\n",argv[0]);
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
		int ans = 0, i, j, k = 2, n;
		n = atoi(argv[1]);
		printf("%d ",n);
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
	   }
     printf("\n");

	}


	else
	{
		wait(NULL);
		printf("Returned to parent Process...\n");
		printf("Done\n");
	}
}

