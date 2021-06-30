#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void reverse();
void copy();
void insert_end();
void delete_end();
void insert_begin();
void delete_begin();
void insert_pos();
void delete_pos();
void delete_end();
void reverse_Dw();
void search();
void sort();
void delete_key();
void sort1();
struct node *copy_rec();
struct node
{
    int data;
    struct node *nextptr;
};

struct node *start=NULL,*start1,*newnode,*ptr,*newhead;
struct node* head=NULL;
int data,i;
int main()
{   struct node* temp=NULL;
    int choice,n,target;
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
                display(start);
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                delete_end();
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
            case 9:
                ptr=NULL;
                newhead=copy_rec(start,NULL);
                printf("Elements in copied linked list are:\n");
                temp=newhead;
                while(temp->nextptr!= newhead)
                   {
                       printf("%d-%p\n",temp -> data,temp);
                       temp = temp -> nextptr;
                   }
                printf("%d-%p\n",temp -> data,temp);
                break;
            case 10:
                copy();
                break;
            case 11:
                reverse();
                break;
            case 12:
                i=0;
                search(start);
                break;
            case 13:
                printf("enter the target element to be deleted\n");
                scanf("%d",&target);
                delete_key(start,target);
                break;
            case 14:
                i=0;
                sort();
                break;
            case 15:
                exit(0);
            default:
                sort1();
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
        printf("Memory cannot be allocated.\n");
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
                temp -> nextptr = newnode;          
                temp = temp -> nextptr;
            }
            
        }
       temp -> nextptr=start;
    }
    
}
void display(struct node *temp)
{  struct node *ptr=temp;
   if(start ==  NULL)
    {
        printf("List is empty");
        return;
    }
   
    {
        printf("Elements in linked list are:\n");
        while(temp->nextptr!= ptr)
        {
            printf("%d\n",temp -> data);
            temp = temp -> nextptr;
        }
        printf("%d\n",temp -> data);
    }
    printf("\n\n");
}
void insert_end()
{
   struct node *temp=start;
   if(start ==  NULL)
    {
        printf("List is empty");
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&data);
    newnode -> data = data;
        while(temp->nextptr!= start)
        {
            temp = temp -> nextptr;
        }
   temp -> nextptr=newnode;
   newnode -> nextptr=start;
}
void reverse()
{
   struct node* temp = start,*ptr=start,*next=start;
   while (next->nextptr!= start)
	{ 		
	  next=temp->nextptr;
	  temp->nextptr = ptr;
	  ptr= temp;  
          temp =next;
	}
   start->nextptr=next;
   start=next;
   temp->nextptr = ptr;
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
   while (temp->nextptr!= start)
	{ 		
	  ptr->nextptr = (struct node*)malloc(sizeof(struct node));
	  ptr = ptr->nextptr;
	  ptr->data = temp->data;
	  ptr->nextptr = NULL;  
          temp = temp->nextptr;
	}
  ptr->nextptr = (struct node*)malloc(sizeof(struct node));    
  ptr = ptr->nextptr;
  ptr->data = temp->data;
  ptr->nextptr=head;
  printf("Elements in copied linked list are:\n");
  temp=head;
        while(temp->nextptr!= head)
        {
            printf("%d-%p\n",temp -> data,temp);
            temp = temp -> nextptr;
        }
        printf("%d-%p\n",temp -> data,temp);
}
struct node *copy_rec(struct node *start1)
{   
    if(start1==start && ptr!=NULL) return ptr;
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    if(start1==start)
      ptr=temp;
    temp->data=start1->data;
    printf("%d-%p--%p\n",temp -> data,temp,start1);
    temp->nextptr=copy_rec(start1->nextptr);
    printf("%d-%p--%p--%p\n",temp -> data,temp,start1,temp->nextptr);
    return temp;
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
      { temp=start;
        while(temp->nextptr!= start)
        {
            temp = temp -> nextptr;
        }
       temp -> nextptr=newnode;
       newnode -> nextptr=start;
       start=newnode;
      }
    else
      { temp=start;
        for(i=1;i<pos-1;i++)
           { temp=temp->nextptr;
             if(temp==start)
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
      {  temp=start;
         while(temp->nextptr!= start)
        { 
            temp = temp -> nextptr;
        }
   temp -> nextptr=start->nextptr;
   free(start);
   start=temp -> nextptr;
       
      }
    else
      { temp=start;
        for(i=0;i<pos-1;i++)
           { newnode=temp;
             temp=temp->nextptr;
             if(temp==start)
               {
                 printf("\nPosition not found\n");
                 return;
               }
           }
        newnode->nextptr=temp->nextptr;
        free(temp);
       }
}
void reverse_1()
{
    struct node *currentnode, *prevnode=start, *nextnode;
    currentnode =  nextnode = start;
    
    do
    {
        nextnode = currentnode->nextptr;
        currentnode->nextptr = prevnode;

        prevnode = currentnode;
        currentnode = nextnode;
    }while(currentnode != start);
    start->nextptr = prevnode;
    start = prevnode;
}
void delete_end()
{
   struct node *temp=start,*ptr;
   if(start->nextptr== start)
    {
        printf("List is empty\n");
        return;
    }
        while(temp->nextptr!= start)
        {   ptr=temp;
            temp = temp -> nextptr;
        }
   ptr -> nextptr=start;
   free(temp);
}
void insert_begin()
{
   struct node *temp=start;
   if(start ==  NULL)
    {
        printf("List is empty");
    }
    printf("Enter the value to be inserted");
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&data);
    newnode -> nextptr=start;
    newnode -> data = data;
        while(temp->nextptr!= start)
        {
            temp = temp -> nextptr;
        }
   start=newnode;
   temp -> nextptr=start;
}
void delete_begin()
{  int b=0;
   struct node *temp=start,*ptr;
   if(start==NULL)
    {
        printf("List is empty");
    }
        while(temp->nextptr!= start)
        {   b=1;
            temp = temp -> nextptr;
        }
   temp -> nextptr=start->nextptr;
   free(start);
   if(b)
   start=temp -> nextptr;
   else
    start=NULL;
}
void search()
{
    int data,k,i=0;
    printf("Input data to be searched\n");
    scanf("%d",&k);
    struct node *temp=start,*temp1;
      while(temp->nextptr != start)
        {  i++;
            if(temp->data==k)
              { printf("Found:Position=%d\n",i);
                return;
              }
            temp = temp -> nextptr;
        }
   if(temp->data==k)
        { printf("Found:Position=%d\n",i);
          return;
        }
   printf("Not Found\n");
}
void sort() 
{ 
    int i,j; 
    struct node *ptr,*ptr1; 
    struct node *temp = start; 
    if (start == NULL) 
        return; 
  
    do
    { 
        i= 0; 
        ptr= start;
        do
        {   
            if (ptr->data > ptr->nextptr->data) 
            {  
                j=ptr->data;
                ptr->data= ptr->nextptr->data;
                ptr->nextptr->data=j;
                i = 1; 
            }
            if(ptr->nextptr==temp)
              break;
            ptr = ptr->nextptr;
        } 
        while (ptr->nextptr!=temp); 
        temp = ptr;
         
    } 
    while (i); 
}
void sort1()
{
    int swapped = 0;
    head=start;
    struct node *currentnode = head,*prevnode = NULL;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    do
    {
        currentnode = head;
        swapped = 0;
        while(currentnode->nextptr != head)
        {   
            if(currentnode->data > currentnode->nextptr->data)
            {
                int temp = currentnode->data;
                currentnode->data = currentnode->nextptr->data;
                currentnode->nextptr->data = temp;
                swapped = 1;
            }
            currentnode = currentnode->nextptr;
        }

    } while (swapped);
    
}
void delete_key(struct node *temp,int target)
{
    struct node *currentnode=start,*prevnode;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {      
            if(start->data == target)
            {
                delete_begin();
                prevnode=start;
                
            }
            else
            {   prevnode=temp;
                temp=temp->nextptr;
               
                while(temp != start && temp -> data != target)
                {
                    prevnode=temp;
                    temp = temp->nextptr;
                    
                }
                if(temp==start)
                  { printf("Deleting element is not present\n");
                    return;
                  }
                else
                  {
                    prevnode->nextptr = temp->nextptr;
                    free(temp);
                  }
            }
            
        
    }
    delete_key(prevnode,target);
}


