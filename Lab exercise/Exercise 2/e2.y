%{
#include <stdio.h>
#include <stdlib.h>

int flag = 0;
int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%left '*'
%left '/'
%left '+' '-'

%%

input:
    expression {
        printf("Result: %d\n", $1);
    }
    ;

expression:
      expression '+' expression {
          $$ = $1 + $3;
      }
    | expression '-' expression {
          $$ = $1 - $3;
      }
    | expression '/' expression {
          if ($3 == 0) {
              yyerror("Division by zero");
              YYABORT;
          } else {
              $$ = $1 / $3;
          }
      }
    | expression '*' expression {
          $$ = $1 * $3;
      }
    | NUMBER {
          $$ = $1;
      }
    | '(' expression ')' {
          $$ = $2;
      }
    ;

%%

int main(void) {
    printf("Enter input: ");
    if (yyparse() == 0 && flag == 0)
        printf("Valid expression.\n");
    return 0;
}

void yyerror(const char *s) {
    flag = 1;
    fprintf(stderr, "Error: %s\n", s);
}
