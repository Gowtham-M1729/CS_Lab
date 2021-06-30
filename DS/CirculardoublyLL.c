#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_end();
void delete_end();
void delete_key();
void reverse();
void copy();
void insert_begin();
void delete_begin();
void insert_pos();
void delete_pos();
void delete_end();
void reverse_Dw();
void search();
void sort();
struct node *copy_rec();
struct node
{
    int data;
    struct node *nextptr;
    struct node* prevptr;
};

struct node *start=NULL,*head,*ptr,*newhead;


int main()
{
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
            case 6:
                delete_begin();
                break;
            case 3:
                insert_begin();
                break;
            case 7:
                insert_pos();
                break;
            case 8:
                delete_pos();
                break;
            case 10:
                copy();
                break;
            case 12:
                search();
                break;
            case 11:
                reverse();
                break;
            case 13:
                printf("enter the target element to be deleted\n");
                scanf("%d",&target);
                delete_key(start->nextptr,target);
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
    if (start == NULL)
    {   start = (struct node *)malloc(sizeof(struct node));
        if (start == NULL)
          {
             printf("Memory cannot be allocated.\n");
             return;
          }
        start->data=0;
        start -> nextptr = NULL;
        start -> prevptr=NULL;
    }
    printf("Enter number of nodes you want to create\n");
    scanf("%d",&n);
    {
        ptr = start;
        for(i=1; i<=n; ++i)
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
                start->data +=1;
                printf("%p\n",temp);
            }
            
        }
      head=newnode;
      head->nextptr=start;
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
    if(start == NULL)
    {
        start ->nextptr= temp;
        start->data=1;
    }
    else
    {
        head -> nextptr = temp;
        temp->prevptr=head;
        head = temp;
        head->nextptr=start;
        start->data +=1;
       
    }
    
}
void delete_end()
{
    int data;
    struct node *temp;
        temp=head -> prevptr;
        temp->nextptr=start;
        start->prevptr=temp;
        free(head);
        start->data -=1;
        head = temp;
        
}

void display()
{
    struct node *temp;
    if(start->data==0 || start==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        printf("Toatl %d Elements in linked list are: \n",start->data);
        temp = start->nextptr;
        while(temp->nextptr!= start)
        {
            printf("%d\n",temp -> data);
            temp = temp -> nextptr;
        }
        printf("%d\n",temp -> data);
       // printf("%d\n",temp->nextptr -> data);
    }
    printf("\n\n");
}
void copy()
{
   struct node* temp = start->nextptr;
   struct node* ptr=NULL,*temp1;
   newhead = (struct node*)malloc(sizeof(struct node));
   newhead->data = 0;
   newhead->nextptr = NULL;
   ptr = newhead;
   while (temp ->nextptr!= start)
	{ temp1=ptr;	
	  ptr->nextptr = (struct node*)malloc(sizeof(struct node));
	  ptr = ptr->nextptr;
	  ptr->data = temp->data;
	  ptr->nextptr = NULL;
          ptr->prevptr = ptr->prevptr;  
          temp = temp->nextptr;
	}
  newhead->prevptr = ptr;
  ptr->nextptr=newhead;
  printf("%p is address contained in old head\n",start);;
  printf("%p is address contained in new head\n",newhead);
  temp = start->nextptr;
        while(temp->nextptr!= start)
        {
            printf("%d\n",temp -> data);
            temp = temp -> nextptr;
        }
        printf("%d\n",temp -> data);
    
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
            if(start->nextptr->data == target)
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
                    temp->nextptr->prevptr=prevnode;
                    free(temp);
                    start->data -=1;
                  }
            }
            
        
    }
    delete_key(prevnode,target);
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
        ptr= start->nextptr;
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
void insert_begin()
{
   struct node *temp=start->nextptr,*newnode;
   int data;
   if(start ==  NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Enter the value to be inserted");
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&data);
    newnode -> nextptr=temp;
    temp->prevptr=newnode;
    newnode->prevptr=start;     
    start->nextptr=newnode;
    newnode -> data = data;
    start->data +=1;
    
}
void delete_begin()
{  int b=0;
   struct node *temp=start->nextptr,*ptr;
   if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    start->nextptr=start->nextptr->nextptr;
    temp->nextptr->prevptr=start;
   free(temp);
  // if(b)
   //start=temp -> nextptr;
   //else
    //start=NULL;
   start->data -=1;
}
void reverse()
{
   struct node *firstnode=start->nextptr, *prevnode=start, *nextnode=start->nextptr;
    
    do
    {
        nextnode = firstnode->nextptr;
        firstnode->nextptr = prevnode;

        prevnode = firstnode;
        firstnode = nextnode;
    }while(firstnode != start);
    start->nextptr = prevnode;
    prevnode->prevptr = start;
    start->nextptr = prevnode;
}
void insert_pos()
{
    struct node *temp,*newnode;
    int i,pos,data;
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
        newnode -> nextptr=temp;
        temp->prevptr=newnode;
        newnode->prevptr=start;     
        start->nextptr=newnode;
        newnode -> data = data;
        
      }
    else
      { temp=start->nextptr;
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
        newnode->prevptr=temp;
        newnode->nextptr->prevptr=newnode;
       }
    start->data +=1;
}
void delete_pos()
{
    struct node *temp,*newnode;
    int i,pos;
    printf("\nEnter the position for the new node to be deleted:");
    scanf("%d",&pos);
    if(pos==1)
      {  delete_begin();
      }
    else
      { temp=start->nextptr;
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
        temp->nextptr->prevptr=newnode;
        free(temp);
       }
}
void search()
{
    int data,k,i=0;
    printf("Input data to be searched\n");
    scanf("%d",&k);
    struct node *temp=start->nextptr,*temp1;
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

