%{
#include <stdio.h>
#include <stdlib.h>

#define YYPARSER 

int yyerror(char * message);
#include "lex.h"
static int yylex(void);
static int yywrap(void);

extern TokenType tok_atual;
extern char tokenString_atual[100];

// #include "defines.h"

%}

%union {
    float f;
    char ch;
}

%token <f> tNUM
%type <f> tE tT tF
%type <ch> '+' '-' '*' '/' '(' ')'
%%

/**************************/
/* Grammar rules          */
/**************************/

S : tE           {printf("%f\n",$1); exit(0);}
  ;

tE : tE '+' tT     {$$ = $1 + $3; printf("a: %f, %f, %c, %f\n",$$, $1, $2, $3);}
  | tE '-' tF     {$$ = $1 - $3; printf("b: %f, %f, %c, %f\n",$$, $1, $2, $3);}
  | tT           {$$ = $1; printf("c: %f, %f\n",$$, $1);}
  ;

tT : tT '*' tF     {$$ = $1 * $3; printf("d: %f, %f, %c, %f\n",$$, $1, $2, $3);}
  | tT '/' tF     {$$ = $1 / $3; printf("e: %f, %f, %c, %f\n",$$, $1, $2, $3);}
  | tF           {$$ = $1; printf("f: %f, %f\n",$$, $1);}
  ;

tF : '(' tE ')'   {$$ = $2; printf("g: %f, %f\n",$$, $2);}
  | '-' tF       {$$ = - $2; printf("h: %f, %f\n",$$, $2);}
  | tNUM         {$$ = $1; printf("\n(%d) i: %f, %f\n",tok_atual, $$, $1);}
  ;


%%

/**************************/
/* Additional C code      */
/**************************/

int yyerror(char * message) {
  printf("\033[0;31m");
  printf("Syntax error at line %d: %s\n",buffer->linha,message);
  printf("Current token: ");
  printf("%s(%d)\n",tokenString_atual, tok_atual);
  printf("\033[0m");
  Error = TRUE;
  exit(1);
}


static int yylex(void) {
  int ret = tabledriven(tokenString_atual, tok_atual, TRUE);
  tok_atual = ajusta_token(tok_atual);
  yylval.f = atof(tokenString_atual);

  return tok_atual;
}

// TreeNode * parse(void) {
//   yyparse();
//   return savedTree;
// }