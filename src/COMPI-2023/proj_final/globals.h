#ifndef _GLOBALS_H_
#define _GLOBALS_H_

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

typedef enum tk {
    END_OF_FILE,
    // Reserved Words
    ELSE,
    IF,
    INT,
    RETURN,
    VOID,
    WHILE,
    // Special Symbols
    PLUS,      // +
    MINUS,     // -
    TIMES,     // *
    OVER,      // /
    LT,        // <
    LTE,       // <=
    GT,        // >
    GTE,       // >=
    EQ,        // ==
    NEQ,       // !=
    ASSIGN,    // =
    SEMI,      // ;
    COMMA,     // ,
    LPAREN,    // (
    RPAREN,    // )
    LBRACKET,  // [
    RBRACKET,  // ]
    LBRACE,    // {
    RBRACE,    // }
    SCOMMENT,  // /*
    ECOMMENT,  // */
    // Others
    ID,    // identificador
    NUM,   // número
    ERROR  // erro
} TokenType;

#define MAXCHILDREN 3

typedef enum { StmtK,
               ExpK,
               Decl } NodeKind;
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
               ParamK,
               ArrParamK,
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

} TreeNode;

#endif
