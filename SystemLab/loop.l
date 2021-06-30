%{
#include<stdio.h>
#include<ctype.h>
int c=1;
int forcount=0;
%}
op "++"|"--"
rop "<"|">"|"<="|">="|"=="|"!="
id [a-zA-Z][a-zA-Z0-9]*
no [0-9]*
blank " "
pp [\n]
for "for"{blank}*\(({id}=({no}|{id}))?\;{id}{rop}({id}|{no})\;{id}{op}\){pp}+\{(.\n).*\} 
%%
for {forcount++;c=0;} 
%%
int main()
{ yyin=fopen("vloop.c","r");
yylex();
if(c==1)
printf("incorrect");
if(c==0)
printf("correct");

}
int yywrap()
{
return 1;
}
