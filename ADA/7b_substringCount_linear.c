#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define x 10
#define y 100
#define inc 10

int strcount(char str[],int n)
{
    int countA = 0,countB = 0,countSubstr=0,count=0;
    for(int i=0; i<n; ++i)
    {
        count++;
        if(str[i] == 'A')
            countA++;
        else if(str[i] == 'B')
        {
            countB++;
            countSubstr += countA;
        }
    }
    printf("count %d\n\n",countSubstr);
    return count;
}

void main()
{
    char str[110];
    srand(time(NULL));
    FILE *fp1;
    int i;
    system("del strcount_linear.txt");
    fp1 = fopen("strcount_linear.txt","a");
    
    //printf("Enter the string:\n");
    //fgets(str,100,stdin);
    int countSubstr;
for(int n=x; n<=y; n+=inc)
{
    for(i=0; i<n; ++i)
    {
        str[i] = 65 + rand() % 26;
    }
    str[i] = '\0';
    printf("%s\n",str);
    int count = strcount(str,n);

    fprintf(fp1,"%d %d\n",n,count);
}

}