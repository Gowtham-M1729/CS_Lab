#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void linear(int q,FILE *fp1,FILE *fp2,int count){

	int n,key,flag=0,i;
	int *a;

	for(n=x;n<=y;n+=incre)
	{

		a=(int*)malloc(n*sizeof(int));

		if(q==2){
			for(i=0;i<n;i++)
			{
				a[i]=i+1;
			}
		}

		else{
			for(i=0;i<n;i++)
			{
				a[i]=rand()%100;
			}
		}
		if(q==1)key=a[0]; 					//best case
		if(q==3)key=1000;					 //worst case
		if(q==2)key=a[n/2]; 				//average case

		count=0;
		for(i=0;i<n;i++)
		{
			count++;
			if(a[i]==key)
			{
				flag=1;
				break;
			}
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
	int count=0,run=0;
	system("rm linear_A.txt");
	system("rm linear_B.txt");
	system("rm linear_C.txt");
	system("rm linear_A_count.txt");
	system("rm linear_B_count.txt");
	system("rm linear_C_count.txt");
	srand(time(NULL));
	for(;;){
		if(run==1)break;
		printf("\n1.best case\n2.average case\n3.worst case\n4.exit\nEnter the choice\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: fp1=fopen("linear_B.txt","a");
					fp2=fopen("linear_B_count.txt","a");
					linear(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 2: fp1=fopen("linear_A.txt","a");
					fp2=fopen("linear_A_count.txt","a");
					linear(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 3: fp1=fopen("linear_W.txt","a");
					fp2=fopen("linear_W_count.txt","a");
					linear(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 4: run=1;break;
			
		   default: printf("Invalid input choose again");
					break;
		}
	}
system("gnuplot  -p 'commands.txt'");
}

