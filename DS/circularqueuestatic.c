#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int arr[100];
    int front ,rear ,element;
};

struct Queue *queue;

int dequeue(struct Queue*);
void enqueue(struct Queue*,int);
void display(struct Queue*);
struct Queue create();

void main()
{
    int element,choice,x;
    struct Queue queue;
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1.Create\n");
        printf("2.Enqueue\n");
        printf("3.Dequeue\n");
        printf("4.Display\n");
        printf("5.Exit\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            queue = create();
            break;
        case 2:
            printf("Enter element:\n");
            scanf("%d",&element);
            enqueue(&queue,element);
            break;
        case 3:
            x = dequeue(&queue);
            break;
        case 4:
            display(&queue);
            break;
        case 5:
            exit(0);
        default:
            printf("enter valid choice\n");
            break;
        }
    }
}

struct Queue create()
{
    struct Queue queue;
    printf("Enter size:\n");
    scanf("%d",&queue.size);
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

void enqueue(struct Queue* queue,int element)
{
    if((queue->front == 0 && queue->rear == queue->size-1) || (queue->front == queue->rear + 1))
        printf("Queue if full\n");
    else
    {
        if(queue->front == -1)
        {
            queue->front = 0;
            queue->rear = (queue->rear + 1) % queue->size;
        }
        else
        {
            queue->rear = (queue->rear + 1) % queue->size;
            printf("rear %d\n", queue->rear);
        }
        queue->arr[queue->rear] = element;
    }
}

int dequeue(struct Queue* queue)
{
    int x;
    if(queue->front == -1)
        printf("queue is empty\n");
    else
    {
        x = queue->arr[queue->front];
        if(queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1)%queue->size;
        }

    }
    return x;
}

void display(struct Queue* queue)
{
    int i;
    for(i=queue->front;i != queue->rear;i = (i + 1) % queue->size)
    {
        printf("%d ",queue->arr[i]);
    }
    //printf("%d",queue->arr[i]);
    printf("\n");
}
