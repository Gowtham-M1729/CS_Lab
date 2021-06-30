#include<stdio.h>
#include<stdlib.h>
struct QUEUE
{
   int* items;
   int front;
   int rear;
   int capacity;
};

typedef struct QUEUE* queue;
void insert(queue);
void delete(queue);
void display(queue);


void main()
{

  int choice;
  queue data = (struct QUEUE *)malloc(sizeof(queue));
  data->front= 0; data->rear = -1; data->capacity=4;
  data->items = (int*)malloc(sizeof(int)*data->capacity);



  for(;;)
  {
    printf("\nEnter choice:\n1:Insert\n2:Delete\n3:Display\n4:exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
       case 1: insert(data);display(data); break;
       case 2:  delete(data); display(data); break;
       case 3:   display(data); break;
       case 4: exit(0);
       default:  printf("Invalid input, please try again\n");break;
    }
    }
  }
void insert(queue data)
{
  int item, j;
  if(data->rear == data->capacity-1)
  {
    printf("Queue is Full, reallocating\n");
    data->capacity=data->capacity*2;
    data->items = (int*)realloc(data->items,sizeof(int)*data->capacity);

  }
  printf("enter the item:");
  scanf("%d", &item);


 for(j = data->rear;j>=0 && *(data->items+j)>item;j--)
 {
     *(data->items + (j+1)) = *(data->items+j);
 }

 data->items[++j] = item;
 data->rear++;

 }




 void delete(queue data)
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
 }

 void display(queue data)
 {  int i;
     if(data->front>data->rear)
   {
      printf("---------Empty\n");
      return;
   }
    for(i=data->front; i<=data->rear; i++)

      printf("%d  ", data->items[i]);
 }
