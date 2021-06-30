#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void * threadfun();
int i, j, n;
void main()
{
  pthread_t T1;
  pthread_create(&T1, NULL, threadfun, NULL);
  //pthread_join(T1,NULL);
  printf("Inside main thread\n");
  printf("Hi.....\n");
  for(i=10; i<=15;i++)
  {
   printf("%d\n",i);
   //sleep(1);
  }
 }
void * threadfun() 
{  
  printf("inside thread\n");
  for(j=1; j<=5;j++)
  {
   printf("%d\n",j);
   //sleep(1);
  }
}
