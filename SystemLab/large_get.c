#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{

        int n,a[50],i;
	key_t key = ftok("shmfile",65);
	// shmget returns an identifier in shmid
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	// shmat to attach to shared memory
	char *str = (char*) shmat(shmid,(void*)0,0);
	printf("\n Enter the Upper limit for Array \n");
        scanf("%d",&n);
        printf("\n Enter the Array elements\n");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        int large=a[0];
        for(i=0;i<n;i++)
        {
         if(a[i]>large)
         large=a[i];
        }
        sprintf(str," %d ",large);
        
	return 0;
}	
