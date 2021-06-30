#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void copy();
void reverse();
void insert_end();
void insert_begin();
void delete_begin();
void delete_end();
void insert_pos();
void delete_pos();
void search();
void delete_key();
void rearrange();
void sort();
struct node
{
    int data;
    struct node *nextptr;
};

struct node *start=NULL;
struct node* head=NULL;
int n;
int main()
{
    int choice,n,target;
    while(1)
    {
        
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert at the beginning\n");
        printf("4.Reverse\n\n");
        printf("5.Copy\n");
        printf("6.Insert at End\n");
        printf("7.Delet at Begin\n");
        printf("8.Delete at End\n");
        printf("9.Insert at Position\n");
        printf("10.Delete at Position\n");
        printf("11.Search\n");
        printf("12.Delete by key\n");
        printf("13.Sort\n");
        printf("14.Exit\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display(start);
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                reverse();
                break;
            case 5:
                copy();
                break;
            case 6:
                insert_end();
                break;
            case 7:
                delete_begin();
                break;
            case 8:
                delete_end();
                break;
            case 9:
                insert_pos();
                break;
            case 10:
                delete_pos();
                break;
            case 11:
                search();
                rearrange(start);
                break;
            case 12:
                printf("enter the target element to be deleted\n");
                scanf("%d",&target);
                delete_key(start,target);
                break;
            case 13:
                sort();
                break;
            case 14:
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
    int data,i;
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

void display(struct node *temp)
{
    //struct node *temp1=start;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements in linked list are:\n");
        //temp = head;
        while(temp != NULL)
        {
            printf("%d\n",temp -> data);
            temp = temp -> nextptr;
            //temp1 = temp1 -> nextptr;
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
  display(head);
    
}
void reverse()
{
   struct node* temp = start,*ptr=NULL,*next=start;
   while (next != NULL)
	{ 		
	  next=temp->nextptr;
	  temp->nextptr = ptr;
	  ptr= temp;  
          temp =next;
	}
   start=ptr;
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
void delete_begin()
{
    struct node *temp;
    if(start == NULL)
    { printf("List is empty");
        
    }
    else
    {   temp = start;
        start=start -> nextptr;
        free(temp);
    }
    
}
void insert_end()
{   int data;
    struct node *temp,*newnode,*d;
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&data);
    newnode -> data = data;
    newnode -> nextptr = NULL;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = start;
        while(temp ->nextptr!= NULL)
        {
            //printf("%d %p\n",temp -> data,temp);
            temp = temp -> nextptr;
        }
       temp ->nextptr=newnode;
        
    }
}
void delete_end()
{   int data;
    struct node *temp,*newnode;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = start;
        while(temp ->nextptr!= NULL)
        {   newnode=temp;
            temp = temp -> nextptr;
        }
       newnode->nextptr=NULL;
       free(temp);
        
    }
}
void insert_pos()
{
    struct node *temp,*newnode;
    int i,pos;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
      {
         printf("\nOut of Memory Space:\n");
         return;
      }
    printf("\nEnter the position for the new node to be inserted:");
    scanf("%d",&pos);
    printf("\nEnter the data value of the node:");
    scanf("%d",&newnode->data) ;
    newnode->nextptr=NULL;
    if(pos==1)
      {
        newnode->nextptr=start;
        start=newnode;
      }
    else
      { temp=start;
        for(i=1;i<pos-1;i++)
           { temp=temp->nextptr;
             if(temp==NULL)
               {
                 printf("\nPosition not found\n");
                 return;
               }
           }
        newnode->nextptr =temp->nextptr;
        temp->nextptr=newnode;
       }
}
void delete_pos()
{
    struct node *temp,*newnode;
    int i,pos;
    printf("\nEnter the position for the new node to be deleted:");
    scanf("%d",&pos);
    if(pos==1)
      { 
        temp = start;
        start=(start -> nextptr)->nextptr;
        free(temp);
       
      }
    else
      { temp=start;
        for(i=0;i<pos-1;i++)
           { newnode=temp;
             temp=temp->nextptr;
             if(temp==NULL)
               {
                 printf("\nPosition not found\n");
                 return;
               }
           }
        newnode->nextptr=temp->nextptr;
        free(temp);
       }
}
void search()
{   int data,i=0;
    printf("\nEnter the data value to be searched:");
    scanf("%d",&data) ;
    struct node *temp,*newnode;
    if(start ==  NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = start;
        while(temp!= NULL)
        {   i++;
            if(temp -> data==data);
              { printf("Found at %d\n",i);
                return;
              }
        }
        printf("Not Found\n");
        
    }
}
void delete_key(struct node *temp,int target)
{
    struct node *currentnode=start,*prevnode;

    //printf("first %d\n",temp->data);
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
            if(start->data == target)
            {
                temp = start;
                start = start->nextptr;
                free(temp);
                prevnode=start;
                //n--;
            }
            else
            {

                while(temp != NULL && temp -> data != target)
                {
                    prevnode=temp;
                    temp = temp->nextptr;
                    
                }
                if(temp==NULL)
                  { printf("Deleting element is not present\n");
                    return;
                  }
                else
                  {
                    prevnode->nextptr = temp->nextptr;
                    free(temp);
                    //n--;
                  }
            }
            
        
    }
    delete_key(prevnode,target);
}
void sort() 
{ 
    int i,j; 
    struct node *ptr; 
    struct node *temp = NULL; 
    if (start == NULL) 
        return; 
  
    do
    { 
        i= 0; 
        ptr= start; 
  
        while (ptr->nextptr != temp) 
        {   
            if (ptr->data > ptr->nextptr->data) 
            {  
                j=ptr->data;
                ptr->data= ptr->nextptr->data;
                ptr->nextptr->data=j;
                i = 1; 
            } 
            ptr = ptr->nextptr; 
        } 
        temp = ptr; 
    } 
    while (i); 
}
void rearrange(struct node *odd)
{
    struct node* temp=odd,*ppre=NULL,*pre=NULL,*nxt;
    int cnt=1;
    while(temp)
    {
        nxt=temp->nextptr;
        if(cnt%2!=0 && ppre)
            ppre->nextptr=temp;
        else if(cnt%2==0)
            temp->nextptr=ppre;
        ppre=pre;
        pre=temp;
        temp=nxt;
        cnt++;
    }
    if(cnt%2!=0)
    ppre->nextptr=pre;
    else
    pre->nextptr=ppre;
}








