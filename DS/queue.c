#include <stdio.h> 
#include <stdlib.h>  
struct QNode { 
    int key; 
    struct QNode* next; 
}; 

struct Queue { 
    struct QNode *front, *rear; 
}; 
struct QNode* newNode(int k) 
{ 
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 
struct Queue* createQueue() 
{ 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 
void enqueue(struct Queue* q, int k) 
{ 
	
	struct QNode* temp = newNode(k);
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 
	q->rear->next = temp; 
	q->rear = temp; 
} 

void dequeue(struct Queue* q) 
{ 
	 
	if (q->front == NULL) 
          { printf("Underflow\n");
		return;
          }

	struct QNode* temp = q->front; 

	q->front = q->front->next; 

	
	if (q->front == NULL) 
		q->rear = NULL; 

	free(temp); 
}
void display(struct Queue* q)
{  struct QNode* temp=q->front;
    while(temp!=NULL)
            { printf(" %d\t", temp->key);
              temp=temp->next;
            }
}
void peek(struct Queue* q)
 { if(q->front==NULL)
      { printf("Empty Queue\n");
        return;
      }
   printf("Queue Front : %d \n", q->front->key);
   printf("Queue Rear : %d", q->rear->key);
}
int main() 
{    struct Node* temp;
     int choice,item;
     struct Queue* q = createQueue();
        while(1)
    {
        printf("\n---------------------\n");
        printf("Enter your choice:\n");
        printf("2.Enqueue\n");
        printf("3.Dequeue\n");
        printf("4.Peek\n");
        printf("5.DISPLAY\n");
        printf("0.EXIT\n");
        printf("---------------------\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 2:
                printf("Enter the element:\n");
                scanf("%d",&item);
                enqueue(q,item);
                break;
            case 3:
                dequeue(q);
                break;
            case 4:
                peek(q);
                break;
            case 5:
                display(q);
                break;
            case 0:
                exit(0);
        }
    } 
	
	return 0; 
} 

