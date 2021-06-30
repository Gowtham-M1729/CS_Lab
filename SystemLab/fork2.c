#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void)
{
    pid_t pid;
    pid = fork();
    printf("My child id : %d\n",pid);
    
    if(pid==0)
    {
        wait(NULL);
         sleep(2);
        printf("Child : \n");
        printf("I'm child with id : %d\n",getpid());
        printf("My parent id : %d\n",getppid());
    }
    else
    {
        printf("Parent : \n");
        printf("I'm parent with id : %d\n",getpid());
        printf("My child id : %d\n",pid);
    }
}
