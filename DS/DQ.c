#include<stdio.h>
#include<stdlib.h>
#define size 6
struct Queue
{
   int items[size];
   int f, r;
};

typedef struct Queue QUE;
void InsertR( QUE *);
void DeleteF(QUE *);
void InsertF( QUE *);
void DeleteR(QUE *);
void Disp(QUE *);

int main()
{
  int ch;
  QUE Q;
  Q.f= 0; Q.r = -1;
  for(;;)
  {
    printf("enter choice:\n1:InsertFront\n2:DeleteRear\n3:Insertfront\n4:DeleteRear\n5:Display\n");
    scanf("%d", &ch);
    switch(ch)
    {
       case 1: InsertR(&Q); Disp(&Q); break;
       case 2:  DeleteF(&Q); Disp(&Q); break;
	     case 3: InsertF(&Q); Disp(&Q); break;
       case 4:  DeleteR(&Q); Disp(&Q); break;
       case 5:   Disp(&Q); break;
       default:  exit(0);
    }
    }
  }
void InsertR(QUE *Q)
{
  int item;
  if(Q->r==size-1)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
 // Q->r++;
  Q->items[++Q->r] = item;
 }
 void DeleteF(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
   printf("deleted:%d\n",Q->items[Q->f++]);
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }                 //       30  40  50   f = 2  r = 4  f = 0

 void Disp(QUE *Q)
 {  int i;
     if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
    for(i=Q->f; i<=Q->r; i++)

      printf("%d  ", Q->items[i]);
 }

void InsertF(QUE *Q)
{
  int item;
  if(Q->f==0 && Q->r!=-1)
  {
    printf("Front Insertion not possible,No rooms at the front\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
  if(Q->f==0 && Q->r==-1)
  {
 // Q->r++;
  Q->items[++Q->r] = item;
  return;
 }
  Q->items[--Q->f] = item;
 }

 void DeleteR(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("Queu Empty\n");
      return;
   }
   printf("deleted:%d\n",Q->items[Q->r--]);
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }
