#ifndef GLOBALS_H
#define GLOBALS_H
#include "globals.h"
#endif

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