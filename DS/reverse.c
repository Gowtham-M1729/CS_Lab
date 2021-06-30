#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct operatorStack{
    int top;
    char items[20];
};
typedef struct operatorStack* operatorStack;

void push(char c, operatorStack S){
    if(S->top==19) printf("Stack overflow\n");
    else S->items[++S->top]=c;
}

char pop(operatorStack S){
    if(S->top==-1) printf("Stack underflow\n");
    else return S->items[S->top--];
}

int isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '$':
        case '^': return 1;
        default: return 0;
    }
}

int stackPrecedence(char c){
    switch(c){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '$':
        case '^': return 6;
        case '(': return 0;
    }
}

int inputPrecedence(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '$':
        case '^': return 7;
        case '(': return 9;
        case ')': return 0;
    }
}

void infixToprefix(char infix[],char prefix[]){
    operatorStack S = (operatorStack)malloc(sizeof(struct operatorStack));
    S->top=-1;
    char c;
    int i=0,j=0;
    while((c=infix[i++]) != '\0'){
        if(!isOperator(c)){
            prefix[j++] =c;
        }
        else{
            while(S->top != -1 && stackPrecedence(S->items[S->top]) > inputPrecedence(c)){
                if(c==')'){
                    while(S->items[S->top] != '(') {
                        prefix[j++]=pop(S);
                    }
                    pop(S);//remove "(" also
                    break;//breaks while loop at line no. 72
                }else{
                    prefix[j++]=pop(S);
                }
            }
            if(c!=')'){
                push(c,S);
            }
        }
    }

    while(S->top!=-1){
        prefix[j++]=pop(S);
    }
    prefix[j]='\0';
    free(S);
}

int main(){
    char infix[30],prefix[30],reverseinfix[30];
    int choice;
    while(1){
        printf("\n0.Exit\n1.Conversion\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: printf("Enter the infix expression:");
                    scanf("%s",infix);
                    printf("%s",infix);
                    for(int i=strlen(infix),j=0;i>=0;i--,j++)
                    {  
                        if( infix[i] == '(' )
                            reverseinfix[j] = ')';
                        else if( infix[i] == ')' )
                            reverseinfix[j] = '(';
                        else 
                            reverseinfix[j] = infix[i];
                    }
                    printf("%s",reverseinfix);
                    infixToprefix(reverseinfix,prefix);
                    printf("prefix expression: %s \n",prefix);
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}
