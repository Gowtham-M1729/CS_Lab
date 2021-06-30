%{
   #include<stdio.h>
   #include<stdlib.h>
   int yylex();
   void yyerror(char *str);
%}

%token ID BUILTIN SC NL COMMA

%%
start: BUILTIN varlist SC NL {
     printf("valid");
     exit(0);
}
     ;
varlist:varlist COMMA ID|ID
       |
       ;
%%
void yyerror(char *str){
   printf("Error in declaration or definition");
   exit(0);
}
int main(){
   printf("Enter variable declaration\n");
   yyparse();
   return 0;
}

