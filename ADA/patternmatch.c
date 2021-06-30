#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
FILE *fp1,*fp2;
void search(char* pat, char* txt,int *count)
{
	int m= strlen(pat);
	int n= strlen(txt);
	int i=0;
	 while(i<=n-m) {
		int j=0;
		while(j<m && txt[i+j]==pat[j])
		{
			j=j+1;
			*count+=1;
			
	    }
	    

		if (j == m)
		{
			printf("Pattern found at index %d \n", i);
			break;
			}
			*count+=1;
		i++;
	}
	if(i>n-m)
	  {
	  printf("No pattern is present in given text\n");
	  }
}
void worstcase(int k)
{  char txt[100]="AAAAAAAAAAAAAAAAAA";
   char pat[100] = "AAAB";
   int j,count=0,l=0;
   for ( j = strlen(txt); l < 2*k+1; j++,l++) 
         txt[j]='A';
         l=0;
   for ( j = strlen(pat)-1; l < k; j++,l++) 
        pat[j]='A';
        pat[j]='Z';
   printf("Text:%s\tPattern:%s\n",txt,pat);
   search(pat, txt,&count);
   fp2 = fopen("Patterncount.txt","a");
   fprintf(fp2,"%d\t%d\t",2*k+1+18,count);
          //fclose(fp2);
printf("No of count is %d \n", count);   
}
void bestcase(int k)
{  char txt[100]="AAAAAAAAAAAAAAAAAA";
   char pat[100] = "AA";
   int j,count=0,l=0;
   for ( j = strlen(txt); l < 2*k-1; j++,l++) 
         txt[j]='A'+rand()%26;
         l=0;
   for ( j = strlen(pat)-1; l < k; j++,l++) 
        pat[j]='A';
   printf("Text:%s\tPattern:%s\n",txt,pat);
   search(pat, txt,&count);
   //fp2 = fopen("Patterncount.txt","a");
   fprintf(fp2,"%d\t",count);
          //fclose(fp2);
printf("No of count is %d \n", count);   
}
void Avgcase(char txt[],char pat[],int k)
{    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n', 
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
       int count=0,j;
          for ( j = 0; j < 4*(k+1); j++) 
              txt[j]=alphabet[rand() % 2];
          for ( j = 0; j < k+2; j++) 
              pat[j]=alphabet[rand() % 1];
           printf("Text:%s\tPattern:%s\n",txt,pat);
           search(pat, txt,&count);
	      //fp2 = fopen("Patterncount.txt","a");
          fprintf(fp2,"%d\n",count);
	      printf("No of count is %d \n", count);
              }
int main()
{    int count,j;
	 char txt[100],pat[100];
	 srand(time(NULL));
	 
     remove("Patterncount.txt");
     remove("Patternvalue.txt");
	 for(int i=0;i<=10;i++)
	  {   count=0;
	      printf("Entering two strings\n");
	      //scanf("%s %s",txt,pat);
	      //char txt[] = "AABPAABPAABPAABPAABP";
	      worstcase(i);
	      bestcase(i);
	      Avgcase(txt,pat,i);
	     
	      
	  } 
	 return 0;
}

