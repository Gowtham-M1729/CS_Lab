// Write a program to categorize the data  without  destroying their original sequence.
// Eg:  Consider a group of numbers. Group the numbers maintaining their original order in each group.
//      3   22   12   6   10   34   65   29   9   30   81    4   5  19   20   57   44   99
// categorize these nos in to 4 groups:
// Group 1: < 10
// Group 2:  >10 and  < 19
// Group 3: >19 < 29
// group 4: >29
// Hint: Create multiple queues.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct DATA{

    int array[SIZE];
    int front;
    int rear;
};

typedef struct DATA data;

void insert(data * );
void display(data * );
void categorize(data *,data *,data *,data *,data *);


void main(){
    int choice;
    data mainData,group1,group2,group3,group4;

    mainData.front = 0;mainData.rear = -1;
    group1.front = 0;group1.rear = -1;
    group2.front = 0;group2.rear = -1;
    group3.front = 0;group3.rear = -1;
    group4.front = 0;group4.rear = -1;

    data *M = &mainData;
    data *g1 = &group1; 
    data *g2 = &group2; 
    data *g3 = &group3; 
    data *g4 = &group4; 

    for(;;){
    printf("\nEnter Choice\n1:insert elements to main data\n2:display All\n3:exit\n");
    scanf("%d", &choice);
    switch(choice){
        case 1: insert(M);categorize(M,g1,g2,g3,g4);printf("Entered main sequence: \n");
                display(M);printf("\ngroup1");display(g1);printf("\ngroup2");display(g2);printf("\ngroup3");display(g3);printf("\ngroup4");display(g4);
                break;
        case 2: printf("The display function :\n");
                display(M);printf("\ngroup1");display(g1);printf("\ngroup2");display(g2);printf("\ngroup3");display(g3);printf("\ngroup4");display(g4);
                break;
        case 3: exit(0);

        defalut: printf("Invalid Choice, read again\n");
                break;
    }

    }

}

void insert(data * Q)
{
  int item;

  if(Q->rear==SIZE-1)

  {
    printf("Queue Full\n");
    return;
  }

  printf("enter item:");
  scanf("%d", &item);

  Q->array[++Q->rear] = item;
    
 }

void categorize(data *M, data *q1, data *q2, data *q3, data*q4)
{
   
        if(M->array[M->rear]<= 10)
        {
            q1->array[++q1->rear] = M->array[M->rear];
        } else 
        if(M->array[M->rear]> 10 && M->array[M->rear]<=19 ){
            q2->array[++q2->rear]= M->array[M->rear];
        }   else  
        if(M->array[M->rear]> 19 && M->array[M->rear]<=29){
             q3->array[++q3->rear]= M->array[M->rear];
        }else
        if(M->array[M->rear]> 29 ){
             q4->array[++q4->rear]= M->array[M->rear];
        }
        
    
}

 void display(data *Q)
 {  
     printf(" List is: ");
     int i;
     if(Q->front>Q->rear)
   {
      printf("----------\n");
      return;
   }
    for(i=Q->front; i<=Q->rear; i++)
      printf("%d  ", Q->array[i]);
    printf("\n");
 }


