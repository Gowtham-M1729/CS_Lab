#include<stdio.h>
#include<stdlib.h>
void main()
{ 
char a[10],b[20];
FILE *p,*q;
p=fopen("ovbd.txt","r");
if(p==NULL)
{ printf("unable to create a file");
exit(0);
}
q=fopen("jgf.txt","a");
if(q==NULL)
{ printf("unable to create a file");
exit(0);
}
fgets(a,9,p);
fputs(a,q);
fgets(b,20,q);
fputs(b,stdout);
fclose(p);
fclose(q);
}

