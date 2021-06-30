/*lex code to accept a valid email */
%{
int flag = 0; 
%}  
%% 
[a - z.0 - 9 _]+@[gmail]+".com"|".in" {
flag = 1; }
%%
int main() {
yylex();
if (flag == 1)
	printf("Accepted");
else
	printf("Not Accepted");
	return 0;
}

