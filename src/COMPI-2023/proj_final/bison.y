%{
#define YYSTYPE TreeNode *
#include <stdio.h>
#include <stdlib.h>

#define YYPARSER 
int yyerror(char * message);
#include "lex.h"
#include "util.h"
static int yylex(void);
static int yywrap(void);

TokenType toktok = ERROR;
extern char tokenString_atual[100];
static int savedNumber;
static TreeNode* aas;

// #include "defit_NEQs.h"

%}


%token t_IF t_ELSE t_INT t_RETURN t_VOID t_WHILE
%token t_ID t_NUM
%token t_LT t_LTE t_GT t_GTE t_EQ t_NEQ

%%

/**************************/
/* Grammar rut_LTEs          */
/**************************/

t_programa : t_declList{
                printTree(aas);
                aas=$1;
                printf("Programa\n");
                }

t_declList : t_declList t_decl 
            { printf("decl list\n");
              TreeNode * t = $1;
              if( t == NULL){
                $$ = $2;
            }else{
              while(t->sibling != NULL){ // percorre ate o ut_LTimo irmao
                t = t->sibling;
              }
              t->sibling = $2;
              $$ = $1;
            }
            }
         | t_decl {$$ = $1; printf("decl\n");}
         ;

t_decl : t_vardecl {$$ = $1;
printf("decl\n");}
     | t_funDecl {$$ = $1;printf("decl\n");}
     ;

t_vardecl : t_tipoEspec t_ID ';' {
  printf("var decl\n");
  $$ = newDeclNode(VarK);
                                  $$->child[0] = $1;
                                  $$->attr.name = buffer->buf;
                                  $$->lineno = buffer->linha;
                                  }
        | t_tipoEspec t_ID '[' t_NUM ']' ';' {
          printf("[var decl]\n");
               $$ = newDeclNode(ArrVarK);
                    $$->child[0] = $1;
                    $$->lineno = buffer->linha;
                    $$->type = IntegerArray;
                    $$->attr.name = buffer->buf;
                    $$->attr.val = savedNumber;}
        ;

t_tipoEspec : t_INT {$$ = newExpNode(TypeK);
                    $$->type = Integer;
                    printf("Tipo espec. INT\n");}
          | t_VOID{
            printf("Tipo espec. VOID\n");
            $$ = newExpNode(TypeK);
                    $$->type = Void;}
          ;

t_funDecl : t_tipoEspec t_ID '(' t_params ')' t_compdecl {
  printf("fun decl\n");
              $$ = newDeclNode(FunK);
              $$->lineno = buffer->linha;
              $$->attr.name = buffer->buf;
              $$->child[0] = $1;
              $$->child[1] = $4;
              $$->child[2] = $6;
            }
          ;

t_params : t_paramList {$$ = $1; printf("params\n");};

t_paramList : t_paramList ',' t_param {
            printf("param list\n");
            TreeNode *t = $1;
            while(t->sibling != NULL){ // percorre ate o ut_LTimo irmao
              t = t->sibling;
            }
            t->sibling = $3;
            $$ = $1;
            }
            | t_param {$$ = $1;}
            ;

t_param : t_tipoEspec t_ID {
        printf("param\n");
          $$ = newDeclNode(ParamK);
          $$->child[0] = $1;
          $$->attr.name = buffer->buf;
          }
          | t_tipoEspec t_ID '[' ']' {
            printf("param\n");
            $$ = newDeclNode(ArrParamK);
            $$->child[0] = $1;
            strcpy($$->attr.name, buffer->buf);
          }
          ;
t_compdecl : '[' t_localdecl t_stmtlista ']'
                { 
                  printf("comp decl\n");
                  $$ = newStmtNode(CompoundK);
                  $$->child[0] = $2;
                  $$->child[1] = $3;
                }
              ;

t_localdecl : t_localdecl t_vardecl
                     {
                      printf("local dcl\n"); 
                      TreeNode * t = $1;
                       if (t != NULL) {
                         while (t->sibling != NULL) { t = t->sibling; }
                         t->sibling = $2;
                         $$ = $1;
                       } else {
                         $$ = $2;
                       }
                     }
                   | { $$ = NULL; }
                   ;

t_stmtlista : t_stmtlista t_stmt
                 {
                  printf("stmt lista\n "); 
                  TreeNode * t = $1;
                   if (t != NULL) {
                     while (t->sibling != NULL) { t = t->sibling; }
                    t->sibling = $2;
                    $$ = $1;
                   } else {
                     $$ = $2;
                   }
                 }
               | { $$ = NULL; }
               ;

t_stmt : t_expdecl { $$ = $1; printf("stmt exp\n" );}
          | t_compdecl { $$ = $1; printf("stmt comp\n");}
          | t_selecdecl { $$ = $1; printf("stmt selec\n");}
          | t_iterdecl { $$ = $1; printf("stmt iter\n");}
          | t_retornodecl { $$ = $1; printf("stmt retorno\n");}
          ;

t_expdecl : t_exp ';' { $$ = $1; printf(";");}
                | ';' { $$ = NULL; printf(";");}
                ;

t_selecdecl : t_IF '(' t_exp ')' t_stmt
                 { 
                  printf( "if(exp)algo\n");
                  $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
               | t_IF '(' t_exp ')' t_stmt t_ELSE t_stmt
                 { printf( "if(exp)algo else algo\n");
                  $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
               ;

t_iterdecl : t_WHILE '(' t_exp ')' t_stmt
                 { 
                    printf( "while\n");
                    
                  $$ = newStmtNode(RepeatK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
               ;

t_retornodecl : t_RETURN ';'
              { 
                printf( "return\n");
                $$ = newStmtNode(ReturnK);
                $$->type = Void;
              }
            | t_RETURN t_exp ';'
              { 
                printf( "return\n");
                $$ = newStmtNode(ReturnK);
                $$->child[0] = $2;
              }
            ;

t_exp : t_VAR '=' t_exp
             { 
              printf( "exp\n");
              $$ = newStmtNode(AssignK);
               $$->child[0] = $1;
               $$->child[1] = $3;
             }
           | t_simpleexp { 
            printf( "exp_simpleexp\n");
            $$ = $1; }
           ;

t_VAR : t_ID
      {
        printf( "var\n");
         $$ = newExpNode(IdK);
        $$->attr.name = buffer->buf;
      }
    |'[' t_ID ']'{
      printf( "arr\n");
        $$ = newExpNode(ArrIdK);
        $$->attr.name = buffer->buf;
      } '[' t_exp ']'
      {
        printf("[var]\n");
        $$ = $2;
        $$->child[0] = $4;
      }
    ;

t_simpleexp : t_somaexp t_comp t_somaexp
                    { 
                      printf( "simpleexp\n");
                      $$ = newExpNode(CalcK);
                      $$->child[0] = $1;
                      $$->child[1] = $2;
                      $$->child[2] = $3;
                    }
                  | t_somaexp { 
                    printf( "simpt_LTEsexp_termo\n");
                    $$ = $1; }
                  ;

t_comp : t_LT
        {
          printf( "lt\n");
           $$ = newExpNode(OpK);
          $$->attr.op = t_LT;
        }
      | t_LTE
        {
          printf( "lte\n");
           $$ = newExpNode(OpK);
          $$->attr.op = t_LTE;
        }
      | t_GT
        {
          printf( "gt\n");
           $$ = newExpNode(OpK);
          $$->attr.op = t_GT;
        }
      | t_GTE
        {
          printf( "gte\n");
           $$ = newExpNode(OpK);
          $$->attr.op = t_GTE;
        }
      | t_EQ
        { printf( "eq\n");
          $$ = newExpNode(OpK);
          $$->attr.op = t_EQ;
        }
      | t_NEQ
        { 
          printf( "neq\n");
          $$ = newExpNode(OpK);
          $$->attr.op = t_NEQ;
        }
      ;

t_somaexp : t_somaexp t_soma t_termo
                      { 
                        printf( "somaexp\n");
                        $$ = newExpNode(CalcK);
                        $$->child[0] = $1;
                        $$->child[1] = $2;
                        $$->child[2] = $3;
                      }
                    | t_termo {
                      printf( "somaexp_termo\n");
                       $$ = $1; }
                    ;

t_soma : '+'
        { 
          printf("mais\n");
          $$ = newExpNode(OpK);
          $$->attr.op = PLUS;
        }
      | '-'
        { 
          printf("menos\n");
          $$ = newExpNode(OpK);
          $$->attr.op = MINUS;
        }
      ;

t_termo : t_termo t_mult t_fator
       {
        printf("termo\n") ;
        $$ = newExpNode(CalcK);
         $$->child[0] = $1;
         $$->child[1] = $2;
         $$->child[2] = $3;
       }
     | t_fator { $$ = $1; }
     ;

t_mult : '*'
        {
          printf("mult\n");
           $$ = newExpNode(OpK);
          $$->attr.op = TIMES;
        }
      | '/'
        { 
          printf("div\n");
          $$ = newExpNode(OpK);
          $$->attr.op = OVER;
        }
      ;

t_fator : '(' t_exp ')' { $$ = $2; printf( "(fator)\n");}
       | t_VAR { $$ = $1; printf( "fator_var\n");}
       | t_ativ { $$ = $1; printf( "fator_ativ\n"); }
       | t_NUM
         { $$ = newExpNode(ConstK);
           $$->type = Integer;
           $$->attr.val = atoi(buffer->buf);
         };
       ;

t_ativ : t_ID {
        printf("ativ\n");
         $$ = newExpNode(CallK);
         $$->attr.name = buffer->buf;
         } '(' t_args ')' {
           $$ = $2;
           $$->child[0] = $4;
       }
     ;

t_args : t_arglista { $$ = $1; printf("args\n"); }
     | { printf( "null\n"); $$ = NULL; }
     ;

t_arglista : t_arglista ',' t_exp
           {
            printf("arglista\n");
            TreeNode * t = $1;
             if (t != NULL) {
               while (t->sibling != NULL) { t = t->sibling; }
               t->sibling = $3;
               $$ = $1;
             } else {
               $$ = $3;
             }
           }
         | t_exp { $$ = $1; }
         ;




// S : tE           {printf("%f\n",$1); exit(0);}
//   ;

// tE : tE '+' tT     {$$ = $1 + $3; printf("a: %f, %f, %c, %f\n",$$, $1, $2, $3);}
//   | tE '-' tF     {$$ = $1 - $3; printf("b: %f, %f, %c, %f\n",$$, $1, $2, $3);}
//   | tT           {$$ = $1; printf("c: %f, %f\n",$$, $1);}
//   ;

// tT : tT '*' tF     {$$ = $1 * $3; printf("d: %f, %f, %c, %f\n",$$, $1, $2, $3);}
//   | tT '/' tF     {$$ = $1 / $3; printf("e: %f, %f, %c, %f\n",$$, $1, $2, $3);}
//   | tF           {$$ = $1; printf("f: %f, %f\n",$$, $1);}
//   ;

// tF : '(' tE ')'   {$$ = $2; printf("g: %f, %f\n",$$, $2);}
//   | '-' tF       {$$ = - $2; printf("h: %f, %f\n",$$, $2);}
//   | tNUM         {$$ = $1; printf("\n(%d) i: %f, %f\n",tok_atual, $$, $1);}
//   ;


%%

/**************************/
/* Additional C code      */
/**************************/

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
  toktok = tabledriven(tokenString_atual, toktok, TRUE);
  int temp = toktok;
  toktok = ajusta_token(toktok);
  // yylval.f = atof(tokenString_atual);

  return toktok;
}

// TreeNode * parse(void) {
//   yyparse();
//   t_RETURN savedTree;
// }