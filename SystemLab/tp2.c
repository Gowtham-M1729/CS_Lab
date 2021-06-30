#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void *sum(void *arg);
void *mul(void *arg);
int sm=0, prod=1;
void main(int argc, char * argv[])
{
  pthread_t T1,T2;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
    
  pthread_create(&T1, &attr, sum, argv[1]);
  pthread_create(&T2, &attr, mul, argv[1]);
 pthread_join(T1,NULL);
  pthread_join(T2,NULL);
 // wait(NULL);
  printf("Inside main thread\n");
  printf("sum=%d\n",sm);
  printf("product=%d\n",prod);
 }
void *sum(void *parm) 
{ 
  int i, n=2; 
   n = atoi(parm);
  printf("inside  sum thread\n");
  
  for(i=1; i<=n;i++)
  {
    sm+=i;
     
  }
 printf("sum thread completed\n");
}
void *mul(void *parm)
{
  int i, n=3;
  n = atoi(parm);
  printf("inside mul thread\n");
  for(i=2; i<=n;i++)
  {
    prod =prod *i;
    
  }
  printf("mul thread completed  product\n");
}
