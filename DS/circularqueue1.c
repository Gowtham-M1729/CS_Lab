#include<stdio.h>
#include<stdlib.h>
struct node{
  int *a;
  int f;
  int r;
  int k;
};
void insert(struct node*);
void delete(struct node*);
void display(struct node*);
int n,k=0;
void main()
{
  int i,j,choice;
  struct node *queue=(struct node*)malloc(sizeof(struct node));
  printf("Enter the size of queue\n");
  scanf("%d",&n);
  queue->f=0;
  queue->r=-1;
  queue->a=(int *)malloc(sizeof(int)*n);
  while(1)
  {
    printf("\nEnter choice:\n1:Insert\n2:Delete\n3:Display\n4:exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
       case 1: insert(queue);
               display(queue);
                break;
       case 2:  delete(queue);
                display(queue);
                break;
       case 3: display(queue);
               break;
       case 4:
              exit(0);
       default:
              printf("Invalid input, please try again\n");
              break;
    }
  }

 }
 void insert(struct node *queue)
 {
   int item,i;
   printf("Enter the element to be inserted\n");
   scanf("%d",&item);
     queue->r=(queue->r+1)%n;
     if(queue->r!=queue->f || k!=n)
       {
            i=queue->r;
          queue->a[i]=item;
          k++;

       }
       else
       {
         printf("Queue is full\n");
         queue->r=n-1;
       }
  }
 void display(struct node *queue)
 {  int i,j;
   printf("%d %d\n",queue->f,queue->r);
   printf("Elements in Queue are\n");
   for(j=queue->f,i=0;i<k;i++)
 {
   printf("%d\n",queue->a[j]);
   j=(j+1)%n;
 }

}
void delete(struct node *queue)
{
  if(queue->f==queue->r)
  {
    printf("Queue is Empty\n");
    k=0;
    return;
  }
  else
  {
    queue->f=(queue->f+1)%n;
    printf("------%d",queue->f);
    k--;

  }
}
