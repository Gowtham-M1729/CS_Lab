#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 100
#define y 1000
#define incre 100

void swap(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

void bubbleSort(int *a,int n){
	int i,swapped,j;

	for(i=0;i<n-1;i++)
        {
            swapped=0;
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(&a[j],&a[j+1]);
                    swapped=1;
                }
            }
            if(swapped == 0)
            break;
        }
}

void binary(int q,FILE *fp1,FILE *fp2,int count){

	int n,key,i,m;
	int *a;

	for(n=x;n<=y;n+=incre)
	{
        int l=0,r=n;
		a=(int*)malloc(n*sizeof(int));

		
			for(i=0;i<n;i++)
			{
				a[i]=rand()%1000;
			}
		bubbleSort(a,n);
		
		if(q==1)key=a[n/2]; 					    //best case
		if(q==3)key=10000;                          //worst case
		if(q==2)key=a[n/4]; 				    //average case

		count=0;
		while(l<=r)
		{
			count++;
			int m=(l+r)/2;
            if(a[m]==key)
                break;
            if(a[m]<key)
                l=m+1;
            else    
                r=m-1;
		}

		fprintf(fp1,"iteration	");
		for(i=0;i<n;i++)
		{
			fprintf(fp1,"%d ",a[i]);
		}
		fprintf(fp1,"\nkey = %d",key);
		fprintf(fp1,"\n\n");
		
		
		fprintf(fp2,"%d\t",n);
		fprintf(fp2,"%d\t\n",count);
		
	}
}

void main()
{
	int choice;
	FILE *fp1,*fp2;
	int count=0,run=1;
	system("del binary_A.txt");
	system("del binary_B.txt");
	system("del binary_C.txt");
	system("del binary_A_count.txt");
	system("del binary_B_count.txt");
	system("del binary_C_count.txt");
	srand(time(NULL));
	while(run){
		printf("\n1.best case\n2.average case\n3.worst case\n4.exit\nEnter the choice\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: fp1=fopen("binary_B.txt","a");
					fp2=fopen("binary_B_count.txt","a");
					binary(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 2: fp1=fopen("binary_A.txt","a");
					fp2=fopen("binary_A_count.txt","a");
					binary(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 3: fp1=fopen("binary_W.txt","a");
					fp2=fopen("binary_W_count.txt","a");
					binary(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 4: run=0;break;
			
		   default: printf("Invalid input choose again");
					break;
		}
	}
system("gnuplot -p 'commands.txt'");
}


