#include<stdio.h>
#include<stdlib.h>
struct QUEUE
{
   int item;
   struct QUEUE *front;
   struct QUEUE *nextptr;
   struct QUEUE *rear;
   int capacity;
};

typedef struct QUEUE* queue;
void insert(queue);
void delete(queue);
void display(queue);
int k=0;
queue temp=NULL;

void main()
{

  int choice;
  struct QUEUE Q;
  queue data = &Q;
  data->capacity=100;
  data->front= (queue)malloc(sizeof(queue)); data->rear = NULL;
  data->front->nextptr=data->rear;



  for(;;)
  {
    printf("\nEnter choice:\n1:Insert\n2:Delete\n3:Display\n4:exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
       case 1: insert(data);display(data); break;
       case 2: // delete(data); display(data); break;
       case 3:   display(data); break;
       case 4: exit(0);
       default:  printf("Invalid input, please try again\n");break;
    }
    }
  }
void insert(queue data)
{
  int item, j;
  if(k == data->capacity-1)
  {
    printf("Queue is Full, reallocating\n");


  }
  printf("enter the item:");
  scanf("%d", &item);
    queue prev=data->front,newnode;
    temp=data->front;
    if(temp->item>item && k!=0)
    {newnode = (queue)malloc(sizeof(queue));
     newnode->item=item;
     newnode->nextptr=prev;
     //printf("Hi---%d\n",data->front->item);
     data->front=newnode;
     //printf("Hi---");
     return;

   }
 while(temp!=NULL && temp->item<item)
    {   prev=temp;
        temp=temp->nextptr;
    }

 newnode = (queue)malloc(sizeof(queue));

 prev->nextptr=newnode;
 newnode->item=item;
 newnode->nextptr=temp;
 if(k==0 || temp==data->front)
   {
     data->front=newnode;
     k++;

   }
   else
   {
      k++;

   }
   if(temp==NULL)
     data->rear=prev;


 }




 /*void delete(queue data)
 {
   if(data->front>data->rear)
   {
      printf("--------Empty\n");
      return;
   }
   printf("deleted: %d\n",*(data->items+(data->front++)));
   if(data->front>data->rear)
   {
     data->front=0; data->rear=-1;
   }
 }      */

 void display(queue data)
 {  int i;
    /* if((data->front)->item>(data->rear)->item)
   {
      printf("---------Empty\n");
      return;
   }*/
    temp=data->front;
    while(temp!=NULL)
    {   printf("%d ",temp->item);
        temp=temp->nextptr;
    }
 }
