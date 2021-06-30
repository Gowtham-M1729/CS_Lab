#include<stdio.h>
#include<stdlib.h>
void create(int n);
struct node{
  int data;
  struct node *nextptr;
};
void display(struct node *temp);
struct node *reverse(struct node *temp);

struct node *start,*k;
int n;
void main()
{
  int i,j;
  printf("Enter the number of nodes you want to create");
  scanf("%d",&n);
  create(n);
  display(start);
  printf("True Head->%p\n",start);
  k=reverse(start);
  k->nextptr=NULL;
  display(start);
  printf("Reversed Head->%p\n",start);
}
void create(int n)
{
 int data,i;
 struct node*temp;
 printf("Enter the data for node->");
 scanf("%d",&data);
 start = (struct node*) malloc(sizeof(struct node));
 start->nextptr=NULL;
 start->data=data;
 temp=start;
  for(i=1;i<n;i++)
  {
  printf("Enter the data for node:-");
  scanf("%d",&data);
  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  newnode->nextptr=NULL;
  newnode->data=data;
  temp->nextptr=newnode;
  temp=newnode;
  }
}
void display(struct node *temp)
{
  if(temp==NULL)
  {
    return;
  }
  else{
    printf("%d--%p\n",temp->data,temp);
    display(temp->nextptr);
}
}
struct node *reverse(struct node *temp)
{
  if(temp->nextptr==NULL)
  {
    start=temp;
    return start;
    //printf("%p########%p\n",temp,k);
  }
  else if(temp==NULL)
  {
    return k;
  }

  {
    reverse(temp->nextptr)->nextptr=temp;
    //printf("%d--%p\n",temp->data,temp);
    return temp;

  }
}
