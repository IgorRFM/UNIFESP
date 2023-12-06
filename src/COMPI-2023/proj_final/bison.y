%{

#include <stdio.h>
#include <stdlib.h>

#define YYPARSER 
int yyerror(char * message);

#include "lex.h"

static int yylex(void);
static int yywrap(void);

TokenType toktok = ERROR;
extern char tokenString_atual[100];
// static int savedNumber;
// static TreeNode* aas;


%}


%token t_IF t_ELSE t_INT t_RETURN t_VOID t_WHILE
%token t_ID t_NUM
%token t_LT t_LTE t_GT t_GTE t_EQ t_NEQ

%%


t_programa : t_declList{
                printf("Programa\n");
                $$ = $1;
                }

t_declList : t_declList t_decl 
            { printf("decl list\n");
              $$ = $1 + $2;
            }
         | t_decl {
         printf("decl\n");
         $$ = $1;}
         ;

t_decl : t_vardecl {$$ = $1; 
printf("v_decl\n");}
     | t_funDecl {$$ = $1;
      printf("f_decl\n");}
     ;

t_vardecl : t_tipoEspec t_ID ';' {
            printf("var decl\n");
                            $$ = $1 + $2;      }
        | t_tipoEspec t_ID '[' t_NUM ']' ';' {
          printf("[var decl]\n");
             $$ = $1 + $2 + $3 + $4 + $5 + $6;
                    }
        ;

t_tipoEspec : t_INT {$$ = $1;
                    printf("Tipo espec. INT\n");}
          | t_VOID{
            printf("Tipo espec. VOID\n");
            $$ = $1;
            }
          ;

t_funDecl : t_tipoEspec t_ID '(' t_params ')' t_compdecl {
  printf("fun decl\n");
             $$ = $1 + $2 + $3 + $4 + $5;
            }
            |
          ;

t_params : t_paramList {printf("params\n");$$ = $1;}|;

t_paramList : t_paramList ',' t_param {
            printf("param list\n");
            $$ = $1+$2+$3;
            
            }
            | t_param {printf("param\n");$$ = $1;}
            ;

t_param : t_tipoEspec t_ID {
        printf("param\n");
          $$ = $1+$2;
          }
          | t_tipoEspec t_ID '[' ']' {
            $$ = $1 + $2;
            printf("param\n");
          }
          ;
t_compdecl : '[' t_localdecl t_stmtlista ']'
                { 
                  $$ = $1 + $2 + $3 + $4;
                  printf("comp decl\n");

                }
              ;

t_localdecl : t_localdecl t_vardecl
                     {
                      $$ = $1 + $2;
                      printf("local dcl\n"); 

                     }

t_stmtlista : t_stmtlista t_stmt
                 {$$ = $1 + $2;
                  printf("stmt lista\n "); 
                 }
               

t_stmt : t_expdecl { $$ = $1;printf("stmt exp\n" );}
          | t_compdecl {$$ = $1;printf("stmt comp\n");}
          | t_selecdecl { $$ = $1; printf("stmt selec\n");}
          | t_iterdecl { $$ = $1;printf("stmt iter\n");}
          | t_retornodecl {$$ = $1;printf("stmt retorno\n");}
          ;

t_expdecl : t_exp ';' { printf(";"); $$ = $1;}
                | ';' {  printf(";");$$ = $1;}
                ;

t_selecdecl : t_IF '(' t_exp ')' t_stmt
                 { 
                  printf( "if(exp)algo\n");
                  $$ = $1 + $2 + $3 + $4 + $5;
                 }
               | t_IF '(' t_exp ')' t_stmt t_ELSE t_stmt
                 { printf( "if(exp)algo else algo\n");
                 $$ = $1 + $2 + $3 + $4 + $5 + $6 + $7;
                  
                 }
               ;

t_iterdecl : t_WHILE '(' t_exp ')' t_stmt
                 { 
                  $$ = $1 + $2 + $3 + $4 + $5;
                    printf( "while\n");
                    
                  
                 }
               ;

t_retornodecl : t_RETURN ';'
              {  $$ = $1 + $2;
                printf( "return\n");
              }
            | t_RETURN t_exp ';'
              {  $$ = $1 + $2;
                printf( "return\n");
              }
            ;

t_exp : t_VAR '=' t_exp
             {  $$ = $1 + $2;
              printf( "exp\n");
             }
           | t_simpleexp { $$ = $1;
            printf( "exp_simpleexp\n");
            }
           ;

t_VAR : t_ID
      {$$ = $1;
        printf( "var\n");
      }
    |'[' t_ID ']'{
      printf( "arr\n");
       $$ = $2;
      } '[' t_exp ']'
      {$$ = $2;
        printf("[var]\n");
      }
    ;

t_simpleexp : t_somaexp t_comp t_somaexp
                    { $$ = $1 + $2 + $3;
                      printf( "simpleexp\n");
                    }
                  | t_somaexp { $$ = $1;
                    printf( "simpt_LTEsexp_termo\n");}
                  ;

t_comp : t_LT
        {
          printf( "lt\n");$$ = $1;
        }
      | t_LTE
        {
          printf( "lte\n");$$ = $1;
        }
      | t_GT
        {
          printf( "gt\n");$$ = $1;
        }
      | t_GTE
        {
          printf( "gte\n");$$ = $1;
        }
      | t_EQ
        { printf( "eq\n");$$ = $1;
        }
      | t_NEQ
        { $$ = $1;
          printf( "neq\n");
        }
      ;

t_somaexp : t_somaexp t_soma t_termo
                      { $$ = $1 + $2 + $3;
                        printf( "somaexp\n");
                      }
                    | t_termo { $$ = $1;
                      printf( "somaexp_termo\n");
                        }
                    ;

t_soma : '+'
        { $$ = $1;
          printf("mais\n");
        }
      | '-'
        { $$ = $1;
          printf("menos\n");
        }
      ;

t_termo : t_termo t_mult t_fator
       {$$ = $1 + $2 + $3;
        printf("termo\n") ;
       }
     | t_fator { $$ = $1; printf( "t_fator\n"); }
     ;

t_mult : '*'
        {$$ = $1;
          printf("mult\n");
        }
      | '/'
        { $$ = $1;
          printf("div\n");
        }
      ;

t_fator : '(' t_exp ')' {$$ = $2; printf( "(fator)\n");}
       | t_VAR {$$ = $1; printf( "fator_var\n");}
       | t_ativ {$$ = $1; printf( "fator_ativ\n"); }
       | t_NUM
         { $$ = $1; printf ("fator_num\n"); }
         ;
       

t_ativ : t_ID {$$ = $1;
        printf("ativ\n");
         } 
         | '(' t_args ')' {$$ = $1;
          printf("ativ_args\n");
       }
     ;

t_args : t_arglista { $$ = $1; printf("args\n"); }
     | { printf( "null\n"); $$ = NULL; }
     ;

t_arglista : t_arglista ',' t_exp
           {
            $$ = $1;
           printf( "arglista\n");
           }
         | t_exp {
          $$ = $1;
           printf( "arglista\n"); }
         ;





%%

int yyerror(char * message) {
  printf("\033[0;31m");
  printf("Syntax error at line %d: %s\n",buffer->linha,message);
  printf("Current token: ");
  printf("%s(%d)\n",tokenString_atual, toktok);
  printf("\033[0m");
  Error = TRUE;
  exit(1);
}


static int yylex(void) { 
  toktok = ERROR;
  toktok = tabledriven(tokenString_atual, toktok, FALSE);
  int temp = toktok;
  toktok = ajusta_token(toktok);
  // yylval.f = atof(tokenString_atual);

  return toktok;
}

// TreeNode * parse(void) {
//   yyparse();
//   t_RETURN savedTree;
// }