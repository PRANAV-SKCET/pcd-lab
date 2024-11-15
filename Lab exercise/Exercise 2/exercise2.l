%{
#include <stdio.h>
#include "e2.tab.h"
%}

%%
[0-9]+  {
    yylval = atoi(yytext);
    return NUMBER;
}
[\n] { return 0; }
. { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
