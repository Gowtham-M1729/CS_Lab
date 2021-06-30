#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void display1();
void display2();
void insert_begin();
struct node
{
    int data;
    struct node *nextptr;
};

struct node *start=NULL;


int main()
{
    int choice,n;
    while(1)
    {
        
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert at the beginning\n");
        printf("4.Exit\n");
        printf("5.Insert at end\n\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                exit(0);
            case 6:
                display1();
                break;
            case 5:
                display2();
                break;  
            default:
                printf("Wrong choice\n");
                break;
        }
    }
printf("
    return 0;
    
}

void create()
{
    int data,i,n;
    struct node *temp,*newnode;

    printf("Enter number of nodes you want to create\n");
    scanf("%d",&n);

    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Memory cannot be allocated.");
    }
    else
    {
        //reads data for the node through keyboard
        printf("Input data for node 1:");
        scanf("%d",&data);
        
        start -> data = data;
        start -> nextptr = NULL;
        temp = start;

        for(i=2; i<=n; ++i)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            
            if(newnode == NULL)
            {
                printf("Memory cannot be allocated\n");
                break;
            }
            else
            {
                printf("Input data for node %d:",i);
                scanf("%d",&data);
                newnode -> data = data;
                newnode -> nextptr = NULL;
                temp -> nextptr = newnode;
                printf("%p\n",temp);                    
                temp = temp -> nextptr;
                printf("%p",temp);
            }
            
        }
    }
    printf("\n\n");
    
}

void display()
{
    struct node *temp;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements in linked list are:\n");
        temp = start;
        while(temp != NULL)
        {
            printf("%d\n",temp -> data);
            temp = temp -> nextptr;
        }
    }
    printf("\n\n");
}

void insert_begin()
{
    int data;
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value for the node:");
    scanf("%d",&data);
    temp -> data = data;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp -> nextptr = start;
        start = temp;
    }
    
}
void display1()
{   int data;
    struct node *temp,*newnode,*d;
    newnode=(struct node *)malloc(sizeof(struct node));
    d=NULL;
    printf("%p\n",d);
    scanf("%d",&data);
        
        newnode -> data = data; 
        //newnode -> nextptr = NULL;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements in linked list are:\n");
        temp = start;
        while(temp ->nextptr!= NULL)
        {
            printf("%d %p\n",temp -> data,temp);
            temp = temp -> nextptr;
        }
        temp ->nextptr=newnode;
        //temp = temp -> nextptr;
        //free(temp);
       printf("%d %p %p %p\n",temp -> data,temp->nextptr,temp,newnode -> nextptr);
       
        
    }
    printf("\n\n");
}
void display2()
{   struct node *temp,*newnode,*d;
    if(start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements in linked list are:\n");
        temp = start;
        while(temp ->nextptr!= NULL)
        {
            printf("%d %p\n",temp -> data,temp);
            d=temp;
            temp = temp -> nextptr;
        }
        d ->nextptr=NULL;
        //temp = temp -> nextptr;
        free(temp);
       printf("%d %p %p %p\n",temp -> data,temp->nextptr,temp,newnode -> nextptr);
    }
}


