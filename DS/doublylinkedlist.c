#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_end();
void delete_end();
void insert_begin();
void delete_begin();
void insert_pos();
void delete_pos();
void search();
void delete_key();
void copy();
void sort();
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


int main()
{
    int choice,n,target,i;
        while(1)
    {
        
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert_begin\n");
        printf("4.Insert_end\n");
        printf("5.Delete_end\n");
        printf("6.Delete_begin\n");
        printf("7.Insert_pos\n");
        printf("8.Delete_pos\n");
        printf("9.Copy_rec\n");
        printf("10.Copy\n");
        printf("11.Reverse\n");
        printf("12.Search\n");
        printf("13.Delet by Key\n");
        printf("14.Sort\n");
        printf("15.Exit\n");
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
            case 15:
                exit(0);
            case 4:
                insert_end();
                break;
            case 5:
                delete_end();
                break;
            case 3:
                insert_begin();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                insert_pos();
                break;
            case 8:
                delete_pos();
                break;
            case 12:
                search();
                break;
             case 10:
                copy();
                newhead=copy1(start,NULL);
                break;
            case 11:
                i=0;
                reverse(NULL,start);
                break;
            case 13:
                printf("enter the target element to be deleted\n");
                scanf("%d",&target);
                delete_key(start,target);
                break;
            case 14:
                sort();
                break;
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
                printf("%p\n",temp);                    
                //ptr = ptr -> nextptr;
                ptr=newnode;
                printf("%p\n",temp);
            }
            
        }
      head=newnode;
    }
    printf("\n\n");
    
}
void insert_end()
{
    int data;
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value for the node:");
    scanf("%d",&data);
    temp -> data = data;
    printf("%p\n",temp -> nextptr);
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        head -> nextptr = temp;
        temp->prevptr=head;
        head = temp;
       
    }
    
}
void insert_begin()
{
    int data;
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value for the node:");
    scanf("%d",&data);
    temp -> data = data;
    printf("%p\n",temp -> nextptr);
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp -> nextptr = start;
        start->prevptr=temp;
        start=temp;
       
    }
    
}
void delete_begin()
{
    int data;
    struct node *temp;
    printf("%p\n",temp -> nextptr);
    if(start == NULL)
    {
       printf("Empty List");
    }
    else
    {   temp=start;
        start=start->nextptr;
        free(temp);
       
    }
    
}
void delete_end()
{
    int data;
    struct node *temp;
        temp=head -> prevptr;
        temp->nextptr=NULL;
        free(head);
        head = temp;
        
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
    if(start==NULL)
      {
         start=newnode;
         return;
      }
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
        newnode->prevptr=temp;
        temp->nextptr->prevptr=newnode;
       }
}
void delete_pos()
{
    struct node *temp,*newnode;
    int i,pos;
    printf("\nEnter the position for the new node to be deleted:");
    scanf("%d",&pos);
    if(start==NULL)
      {
         printf("Empty List");
         return;
      }
    if(pos==1)
      { 
        temp = start;
        start=(start -> nextptr);
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
        temp->nextptr->prevptr=newnode;
        free(temp);
       }
}
void search()
{   int data,i=1;
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
        {   
            if(temp->data==data)
              { printf("Found at %d\n",i);
                return;
              }
            temp=temp->nextptr;
            i++;
        }
        printf("Not Found\n");
        
    }
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
                  { printf("%d %d\n",temp->data,prevnode->data);
                    prevnode->nextptr = temp->nextptr;
                    if(temp->nextptr!=NULL)
                    temp->nextptr->prevptr=prevnode;
                    printf("%d---%d\n",temp->data,prevnode->data);
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
    printf("%p is address contained in old head\n",start);;
    printf("%p is address contained in new head\n",newhead);
   temp = newhead;
   while(temp != NULL)
        {
            printf("%d\n",temp -> data);
            temp = temp -> nextptr;
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
void reverse(struct node *prev,struct node *temp)
{ 
   if(temp!=NULL)
    {
      reverse(temp,temp->nextptr);
      temp->nextptr = prev;
      if(prev!=NULL)
      prev->prevptr = temp;
      //i++;
      printf("%p--%p\n",temp,prev);
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

