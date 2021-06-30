#include <stdio.h>
#include <stdlib.h>
void read();
void display();
void average();
struct Student {
    char name[100];
    char reg[30];
    int m[3];
};
struct Student *ptr;
int n;
int main() 
{   while(1)
    {
    int choice;
    printf("\n");
    printf("Enter your choice:\n");
    printf("1.Input values\n");
    printf("2.Display\n");
    printf("3.Average\n");
    printf("4.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            read();
            break;
        case 2:
            display();
            break;
        case 3:
            average();
            break;
        case 4:
            exit(0);
    }
    }
}
void read()
{
    int i,j;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    ptr = (struct Student *)malloc(n* sizeof(struct Student));
    for (i = 0; i < n; i++) 
      {
        printf("Enter Name:");
        scanf("%s",(ptr + i)->name);
        printf("Enter Register Number:");
        scanf("%s",(ptr + i)->reg);
        printf("Enter Marks:");
        for(int j=0; j<3; ++j)
            scanf("%d",&(ptr + i)->m[j]);
        
      }
}
void display()
{   int i,j;
    printf("Displaying Information:\n");
    for (i = 0; i < n; ++i)
       {
        printf("%s\t%s:\n", (ptr + i)->name, (ptr + i)->reg);
         for (j = 0; j < 3; j++)
             printf("%d\n",(ptr + i)->m[j]);
       }
}
void average()
{   int t,m1,m2,m3,k;
    printf("Enter the number:\n");
    scanf("%d", &k);
    k=k-1;
    float sum=0;
    m1 = (ptr+k)->m[0];
    m2 = (ptr+k)->m[1];
    m3 = (ptr+k)->m[2];

    if(m1 < m2)
    {
        t = m1;
        m1 = m2;
        m2 = t;
        sum += m1;
    }
    if(m2 < m3)
    {
        sum += m3;
        printf("Average:%f\n",sum/2);
        return;
    }

    sum += m2;
    printf("Average:%f\n",sum/2);
    return;
}
