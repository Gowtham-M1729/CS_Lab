%{
	int count = 0;
	FILE *fp;
%}

/* Rules */
chars [a-zA-Z]
digit [0-9]
us _

%%
{digit}+({chars}|{digit}|{us})+ ; 
{chars}({chars}|{digit}|{us})+ {count++;}
(.|\n) ; 
%%

int yywrap(void) {}

int main()
{
	fp = (FILE *) fopen("vloop.c", "r");
	yyin = fp;
	yylex();
	printf("Number of identifiers: %d\n", count);
	return 0;
}

