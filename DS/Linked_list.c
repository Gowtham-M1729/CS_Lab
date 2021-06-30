#include<stdio.h>
#include<stdlib.h>

void create(int);
void display(int);
void insert_begin();
void insert_end();
void delete_begin();
void copy();

struct node
{
    int data; //To store data of a node
    struct node *nextptr; //To store address of the next node
};

struct node *start=NULL,*start1=NULL; //Intializing Start with NULL


int main()
{
    int choice,n,m;
    while(1)
    {
        
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert at the beginning\n");
        printf("4.Insert at the end\n");
        printf("5.Delete at the beginning\n");
        printf("6.Copy a list\n");
        printf("7.Exit\n\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the number of nodes:");
                scanf("%d",&n);
                create(n);
                break;
            case 2:
                printf("1.Print Original list\n2.Print Cloned list(if cloned)\n\n");
                scanf("%d",&m);
                display(m);
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                copy();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n\n");
                break;
        }
    }
    return 0;
    
}

void create(int n)
{
    int data,i;
    struct node *temp,*newnode;


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
                                //since we have not created it yet

        //storing the address of the first node in temp
        temp = start;//temp will act as head

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
                //printf("before %p\n",temp);                       //in temp node's newptr
                temp = temp -> nextptr; //this makes temp to point to the current node
                //printf("after %p\n",temp);
                                    //in order to store address of next node when available
            }
            
        }
    }
    printf("\n\n");
    
}
 
void display(int n)
{
    struct node *temp;
    if (n==1)
    {

        printf("Displaying the original linked list:\n\n");
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
    }
    else if(n == 2)
    {
        printf("Displaying the cloned linked list:\n\n");
        if(start1 ==  NULL)
        {
            printf("List is empty");
        }
        else
        {
            printf("Elements in linked list are:\n");
            temp = start1;
            while(temp != NULL)
            {
                printf("%d\n",temp -> data);
                temp = temp -> nextptr;//moves the temp to the next node
            }
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


void insert_end()
{
    int data;
    struct node *temp,*lastnode;
    lastnode = (struct node *)malloc(sizeof(struct node));
    
    if(lastnode == NULL)
    {
        printf("Memory cannot be allocated!!");
    }
    else
    {
        printf("Enter the element you want to insert at the end:");
        scanf("%d",&data);

        lastnode -> data = data;
        lastnode -> nextptr = NULL;
        temp = start;

        while(temp -> nextptr != NULL)//traverses through the enter linked list
            {
                temp = temp -> nextptr;
            }    
            temp -> nextptr = lastnode;    
    }
    
}

void delete_begin()
{
    struct node *DelNode;
    if (start == NULL)
    {
        printf("Linked list is empty!!");
    }
    else
    {
    DelNode = start;//stores the address of first node in Delnode
    start = start -> nextptr;//makes the second node as first node by pointing to the address
    printf("Node at position 1 was successfully deleted %d\n\n",DelNode -> data);
    free(DelNode);
    }
    

}

void copy()
{
    
    struct node *newnode1,*temp1,*temp;
    if(start == NULL)
    {
        printf("Linked list is empty\n\n");
    }
    else
    {
        temp = start;
        start1 = (struct node *)malloc(sizeof(struct node));
        if(start1 == NULL)
        {
            printf("Memory allocation failed");
        }
        else
        {
            start1->data = temp->data;
            start1->nextptr = NULL;
            temp1 = start1; 

            temp = temp->nextptr;
            while(temp != NULL)
            {
                newnode1 = (struct node *)malloc(sizeof(struct node));
                if (newnode1 == NULL)
                {
                    printf("Memory allocation failed for newnode1");
                }
                else
                {
                newnode1->data = temp -> data;
                newnode1->nextptr = NULL;
                temp1->nextptr = newnode1;
                temp1 = temp1->nextptr;

                temp = temp->nextptr;
                }
            }
        }
        
    }
    
}
