#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insertion_beginning();
void insertion_end();
void insertion_specified();
void deletion_beginning();
void deletion_end();
void deletion_specified();
struct node
{
struct node *prev;
struct node *next;
int data;
};
struct node *head,*temp,*newnode;
void main ()
{
int choice;
while(1)
{
printf("\n*********Main Menu*********\n");
printf("\nChoose one option from the following list ...\n");
printf("\n===============================================\n");
printf("\n1. Create a node. \n2. Insert at beginning\n3. Insertion at end\n4. Insertion atspecified location\n5. Deletion at beginning\n6. Deletion at end.\n7. Deletion at specified location\n8. Display.\n9. Exit\n");
printf("\nEnter your choice\n");scanf("%d",&choice);
switch(choice)
{
case 1: create();
break;
case 2: insertion_beginning();
break;
case 3: insertion_end();
break;
case 4: insertion_specified();
break;
case 5: deletion_beginning();
break;
case 6: deletion_end();
break;
case 7: deletion_specified();
break;
case 8: display();
break;
case 9: exit(0);
break;
default: printf("Wrong choice\n");
break;
}
}
}
void create()
{
newnode=(struct node*)malloc(sizeof(struct node));printf("Enter the data\n");
scanf("%d",&newnode->data);
newnode->prev=NULL;
newnode->next=NULL;
if(head==NULL || temp==NULL)
{
head=temp=newnode;
}
else
{
temp->next=newnode;
newnode->prev=temp;
temp=newnode;
}
}
void display()
{
temp=head;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
//temp=newnode;
}
void insertion_beginning()
{
newnode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data\n");scanf("%d",&newnode->data);
newnode->prev=newnode->next=NULL;
if(head==NULL)
{
head=newnode;
}
else
{
head->prev=newnode;
newnode->next = head;
head=newnode;
}
printf("\nNode inserted\n");
}
void insertion_end()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data\n");
scanf("%d",&newnode->data);
newnode->prev=NULL;
newnode->next=NULL;
if(head == NULL)
{
head=temp=newnode;
}
else
{
temp = head;
while(temp->next!=NULL){
temp = temp->next;
}
temp->next = newnode;
newnode ->prev=temp;
}
printf("\nnode inserted\n");
}
void insertion_specified()
{
int pos,i;
newnode = (struct node *)malloc(sizeof(struct node));
if(newnode == NULL)
{
printf("\n OVERFLOW");
}
else
{
temp=head;
printf("Enter the location\n");
scanf("%d",&pos);
for(i=0;i<pos-1;i++)
{
temp = temp->next;
if(temp == NULL)
{
printf("\n There are less than %d elements", pos-1);
return;
}}
printf("Enter value\n");
scanf("%d",&newnode->data);
newnode->next = temp->next;
newnode -> prev = temp;
temp->next = newnode;
temp->next->prev=newnode;
printf("\nnode inserted\n");
}
}
void deletion_beginning()
{
if(head == NULL)
{
printf("\n Nothing to delete\n");
}
else
{
temp = head;
head = head -> next;
head -> prev = NULL;
free(temp);
printf("\nnode deleted\n");
}
}
void deletion_end()
{if(head == NULL)
{
printf("\n UNDERFLOW");
}
else
{
temp = head;
if(temp->next != NULL)
{
temp = temp -> next;
}
temp -> prev -> next = NULL;
free(temp);
printf("\nnode deleted\n");
}
}
void deletion_specified()
{
int pos,i=1;
printf("\n Enter the position:\n ");
scanf("%d",&pos);
temp = head;
while(i<pos)
{
temp = temp -> next;
i++;
}
temp->prev->next = temp -> next;temp -> next->prev = temp -> prev;
free(temp);
printf("\nnode deleted\n");
}
