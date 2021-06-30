#include<stdio.h>
#include<stdlib.h>
void enQ(int );
void deQ(int );
void display(int );

struct Queue
{
    int a[100];
}*Q;

int front=0,rear=-1,n;

int main(void)
{
    int choice;
    printf("Enter n : ");
    scanf("%d",&n);
    Q = (struct Queue *)malloc(sizeof(struct Queue));
    for(;;)
    {
        printf("\n======MENU======\n");
        printf("1.  Enqueue\n");
        printf("2.  Dequeue\n");
        printf("3.  Peek\n");
        printf("4.  Display\n");
        printf("5.  Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                enQ(n);
                break;
            case 2:
                deQ(n);
                break;
            case 3:
                if(front==-1||rear==-1)
                {
                    printf("\nNo peek...\n");
                }
                else
                {
                    printf("\nPeek : %d\n",Q->a[front]);
                }
                break;
            case 4:
                display(n);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid...\n");
                break;
        }
    }
}

void enQ(int n)
{
    if(rear==(n-1))
        printf("\nOVERFLOW\n");
    else
    {
        rear+=1;
        printf("Enter data : ");
        scanf("%d",&Q->a[rear]);
        printf("\nInserted...\n");
    }
}

void deQ(int n)
{
    if(front==-1||front>rear)
    {
        printf("\nUNDERFLOW...\n");
        return;
    }
    else
    {
        if(front==rear)
        {
            front=rear=-1;
        }
        front+=1;
        printf("\nDeleted...\n");
    }
}

void display(int n)
{
    int i;
    if(rear==-1)
    {
        printf("\nQueue is empty...\n");
        return;
    }
    else
    {
        printf("\nQueue : ");
        for(i=front;i<=rear;i++)
        {
            printf(" %d ",Q->a[i]);
        }
        printf("\n");
    }
}
