#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#define FALSE 0
#define tam_buffer 50

FILE *arqv_ptr;
FILE *code;

typedef struct tipobuffer {
    char *buf;
    int tam;
    int pos;  // pos do próximo char a ser lido.
    int linha;

} buffer_texto;

buffer_texto *buffer;

typedef enum {
    END_OF_FILE,
    // Reserved Words
    IF = 258,       /* IF  */
    ELSE = 259,     /* ELSE  */
    INT = 260,      /* INT  */
    RETURN = 261,   /* RETURN  */
    VOID = 262,     /* VOID  */
    WHILE = 263,    /* WHILE  */
    ID = 264,       /* ID  */
    NUM = 3,        /* NUM  */
    LT = 266,       /* LT  */
    LE = 267,       /* LE  */
    GT = 268,       /* GT  */
    GE = 269,       /* GE  */
    EQ = 270,       /* EQ  */
    NEQ = 271,      /* NE  */
    SEMI = 272,     /* SEMI  */
    LPAREN = 273,   /* LPAREN  */
    RPAREN = 274,   /* RPAREN  */
    LBRACE = 275,   /* LBRACE  */
    RBRACE = 276,   /* RBRACE  */
    LBRACKET = 277, /* LBRACKET  */
    RBRACKET = 278, /* RBRACKET  */
    PLUS = 279,     /* PLUS  */
    MINUS = 280,    /* MINUS  */
    TIMES = 281,    /* TIMES  */
    OVER = 282,     /* OVER  */
    COMMA = 283,    /* COMMA  */
    ASSIGN = 284,   /* ASSIGN  */
    ERROR = 285,    /* ERROR  */
    LTE = 286,      /* LTE  */
    GTE = 287,      /* GTE  */
    SCOMMENT = 289, /* SCOMMENT  */
    ECOMMENT = 290  /* ECOMMENT  */
} TokenType;

bool Error;

#define MAXCHILDREN 3

typedef enum { StmtK,
               ExpK,
               DeclK } NodeKind;
typedef enum { IfK,
               RepeatK,
               AssignK,
               CompoundK,
               ReturnK } StmtKind;
typedef enum { OpK,
               ConstK,
               IdK,
               TypeK,
               ArrIdK,
               CallK,
               CalcK } ExpKind;
typedef enum { VarK,
               FunK,
               ArrParamK,
               ArrVarK,
               ParamK } DeclKind;
typedef enum { Void,
               Integer,
               IntegerArray } ExpType;

typedef struct treeNode {
    struct treeNode *child[MAXCHILDREN];
    struct treeNode *sibling;
    NodeKind nodekind;
    int lineno;

    union {
        StmtKind stmt;
        ExpKind exp;
        DeclKind decl;
    } kind;

    union {
        TokenType op;
        TokenType type;
        int val;
        char *name;
        // ArrAttr arr;
        struct ScopeListRec *scope;
    } attr;

    ExpType type;
    int size;
} TreeNode;

#endif
