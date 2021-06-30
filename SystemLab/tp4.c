#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *sum(void *arg);
int a[5]={1,2,3,4,5};
//int sm=0;

void main()
{
  int *res;
  pthread_t T1;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&T1, &attr, sum, a);
  pthread_join(T1,(void *)&res);
  printf("Inside main thread\n");
  printf("sum=%d\n",*res);
 // printf("thread returned: %s\n",(char *)res);
 }
void *sum(void *parm) 
{ 
  int i, *sm; 
   //n = atoi(parm);
   int *x=parm;
   printf("inside thread\n");
   sm=malloc(sizeof(int));
   for(i=0;i<5;i++)
    *sm=  *sm + x[i]; 
      
 pthread_exit((void *)sm);  

}
