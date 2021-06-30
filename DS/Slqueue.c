#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int capacity;
    int arr[100];
    int front ,rear ,element;
};

int dequeue(struct Queue*);
void enqueue(struct Queue*,int);
void display(struct Queue*);
struct Queue* create();

struct Queue *queue;

void main()
{
    struct Queue *queue;
    int element,choice,x;
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
            enqueue(queue,element);
            break;
        case 3:
            x = dequeue(queue);
            break;
        case 4:
            display(queue);
            break;
        case 5:
            exit(0);
        default:
            printf("enter valid choice\n");
            break;
        }
    }
}

struct Queue* create()
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    printf("Enter size:\n");
    scanf("%d",&queue->size);
    queue->capacity = queue->size;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(struct Queue* queue, int element)
{
    if(queue->rear == queue->capacity - 1)
        printf("queue is Full(OverFlow)\n");
    else
    {
        if(queue->front == -1 && queue->rear == -1)
            queue->front = queue->rear = 0;
        else
            {queue->rear = (queue->rear)+1;}
    queue->arr[queue->rear] = element;
    }
}

int dequeue(struct Queue* queue)
{
    int y;
    if(queue->front == -1 && queue->rear == -1)
        printf("Underflow\n");
    else
    {
        y = queue->arr[queue->front];
        if(queue->front == queue->rear)
            queue->front = queue->rear = -1;
        else
            queue->front += 1;
    }
    queue->size--;
    if(queue->size == 0)
    {
        queue->front == -1;
        queue->rear == -1;
    }
    return y;
}

void display(struct Queue* queue)
{
    if(queue->size == 0)
        printf("queue is empty\n");
    else
    {
        for(int i=queue->front;i<queue->size+queue->front;++i)
        {
            printf("%d ",queue->arr[i]);
        }
        printf("\n\n");
    }

}
