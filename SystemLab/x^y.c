#include<stdio.h>
int c;
int power(int x, int y)
{
    if(y==0)
        return 1;
     c++;
     if(y%2==0)
    {
       
        return power(x,y/2)*power(x,y/2);
    }
    else
    {
        
        return x*power(x,y/2)*power(x,y/2);
    }
    
}
int main(void)
{
    int x,y;
    FILE *fp1,*fp2;
    remove("count.txt");
    fp2 = fopen("count.txt","a");
    x = 1;
    for(y=1;y<=1000;y=y*2)
    {
        c=0;
        power( x,  y);
        fprintf(fp2,"%d\t%d\n",y,c);
    }
    fclose(fp2);
}
