
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int A,int B,int C,int *count)
{ 
	if (n >0) 
	{ 
		
	*count+=1;
	towerOfHanoi(n - 1, A,C,B,count); 
	//cout << "Move disk " << n << " from rod " << A <<
	//							" ------> " << C << endl; 
	//*count+=1;
	towerOfHanoi(n - 1, B,A,C,count); 
}
} 
int main() 
{       
   int i,j,k,n;
   FILE *ptr,*fptr;
   ptr=fopen("Tohcount.txt","a");
   srand(time(NULL));
   for(i=3;i<=30;i++)
     {
        

        //cin >>n;
        int count=0;
	    towerOfHanoi(i, 1, 2, 3,&count);
	    fprintf(ptr,"%d\t%d\n",i,count);
	    //cout<<"Number of Bsic operations are "<<count <<endl;
	}
	return 0; 
} 

