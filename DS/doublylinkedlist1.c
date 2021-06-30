#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void copy();
void search();
struct node *copy1();
void reverse();
void reverse1();
struct node
{
    int data;
    struct node *nextptr;
    struct node* prevptr;
};

struct node *start=NULL,*head,*ptr,*newhead;
int i=0;

int main()
{
    int choice,n;
    while(1)
    {
        
        printf("1.Create\n");
        printf("2.Display\n");
        printf("4.Exit\n");
        printf("5.Insert_end\n");
        printf("6.Delete_end\n");
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
            case 4:
                exit(0);
            case 5:
                copy();
                newhead=copy1(start,NULL);
                break;
            case 6:
                search(start);
                i=0;
                reverse(NULL,start);
                break;
            default:
                printf("Wrong choice\n");
                reverse1();
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
        start -> prevptr=NULL;
        ptr = start;
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
                newnode -> prevptr = ptr;
                ptr -> nextptr = newnode;
                printf("%p\n",ptr);                    
                //ptr = ptr -> nextptr;
                ptr=newnode;
                printf("%p\n",ptr);
            }
            
        }
      head=newnode;
    }
    printf("\n\n");
    
}

void copy()
{
   struct node* temp = start;
   struct node* ptr=NULL,*temp1;
   newhead = (struct node*)malloc(sizeof(struct node));
   newhead->data = temp->data;
   newhead->nextptr = NULL;
   newhead->prevptr = NULL;
   temp = temp->nextptr;
   ptr = newhead;
   while (temp != NULL)
	{ temp1=ptr;	
	  ptr->nextptr = (struct node*)malloc(sizeof(struct node));
	  ptr = ptr->nextptr;
	  ptr->data = temp->data;
	  ptr->nextptr = NULL;
          ptr->prevptr = ptr->prevptr;  
          temp = temp->nextptr;
	}
    
}
struct node *copy1(struct node *start1,struct node *prev)
{
    if(start1==NULL) return NULL ;
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    temp->data=start1->data;
    //prev=temp;
    printf("%d-%p--%p\n",temp -> data,temp,start1);
    temp->nextptr=copy1(start1->nextptr,temp);
    temp->prevptr=prev;
    printf("%d-%p--%p--%p\n",temp -> data,temp,start1,temp->nextptr);
    return temp;
}
void search()
{
    int data,k;
    printf("Input data to be searched\n");
    scanf("%d",&k);
    struct node *temp=start,*temp1;
      while(temp != NULL)
        {
            if(temp->data==k)
              { printf("Found\n");
                return;
              }
            temp = temp -> nextptr;
        }
   printf("Not Found\n");
    temp1=start;
    while(temp1 != NULL)
        {
            printf("%d \n",temp1 -> data);
            temp1 = temp1 -> nextptr;
        }
        
}

void display()
{
    struct node *temp,*temp1=newhead;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements in linked list are:\n");
        temp = head;
        while(temp != NULL)
        {
            printf("%d %d %p\n",temp -> data,temp1->data,temp1->prevptr);
            temp = temp -> prevptr;
            temp1 = temp1 -> nextptr;
        }
      
    }
    printf("\n\n");
}
void reverse(struct node *prev,struct node *temp)
{ 
   if(temp!=NULL)
    {
      reverse(temp,temp->nextptr);
      temp->nextptr = prev;
      if(prev!=NULL)
      prev->prevptr = temp;
      i++;
      printf("%p--%p %d\n",temp,prev,i);
    }
    else
    {
      start = prev;
      return;
    }
  
}
void reverse1()
{
   struct node* temp = start,*ptr=NULL,*next=start;
   while (next != NULL)
	{ 		
	  next=temp->nextptr;
	  temp->nextptr = ptr;
          if(ptr!=NULL)
            ptr->prevptr = temp;
	  ptr= temp;  
          temp =next;
	}
   start=ptr;
}
