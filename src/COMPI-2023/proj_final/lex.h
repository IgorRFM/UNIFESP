#ifndef FALSE
#define FALSE 0
#endif

#ifndef GLOBALS_H
#define GLOBALS_H
#include "globals.h"
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef bool
#define bool int
#endif

char get_next_char();

void printtoken(char* tk, TokenType tok);

bool digito(char c);
bool letra(char c);

void unget_next_char();

TokenType busca_reservadas(char* s);

int tabledriven(char* tk, TokenType tok, bool print);

int ajusta_token(TokenType token);