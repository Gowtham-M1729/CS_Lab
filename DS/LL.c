#include<stdlib.h>
#include <stdio.h>
     
void create();
void clone();
void display_clone();
void display();

struct node
{
        int data;
        struct node *next;
};
struct node* head=NULL;
struct node* head1=NULL;
struct node* start=NULL;


int main()     
{
        int choice;
        while(1)
        {
                printf("                MENU                             \n");
                printf("1.Create     \n");
                printf("2.Display    \n");
                printf("3. Exit\n");
                printf("Enter your choice:\n");
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
                                        exit(0);
                                        break;
                        case 4:
                                        clone();
                                        printf("%p\n",start);
                                        break;
                        case 5:
                                        display_clone();
                                        break;
                                        
                        default:
                                        printf("Wrong Choice:n");
                                        break;
                }
        }
        return 0;
}
        

void create()
{
        struct node *newnode,*temp;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("Out of Memory Space:\n");
                exit(0);
        }
        printf("Enter the data value for the node:\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
                head=newnode;
        }
        else
        {
                temp=head;
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=newnode;
        }
}

void display()
{
        struct node *temp;
        if(head==NULL)
        {
                printf("List is empty:\n");
                return;
        }
        else
        {
                temp=head;
                printf("The List elements are:\n");
                while(temp!=NULL)
                {
                        printf("%dt",temp->data );
                        temp=temp->next;
                }
        }
}
void clone()
{
    
    struct node* temp=head;
    struct node* ptr=NULL;
    struct node* start=(struct node*)malloc(sizeof(struct node));
    struct node  *head1=start;
     if(start==NULL)
        {
                printf("Out of Memory Space:\n");
                exit(0);
        }
    printf("hi-------------");
    start->data=temp->data;
    start->next=NULL;
    temp=temp->next;
    ptr=start;
    while(temp!=NULL)
    {   printf("%p %p %p\n",temp,ptr,start);
        ptr->next=(struct node*)malloc(sizeof(struct node));
        ptr=ptr->next;
        ptr->data=temp->data;
        ptr->next=NULL;
        temp=temp->next;
        
    }
}

void display_clone()
{  
        struct node *temp=NULL;
        printf("%p %p %p\n",temp,start,head1);
        {
                temp=head;
                printf("The List elements are:\n");
                while(temp!=NULL)
                {       printf("%p %p\n",temp,start);
                        printf("%dt",temp->data );
                        temp=temp->next;
                }
        }
}
