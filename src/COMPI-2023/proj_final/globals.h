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