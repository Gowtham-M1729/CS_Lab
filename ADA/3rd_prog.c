#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void swap(int *a, int *b) {

int temp = *a;
*a=*b;
*b=temp;

}
void println(int a[],int n,int count )
  {  for(int i=0;i<n;i++)
       printf("%d ",a[i]);
     printf("\ncount:%d\n",count);
   } 

void bubbleSort(int q,FILE *fp1, FILE *fp2, int count){
    
    
	int *a;
    int n,i,j,swapped;
    for(n=x;n<=40;n+=incre)
	{

		a=(int*)malloc(n*sizeof(int));

		if(q==1){
			for(i=0;i<n;i++)
			{
				a[i]=i+1;
			}
		}

		if(q==2)
        {
			for(i=0;i<n;i++)
			{
				a[i]=rand()%100;
			}
		}
        if(q==3)
        {
            for(i=0;i<n;i++)
			{
				a[i]=n-i;
			}
        }
        count=0;

        for(i=0;i<n-1;i++)
        {
            swapped=0;
            for(j=0;j<n-i-1;j++)
            {
                count++;
                if(a[j]>a[j+1])
                {
                    swap(&a[j],&a[j+1]);
                    swapped=1;
                }
            }
            if(swapped == 0)
              break;
        }
        println(a,n,count);
       fprintf(fp1,"iteration	");
		for(i=0;i<n;i++)
		{
			fprintf(fp1,"%d ",a[i]);
		}
		// fprintf(fp1,"\nkey = %d",key);
		 fprintf(fp1,"\n\n");
		
		
		fprintf(fp2,"%d\t",n);
		fprintf(fp2,"%d\t\n",count);
    }
}
void main(){
	int choice;
	FILE *fp1,*fp2;
	int count=0,run=1;
	/*system("rm bubble_A.txt");
	system("rm bubble_B.txt");
	system("rm bubble_C.txt");
	system("rm bubble_A_count.txt");
	system("rm bubble_B_count.txt");
	system("rm bubble_C_count.txt");*/
	srand(time(NULL));
    while(run){
		printf("\n1.best case\n2.average case\n3.worst case\n4.exit\nEnter the choice\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: //fp1=fopen("bubble_B.txt","a");
					//fp2=fopen("bubble_B_count.txt","a");
					bubbleSort(choice,fp1,fp2,count);
					//fclose(fp1);
					//fclose(fp2);
					break;
			case 2: //fp1=fopen("bubble_A.txt","a");
					//fp2=fopen("bubble_A_count.txt","a");
					bubbleSort(choice,fp1,fp2,count);
					//fclose(fp1);
					//fclose(fp2);
					break;
			case 3: //fp1=fopen("bubble_W.txt","a");
					//fp2=fopen("bubble_W_count.txt","a");
					bubbleSort(choice,fp1,fp2,count);
					//fclose(fp1);
					//fclose(fp2);
					break;
			case 4: run=0;break;
			
		   default: printf("Invalid input choose again");
					break;
		}
	}
//system("gnuplot -p 'commands.txt'");
}
