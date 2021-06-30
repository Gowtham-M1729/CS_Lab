%{
	int oprtrs = 0, oprnds = 0;
	FILE *fp;
%}

%%
("+"|"-"|"*"|"/") {oprtrs++;}
[0-9]+(\.[0-9]+)?|[a-zA-Z][a-zA-Z0-9_]* {oprnds++;}
(.|\n) ;
%%

int yywrap() {}

int main()
{
	fp = (FILE *) fopen("Exp.txt", "r");
	yyin = fp;
	yylex();
	printf("Operators: %d\nOperands: %d\n",oprtrs, oprnds);
	return 0;
}
