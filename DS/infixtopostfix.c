#include<stdio.h>
#include<string.h>

#define SIZE 20

struct STACK
{
  char item[SIZE];
  int topOfStack;
};

typedef struct STACK  stack;

void push(char c, stack *s)
{
  if(s->topOfStack == SIZE-1)
   printf("stack is full\n");
  else
 s->topOfStack++;
 s->item[s->topOfStack] = c;
}

char pop(stack *s)
 {
    char c;
   if(s->topOfStack == -1)
   printf("stack empty\n");
  else
   c = s->item[s->topOfStack];
    s->topOfStack--;
 return c;     
}

int isOperand(char c)
{
   switch(c)
{
   case '+':
   case '-':
   case '*':
   case '/':
   case '(':
   case ')':
   case '$':
   case '^': return 0;
   default : return 1;
}
}

int stackPrecedence(char c)
{
   switch(c)
{
   case '+':
   case '-': return 2;
   case '*':
   case '/':  return 4;
   case '$':
   case '^': return 6;
   case '(': return 0;
 }
}

int inputPrecedence(char c)
{
 switch(c)
{
   case '+':
   case '-': return 1;
   case '*':
   case '/': return 3;
   case '$':
   case '^': return 8;
   case '(': return 10;
   case ')': return 0;
 }
}

void inToPost(char infix[], char postfix[])
{
  stack s;
  char c;
  int i=0, j=0;
  s.topOfStack = -1;
  while((c = infix[i++]) !='\0') 
 {

  if(isOperand(c))
   postfix[j++] = c;

    else
     {
      while(s.topOfStack != -1 && stackPrecedence(s.item[s.topOfStack]) >= inputPrecedence(c))
	{  printf("i %d----%c %c-> %d %d\n",i,s.item[s.topOfStack],c,stackPrecedence(s.item[s.topOfStack]),inputPrecedence(c));
	   if(c ==')')
	    {
		while(s.item[s.topOfStack] != '(' )
			 postfix[j++] = pop(&s);
		 pop(&s);
	    break;
	     }
	  else
	    postfix[j++] = pop(&s);


	}

     if(c!=')')   
       push(c,&s);

     } 

 }  

  while(s.topOfStack !=-1)
   postfix[j++] = pop(&s);

   postfix[j] = '\0';
} 


void main()
{
 char infix[30],postfix[30];

 for(;;)
 {
  printf("Enter the expression ------------- \n0 to stop execution\n");
  scanf("%s", infix);

  if(strcmp(infix,"0")==0)
     break;

  inToPost(infix, postfix);

  printf("%s\n", postfix);
  }
 
}
