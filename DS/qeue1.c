#include <stdio.h> 
#include <stdlib.h>  
struct Node { 
    int key; 
    struct Node* next;
     
}; 
 struct Node *front, *rear; 
struct Node* newNode(int k) 
{ 
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 
void enqueue(int k) 
{ 
	
	struct Node* temp = newNode(k);
	if (rear == NULL) { 
		front = rear = temp; 
		return; 
	} 
	rear->next = temp; 
	rear = temp;
        rear->next=front; 
} 

void dequeue() 
{ 
	 
	if (front == NULL)
          { printf("Queue Undeflow");
            return;
          } 

	
	struct Node* temp = front; 

	front = front->next; 

	
	if (front == NULL) 
		rear = NULL; 

	free(temp); 
} 
void display(struct Node* temp)
{  while(temp!=NULL)
            { printf(" %d\t", temp->key);
              temp=temp->next;
            }
}
void peek()
 { if(front==NULL)
      { printf("Empty Queue\n");
        return;
      }
   printf("Queue Front : %d \n", front->key); 
	printf("Queue Rear : %d", rear->key);
}

int main() 
{    struct Node* temp;
     int choice,item;
        while(1)
    {
        printf("\n---------------------\n");
        printf("Enter your choice:\n");
        printf("1.CREATE\n");
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
                enqueue(item);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                peek();
                break;
            case 5:
                temp=front;
                display(temp);
                break;
            case 0:
                exit(0);
        }
    } 
	
	return 0; 
} 

