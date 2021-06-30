#include<stdio.h>
 
struct proc
{
 int arr_time;
 int burst_time;
 int no;
 int rem_time;
 int priority;
};
 
 
struct proc read(int i)
{
 struct proc p;
 printf("\n\n The process no.:%d.\n",i);
 p.no=i;
 printf("Enter the arrival time:");
 scanf("%d",&p.arr_time);
 printf("Enter the burst time:");
 scanf("%d",&p.burst_time);
 p.rem_time=p.burst_time;
 return p;
}
 
 
 
struct proc readp(int i)
{
 struct proc p;
 printf("\n\n The process no.:%d.\n",i);
 p.no=i;
 printf("Enter the arrival time:");
 scanf("%d",&p.arr_time);
 printf("Enter the burst time:");
 scanf("%d",&p.burst_time);
 p.rem_time=p.burst_time;
 printf("Enter the priority:");
 scanf("%d",&p.priority);
 return p;
}
 
 
 
void swap(struct proc *pi, struct proc *pj)
{
 struct proc *temp;
 temp = pi;
 pi = pj;
 pj = temp;
}
 
 
//FIRST COME FIRST SERVE SCHEDULING ALGO.
 
int main()
{
 int  n;        //To hold the no. of processes.
 struct proc p[10],tmp;     //To hold the details of the processes.
 int i,j;
 printf("Enter the number if processes you want to enter:");
 scanf("%d",&n);       //Get the total no. of processes from tje user
 
 
 for(i=0;i<n;i++)
  p[i]=read(i);      //Get the details of all the processes
 
 
 //Create the ready queue and update every time a new process is scheduled
 for(i=0;i<n-1;i++)
  for(j=0;j<n-1-i;j++)    
  {
   if(p[j].arr_time>p[j+1].arr_time)
     //      swap(&p[j],&p[j+1]);
   {
    tmp=p[j];
    p[j]=p[j+1];
    p[j+1]=tmp;
   }
  }
 for(i=0;i<n;i++)
  printf("%d ",p[i].no); 
    //getc();    // Print the order in which the processes are getting executed.
 return 0;
}
 
