#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Time readtime();
void display(struct Time a);
struct Time updatetime(struct Time b);
struct Time addtime(struct Time c);

struct Time
{  
   int hour;
   int minutes;
   int seconds;
    
};
struct Time newTime1;
struct Time newTime2;

void main()
{   struct Time newTime; 
    while(1)
     {
    int choice;
    printf("\n");
    printf("Enter your choice:\n");
    printf("1.Input values\n");
    printf("2.Display\n");
    printf("3.Update time\n");
    printf("4.Addtime\n");
    printf("5.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            newTime1=readtime();
            break;
        case 2:
            display(newTime1);
            break;
        case 3:
            newTime1=updatetime(newTime1);
            break;
        case 4:
            addtime(newTime1);
            break;
        case 5:
            exit(0);
    }
   }
}

struct Time readtime()
{       struct Time newTime; 
        printf("Enter Hour:");
        scanf("%d",&newTime.hour);
        printf("Enter Minutes:");
        scanf("%d",&newTime.minutes);
        printf("Enter Seconds:");
        scanf("%d",&newTime.seconds);
        if(newTime.seconds>59)
          {  newTime.minutes=newTime.minutes+(int)newTime.seconds/60;
             newTime.seconds%=60;
          }
        if(newTime.minutes>59)
          {  newTime.hour=newTime.hour+(int)newTime.minutes/60;
             newTime.minutes%=60;
          }
        if(newTime.hour>=23)
          {  newTime.hour%=24;
          }
        return newTime;   
}

void display(struct Time newTime)
{
    
        printf("%d hour:%d minutes:%d seconds",newTime.hour,newTime.minutes,newTime.seconds);
        
}

struct Time updatetime(struct Time newTime)
{  newTime.seconds=newTime.seconds+1;
   if(newTime.seconds>59)
     {  newTime.minutes=newTime.minutes+(int)newTime.seconds/60;
        newTime.seconds%=60;
     }
   if(newTime.minutes>59)
     { newTime.hour=newTime.hour+(int)newTime.minutes/60;
       newTime.minutes%=60;
        
     }
   if(newTime.hour>=23)
     {  newTime.hour%=24;
     }
  return newTime;

}

struct Time addtime(struct Time newTime)
{  newTime2=readtime();
   printf("%d hour:%d minutes:%d seconds",newTime.hour,newTime.minutes,newTime.seconds);
   newTime2.hour=newTime.hour+newTime2.hour;
   newTime2.minutes=newTime.minutes+newTime2.minutes;
   newTime2.seconds=newTime.seconds+newTime2.seconds;
   if(newTime2.seconds>59)
     {  newTime2.minutes=newTime2.minutes+(int)newTime2.seconds/60;
        newTime2.seconds%=60;
     }
   if(newTime2.minutes>59)
     { newTime2.hour=newTime2.hour+(int)newTime2.minutes/60;
       newTime2.minutes%=60;
        
     }
   if(newTime2.hour>=23)
     {  newTime2.hour%=24;
     }
   printf("%d hour:%d minutes:%d seconds",newTime2.hour,newTime2.minutes,newTime2.seconds);
}
