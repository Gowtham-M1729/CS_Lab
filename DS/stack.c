#include<stdio.h>
#include<stdlib.h>

struct Stack* create();
void push(struct Stack*, int);
int pop(struct Stack*);
int peek(struct Stack*);
void display(struct Stack*);

struct Stack
{
    int t;
    int *a;
};

int size;
void main()
{   struct Stack* stack;
    printf("Enter the size:\n");
    scanf("%d",&size);
    int choice,item,element;

    while(1)
    {
        printf("\n---------------------\n");
        printf("Enter your choice:\n");
        printf("6.CREATE\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        printf("---------------------\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 6:
                stack = create(size);
                break;
            case 1:
                printf("Enter the element:\n");
                scanf("%d",&item);
                push(stack,item);
                break;
            case 2:
                element = pop(stack);
                break;
            case 3:
                element = peek(stack);
                printf("%d is in the TOS",element);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                exit(0);
        }
    }
}

struct Stack* create(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->t = -1;
    stack->a = (int*)malloc(size * sizeof(int));
    return stack;
}

void push(struct Stack* stack,int item)
{
    if(stack->t == size-1)
        printf("Stack Overflow!!\n");
    else
    {
        stack->a[++stack->t] = item;
        printf("%d--%d pushed to stack\n", item,stack->t);
    }
}

int pop(struct Stack* stack)
{   //printf("%d pushed to stack\n",stack->t);
    if(stack->t == -1)
        printf("Stack Underflow!!\n");
    else
    {
        printf("Popped %d\n",stack->a[stack->t]);
        stack->a[stack->t--];
    }
    
}

int peek(struct Stack* stack)
{
    if(stack->t == -1)
        printf("Stack is empty\n\n");
    else
    {
        int x = stack->a[stack->t];
        
        return x;
    }
    
}

void display(struct Stack* stack)
{   if(stack->t == -1)
      {
        printf("Stack is empty\n\n");
        return;
      }
    printf("Displaying stack elements\n");
    int k=stack->t;
    while(k!= -1)
         {
          printf("%d\n",stack->a[k]);
          k--;
         }
}
