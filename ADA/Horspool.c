#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500
int t[MAX],count=0;
FILE *fp1,*fp2;
void shifttable(char p[]) {
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[]) {
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\n Length of pattern=%d",m);
	i=m-1;
	while(i<n) {
		k=0;
		count++;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		{ count++;
		   k++;
		   }
		if(k==m)
		   return(i-m+1); else
		   i+=t[src[i]];
	}
	return -1;
}
void worstcase(int k)
{  char txt[200]="AAAAAA";
   char pat[100] = "ZAA";
   int j,l=0,pos;
   for ( j =strlen(txt); l <k; j++,l++) 
         txt[j]='A';
         l=0;
   for ( j = strlen(pat); l < k/4; j++,l++) 
        pat[j]='A';
   shifttable(pat);
   count=0;
   pos=horspool(txt,pat);
	if(pos>=0)
	  fprintf(fp1,"Text:%s\nPattern:%s\nThe desired pattern was found starting from position %d\n",txt,pat,pos+1); else
	  fprintf(fp1,"Text:%s\nPattern:%s\nThe pattern was not found in the given text\n",txt,pat);
	  fprintf(fp2,"%d\t%d\t%d\t",(k+6),3+k/4,count); 
}
void bestcase(int k)
{  char txt[200]="AAAAAA";
   char pat[100] = "AAA";
   int j,l=0,pos;
   for ( j = strlen(txt); l < k; j++,l++) 
         txt[j]='A';
         l=0;
   for ( j = strlen(pat); l < k/4; j++,l++) 
        pat[j]='A';
   shifttable(pat);
   count=0;
   pos=horspool(txt,pat);
	if(pos>=0)
	  fprintf(fp1,"Text:%s\nPattern:%s\nThe desired pattern was found starting from position %d\n",txt,pat,pos+1); else
	  fprintf(fp1,"Text:%s\nPattern:%s\nThe pattern was not found in the given text\n",txt,pat);
	  fprintf(fp2,"%d\n",count);
}
int main()
{    
	 srand(time(NULL));
	 
     remove("Patterncount.txt");
     remove("Patternvalue.txt");
     fp2 = fopen("Patterncount.txt","a");
     fp1 = fopen("Patternvalue.txt","a");
	 for(int i=4;i<=100;i=i+10)
	  {   count=0;
	      printf("Entering two strings\n");
	      worstcase(i);
	      bestcase(i);
	     
	      
	  } 
	 return 0;
}

