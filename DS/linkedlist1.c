#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void display1();
void insert_begin();
struct node
{
    int data; //To store data of a node
    struct node *nextptr; //To store address of the next node
};

struct node *start=NULL; //Intializing Start with NULL


int main()
{
    int choice,n;
    while(1)
    {
        
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert at the beginning\n");
        printf("4.Exit\n\n");

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
            case 5:
                display1();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;
    
}

void create()
{
    int data,i,n;
    struct node *temp,*newnode;

    printf("Enter number of nodes you want to create\n");
    scanf("%d",&n);

    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)//if start node is null then no memory is allocated
    {
        printf("Memory cannot be allocated.");
    }
    else
    {
        //reads data for the node through keyboard
        printf("Input data for node 1:");
        scanf("%d",&data);
        
        start -> data = data; //stores data in the given node
        start -> nextptr = NULL; //stores the address of next node as NULL
                                //since we not created it yet

        //storing the address of the first node in temp
        temp = start;

        //Creating n nodes and adding to linked list
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
                newnode -> data = data; //stores the input data in the newnode
                newnode -> nextptr = NULL;//stores the address of next node as NULL
                                        //since we not created it yet
                temp -> nextptr = newnode; //it stores the address of newnode
                printf("%p\n",temp);                        //in temp node's newptr
                temp = temp -> nextptr; //this makes temp to point to the current node
                printf("%p",temp);                        //in order to store address of next node when available
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
            temp = temp -> nextptr;//moves the temp to the next node
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
        temp -> nextptr = start;//stores the address of the previous first node
        start = temp;//start is pointing to the temp i.e, newly inserted node
    }
    
}
void display1()
{   int data;
    struct node *temp,*newnode,*d;
    newnode=(struct node *)malloc(sizeof(struct node));
    d=NULL;
    printf("%p\n",d);
    scanf("%d",&data);
        
        newnode -> data = data; //stores data in the given node
       // newnode -> nextptr = NULL;
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
            temp = temp -> nextptr;//moves the temp to the next node
        }
        //temp = temp -> nextptr;
        free(temp);
       printf("%d %p\n",temp -> data,temp->nextptr);
       temp ->nextptr=newnode;
        
    }
    printf("\n\n");
}
