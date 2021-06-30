
%{
        #include"y.tab.h"
%}

%%
(int|float|char) {return BUILTIN;}
[a-zA-Z]([a-zA-Z0-9_])* {return ID;}
, return COMMA;
; return SC;
\n return NL;
%%

int yywrap() {
   return 1;
}

