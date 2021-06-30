#include<stdio.h>
#include<math.h>
#include<string.h>

#define SIZE 20

void Evaluate(char[]);
float Compute(float, float, char);


struct stk
{
  float item[SIZE];
  int top;
};

typedef struct stk  STK;

void push(float c, STK *s)
{
  if(s->top ==SIZE-1)
   printf("stack full\n");
  else
 s->top++;
 s->item[s->top] = c;
}

float  pop(STK *s)
 {
    float c;
   if(s->top == -1)
   printf("stack empty\n");
  else
   c = s->item[s->top];
    s->top--;
 return c;      
}

int isoperand(char c)
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

void Evaluate(char  po[])
{
  STK s;
  char c;
  float op1, op2,res;
  int i=0;
  s.top = -1;
  while((c =po[i++]) !='\0') // SCAN  EXPRESSION
 {
  if(isoperand(c))
   push(c -'0', &s);

    else
     {
      op2=pop(&s);
      op1=pop(&s);
     res = Compute(op1, op2, c);
     push(res,&s);

      }

  }
res = pop(&s);
if(s.top != -1)
printf("Invalid expression\n");
else
printf("Value of the expression is:%f\n",res);
} 

float Compute(float op1, float op2, char opr)
{
  switch(opr)
  {
    case '+': return(op1+op2);
    case '-' : return(op1-op2);
    case '*' : return(op1*op2);
    case '/' : return(op1/op2);
	case '^' : return pow(op1,op2);
    case '$' : return pow(op1,op2);
    default: printf("invalid expression");
  }
}

void main()
{
 char postfix[30];

 for(;;)
 {

  printf("enter exp and 0 to stop execution\n");

  scanf("%s", postfix);
  if(strcmp(postfix,"0")==0)  break;
  Evaluate(postfix);

  }

}
