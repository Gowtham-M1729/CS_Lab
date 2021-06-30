 #include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
 void generate(int arr[], int l, int r) {
	if (l > r) return;
	int mid = l + (r - l)/2, i;
	int tmp = arr[mid];
	for (i = mid - 1; i >= l; i--)
		arr[i+1] = arr[i];
	arr[l] = tmp;
	generate(arr, l + 1, mid);
	generate(arr, mid+1, r);
}


void quicksort(int *A,int l,int r){
   int i, j, P, temp;
   if(l<r){
      P=l;
      i=l;
      j=r;
      while(i<j){
         
         while(A[i]<=A[P]&&i<r){
            count++;
            i++;
         }
         while(A[j]>A[P]){
             count++;
            j--;
         }
         if(i<j){
             count++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
         }
      }
      temp=A[P];
      A[P]=A[j];
      A[j]=temp;
      quicksort(A,l,j-1);
      quicksort(A,j+1,r);
   }
}

int main(){
    srand(time(0));
   system("rm quick_count.txt");
   int i, count1,count2,count3,*A,n,*B,*C;
   FILE *fp;
   fp=fopen("quick_count.txt","a");
   for(n=1;n<=128;n*=2){
       A=(int*)malloc(n*sizeof(int));
      for(i=0;i<n;i++){
          A[i]=rand()%100;
      }
   quicksort(A,0,n-1);
      for(i=0;i<n;i++){
          printf("%d ",A[i]);
      }
      printf("\n");
   count1=count;
   B=(int*)malloc(n*sizeof(int));
   count=0;
      for(i=0;i<n;i++){
          B[i]=i+1;
      }
   quicksort(B,0,n-1);
   for(i=0;i<n;i++){
          printf("%d ",B[i]);
      }
      printf("\n");
   count2=count;
   C=(int*)malloc(n*sizeof(int));
   count=0;
      for(i=0;i<n;i++){
          C[i]=i+1;
      }
      generate(C,0,n-1);
   quicksort(C,0,n-1);
   for(i=0;i<n;i++){
          printf("%d ",C[i]);
   }
   printf("\n");
   count3=count;
   fprintf(fp,"%d %d %d %d\n",n,count1,count2,count3);
   }
   fclose(fp);
   return 0;
}
