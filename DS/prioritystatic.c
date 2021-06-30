#include<stdio.h>
#include<stdlib.h>
struct QUEUE
{
   int a[100];
   int front;
   int rear;
   int capacity;
};

//typedef struct QUEUE* queue;
void insert(struct QUEUE *queue);
void delete(struct QUEUE *queue);
void display(struct QUEUE *queue);


void main()
{

  int choice;
  struct QUEUE queue;
  //queue data = (struct QUEUE *)malloc(sizeof(queue));
  queue.front= 0; queue.rear = -1; queue.capacity=4;
  //data->items = (int*)malloc(sizeof(int)*data->capacity);



  for(;;)
  {
    printf("\nEnter choice:\n1:Insert\n2:Delete\n3:Display\n4:exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
       case 1: insert(&queue);display(&queue); break;
       case 2:  delete(&queue); display(&queue); break;
       case 3:   display(&queue); break;
       case 4: exit(0);
       default:  printf("Invalid input, please try again\n");break;
    }
    }
  }
void insert(struct QUEUE *queue)
{
  int item, j;
  if(queue->rear == queue->capacity-1)
  {
    printf("Queue is Full, reallocating\n");
    queue->capacity=queue->capacity*2;
    //queue->items = (int*)realloc(queue->items,sizeof(int)*data->capacity);

  }
  printf("enter the item:");
  scanf("%d", &item);


 for(j = queue->rear;j>=0 && queue->a[j]>item;j--)
 {
     queue->a[(j+1)] = queue->a[j];
 }

 queue->a[++j] = item;
 queue->rear++;
 }




 void delete(struct QUEUE *queue)
 {
   if(queue->front>queue->rear)
   {
      printf("--------Empty\n");
      return;
   }
   printf("deleted: %d\n",queue->a[(queue->front++)]);
   if(queue->front>queue->rear)
   {
     queue->front=0; queue->rear=-1;
   }
 }

 void display(struct QUEUE *queue)
 {  int i;
     if(queue->front>queue->rear)
   {
      printf("---------Empty\n");
      return;
   }
    for(i=queue->front; i<=queue->rear; i++)

      printf("%d  ", queue->a[i]);
 }
