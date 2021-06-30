#include<stdio.h>
#include<stdlib.h>
void main()
{ int i,j,k=0;
  char c;
  FILE *ptr,*fptr;
  fptr=fopen("vowels.txt","r");
  //fptr = fopen(filename, "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    }
  c = fgetc(fptr); 
   while (c != EOF) 
    { 
        printf ("%c", c);
        
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' || c == 'A' ||
            c == 'E' || c == 'I' || c == 'O' ||
            c == 'U')
            k++;
        c = fgetc(fptr); 
    }
    printf("Number of Vowels is %d:\n",k);
}
    
