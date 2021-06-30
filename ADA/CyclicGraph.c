#include<stdio.h>
#include<stdlib.h>
int cycle=0;
struct node_info
{
    int no;
}*q = NULL,*r = NULL;
struct node
{
    struct node_info *pt;
    struct node *next;
}*top = NULL,*p = NULL,*np = NULL;
void push(struct node_info *ptr)
{
    np = (struct node*)malloc(sizeof(struct node));
    np->pt = ptr;
    np->next = NULL;
    if (top == NULL)
    {
        top = np;
    }
    else
    {
        np->next = top;
        top = np;
    }
}
struct node_info *pop()
{
    if (top == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        p = top;
        top = top->next;
        return(p->pt);
        //delete(p);
    }
}
void back_edges(int *v,int am[][4],int i,int k)
{
    int c;
     q =( struct node_info*)malloc(sizeof(struct node_info));
     q->no = i;
     push(q);
     v[i] = 1;
     for (int j = 0; j < 3; j++)
     {
         if (am[i][j] == 1 && v[j] == 0)
         {
             c++;
             back_edges(v,am,j,i);
         }
         else if (am[i][j] == 0)
              continue;
         else if ((j == k) && (am[i][k] == 1 && v[j] == 1))
              continue;
         else
         {
             cycle=1;
             am[i][j] = 0;
             am[j][i] = 0;
             continue;
         }
     }
     r = pop();
     return;
}     
int main()
{
    int v[3],am[4][4];
    for (int i = 0; i <3 ; i++)
        v[i] = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("enter the values for adjacency matrix row:");
        for(int j = 0; j < 3; j++)
        {
            scanf("%d",&am[i][j]);
        }
    }
    back_edges(v,am,0,0);
    if(cycle==1){
        printf("Graph is cyclic ");
    }
     else{
        printf("Graph is acyclic ");
    }
}
