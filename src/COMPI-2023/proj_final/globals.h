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
    IF,       /* IF  */
    ELSE,     /* ELSE  */
    INT,      /* INT  */
    RETURN,   /* RETURN  */
    VOID,     /* VOID  */
    WHILE,    /* WHILE  */
    ID,       /* ID  */
    NUM,      /* NUM  */
    LT,       /* LT  */
    LE,       /* LE  */
    GT,       /* GT  */
    GE,       /* GE  */
    EQ,       /* EQ  */
    NEQ,      /* NE  */
    SEMI,     /* SEMI  */
    LPAREN,   /* LPAREN  */
    RPAREN,   /* RPAREN  */
    LBRACE,   /* LBRACE  */
    RBRACE,   /* RBRACE  */
    LBRACKET, /* LBRACKET  */
    RBRACKET, /* RBRACKET  */
    PLUS,     /* PLUS  */
    MINUS,    /* MINUS  */
    TIMES,    /* TIMES  */
    OVER,     /* OVER  */
    COMMA,    /* COMMA  */
    ASSIGN,   /* ASSIGN  */
    ERROR,    /* ERROR  */
    LTE,      /* LTE  */
    GTE,      /* GTE  */
    SCOMMENT, /* SCOMMENT  */
    ECOMMENT  /* ECOMMENT  */
} TokenType;

bool Error;

#define MAXCHILDREN 3

// typedef enum { StmtK,
//                ExpK,
//                DeclK } NodeKind;
// typedef enum { IfK,
//                RepeatK,
//                AssignK,
//                CompoundK,
//                ReturnK } StmtKind;
// typedef enum { OpK,
//                ConstK,
//                IdK,
//                TypeK,
//                ArrIdK,
//                CallK,
//                CalcK } ExpKind;
// typedef enum { VarK,
//                FunK,
//                ArrParamK,
//                ArrVark,
//                 } DeclKind;
// typedef enum { Void,
//                Integer,
//                IntegerArray } ExpType;

// typedef struct treeNode {
//     struct treeNode *child[MAXCHILDREN];
//     struct treeNode *sibling;
//     NodeKind nodekind;
//     int lineno;

//     union {
//         StmtKind stmt;
//         ExpKind exp;
//         DeclKind decl;
//     } kind;

//     union {
//         TokenType op;
//         TokenType type;
//         int val;
//         char *name;
//         // ArrAttr arr;
//         struct ScopeListRec *scope;
//     } attr;

//     ExpType type;
//     int size;
// } TreeNode;

#endif
