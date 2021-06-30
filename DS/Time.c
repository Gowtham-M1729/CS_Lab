#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readtime();
void display();
void updatetime();
void addtime();

struct Time
{  
   int hour;
   int minutes;
   int seconds;
    
};

int num;
struct Time *newTime1;
struct Time *newTime2;

void main()
{  struct Time *newTime; 
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
            newTime1=(struct Time *)malloc(sizeof(struct Time));
            readtime(newTime1);
            break;
        case 2:
            display();
            break;
        case 3:
            updatetime(newTime1);
            break;
        case 4:
            addtime(newTime1);
            break;
        case 5:
            exit(0);
    }
   }
}

void readtime(struct Time *newTime)
{       
        printf("Enter Hour:");
        scanf("%d",&newTime->hour);
        printf("Enter Minutes:");
        scanf("%d",&newTime->minutes);
        printf("Enter Seconds:");
        scanf("%d",&newTime->seconds);
  
    
}

void display()
{
    
        printf("%d hour:%d minutes:%d seconds",newTime1->hour,newTime1->minutes,newTime1->seconds);
        
}

void updatetime(struct Time *newTime)
{  newTime->seconds=newTime->seconds+1;
   if(newTime->seconds>59)
     {  newTime->minutes=newTime1->minutes+(int)newTime1->seconds/60;
        newTime->seconds%=60;
     }
   if(newTime->minutes>59)
     { newTime->hour=newTime->hour+(int)newTime->minutes/60;
       newTime->minutes%=60;
        
     }
   if(newTime->hour>=23)
     {  newTime->hour%=24;
     }

}
void addtime(struct Time *newTime3)
{  newTime2=(struct Time *)malloc(sizeof(struct Time));
   readtime(newTime2);
   printf("%d hour:%d minutes:%d seconds",newTime3->hour,newTime3->minutes,newTime3->seconds);
   newTime2->hour=newTime3->hour+newTime2->hour;
   newTime2->minutes=newTime3->minutes+newTime2->minutes;
   newTime2->seconds=newTime3->seconds+newTime2->seconds;
   if(newTime2->seconds>59)
     {  newTime2->minutes=newTime2->minutes+(int)newTime2->seconds/60;
        newTime2->seconds%=60;
     }
   if(newTime2->minutes>59)
     { newTime2->hour=newTime2->hour+(int)newTime2->minutes/60;
       newTime2->minutes%=60;
        
     }
   if(newTime2->hour>=23)
     {  newTime2->hour%=24;
     }
   printf("%d hour:%d minutes:%d seconds",newTime2->hour,newTime2->minutes,newTime2->seconds);
}
