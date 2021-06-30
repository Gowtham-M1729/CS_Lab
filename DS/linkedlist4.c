#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void copy();
void reverse();
struct node
{
    int data;
    struct node *nextptr;
};

struct node *start=NULL;
struct node* head=NULL;


int main()
{
    int choice,n;
    create();
    copy();
    display();
    reverse(NULL,start);
    display();
           
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
                printf("%p\n",temp);
            }
            
        }
    }
    printf("\n\n");
    
}

void display()
{
    struct node *temp=head;
    struct node *temp1=start;
    if(head ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements in linked list are:\n");
        temp = head;
        while(temp != NULL)
        {
            printf("%d-%p--%d-%p\n",temp -> data,temp,temp1 -> data,temp1);
            temp = temp -> nextptr;
            temp1 = temp1 -> nextptr;
        }
    }
    printf("\n\n");
}

void copy()
{
   struct node* temp = start;
   struct node* ptr=NULL;
   head = (struct node*)malloc(sizeof(struct node));
   head->data = temp->data;
   head->nextptr = NULL;
   temp = temp->nextptr;
   ptr = head;
   while (temp != NULL)
	{ 		
	  ptr->nextptr = (struct node*)malloc(sizeof(struct node));
	  ptr = ptr->nextptr;
	  ptr->data = temp->data;
	  ptr->nextptr = NULL;  
          temp = temp->nextptr;
	}
    
}
void reverse(struct node *prev,struct node *temp)
{ 
   if(temp!=NULL)
    {
      reverse(temp,temp->nextptr);
      temp->nextptr = prev;
      printf("%d-%p--%p\n",temp -> data,temp,prev);
    }
    else
    {
      start = prev;
      return;
    }
}



