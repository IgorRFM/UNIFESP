#include "lex.h"

#include <stdbool.h>

#include "bison.tab.h"
#ifndef GLOBALS_H
#define GLOBALS_H
#include "globals.h"
#endif
void printtoken(char* tk, TokenType tok) {
    // printf("/***********/\n");
    // printf("Token: %s, tok: %d\n", tk, tok);
    // printf("/***********/\n");
    switch (tok) {
        case END_OF_FILE:
            printf("END_OF_FILE, %s\n", tk);
            break;
        case IF:
            printf("(RESERVADA) IF, %s\n", tk);
            break;
        case ELSE:
            printf("(RESERVADA) ELSE, %s\n", tk);
            break;
        case INT:
            printf("(RESERVADA) INT, %s\n", tk);
            break;
        case RETURN:
            printf("(RESERVADA) RETURN, %s\n", tk);
            break;
        case VOID:
            printf("(RESERVADA) VOID, %s\n", tk);
            break;
        case WHILE:
            printf("(RESERVADA) WHILE, %s\n", tk);
            break;
        case PLUS:
            printf("PLUS, %s\n", tk);
            break;
        case MINUS:
            printf("MINUS, %s\n", tk);
            break;
        case TIMES:
            printf("TIMES, %s\n", tk);
            break;
        case OVER:
            printf("OVER, %s\n", tk);
            break;
        case LT:
            printf("LT, %s\n", tk);
            break;
        case LTE:
            printf("LTE, %s\n", tk);
            break;
        case GT:
            printf("GT, %s\n", tk);
            break;
        case GTE:
            printf("GTE, %s\n", tk);
            break;
        case EQ:
            printf("EQ, %s\n", tk);
            break;
        case NEQ:
            printf("NEQ, %s\n", tk);
            break;
        case ASSIGN:
            printf("ASSIGN, %s\n", tk);
            break;
        case SEMI:
            printf("SEMI, %s\n", tk);
            break;
        case COMMA:
            printf("COMMA, %s\n", tk);
            break;
        case LPAREN:
            printf("LPAREN, %s\n", tk);
            break;
        case RPAREN:
            printf("RPAREN, %s\n", tk);
            break;
        case LBRACKET:
            printf("LBRACKET, %s\n", tk);
            break;
        case RBRACKET:
            printf("RBRACKET, %s\n", tk);
            break;
        case LBRACE:
            printf("LBRACE, %s\n", tk);
            break;
        case RBRACE:
            printf("RBRACE, %s\n", tk);
            break;
        case SCOMMENT:
            printf("SCOMMENT, %s\n", tk);
            break;
        case ECOMMENT:
            printf("ECOMMENT, %s\n", tk);
            break;
        case NUM:
            printf("NUM, %s\n", tk);
            break;
        case ID:
            printf("ID, %s\n", tk);
            break;
        case ERROR:
            printf("\033[0;31m");
            printf("Erro Lexico: '%s', Linha: %d\n", tk, buffer->linha + 1);
            printf("\033[0m");
            break;
        default:
            printf("Token não reconhecido, %s\n", tk);
            break;
    }
}

bool digito(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

bool letra(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

/*
get_next_char() - retorna o próximo char do arquivo, mantendo um buffer de tamanho constante tam_buffer
*/
char get_next_char() {
    if (buffer->pos == 0 || buffer->pos == buffer->tam) {
        if (fgets(buffer->buf, tam_buffer, arqv_ptr) != NULL) {
            if (strlen(buffer->buf) < tam_buffer) {
                buffer->tam = strlen(buffer->buf);
            } else {
                buffer->tam = tam_buffer;
            }
            buffer->pos = 0;
        } else {
            return EOF;
        }
    }
    char next_c = buffer->buf[buffer->pos];
    buffer->pos = buffer->pos + 1;
    if (next_c == '\n') {
        buffer->linha++;
    }
    return next_c;
}

/*
unget_char() - retorna o ponteiro do buffer para a posição anterior
*/
void unget_char() {
    buffer->pos = buffer->pos - 1;
}

/*
tabela de palavras reservadas da linguagem C-
*/
struct {
    char* str;
    TokenType tok;
} palavras_reservadas[6] = {
    {"else", ELSE},
    {"if", IF},
    {"int", INT},
    {"return", RETURN},
    {"void", VOID},
    {"while", WHILE},
};

/*
Busca melhor do que linear para palavras reservadas
*/
TokenType busca_reservadas(char* s) {
    // printf("buscando %s\n", s);
    TokenType str;
    if ((str = find(hash_table, s)) != ERROR) {
        // printf("Achado:(%d)\n", str);
        return str;
    }
    // printf("retornando ID\n");
    return ID;
}

/*
Enumeração de possíveis estados do autômato
*/
typedef enum {
    estado_INICIAL,
    estado_ATTR,
    estado_COMENTARIO,
    estado_NUM,
    estado_ID,
    estado_ACEITA
} Estado;

/*
tabledriven(char *tk, TokenType tok, bool imprimir) - retorna o próximo token do arquivo.

char* tk - string que armazenará o token (char*)
TokenType tok - tipo de token (TokenType)
bool imprimir - flag para imprimir todas as ocorrências de tokens (bool true) ou apenas as de erro (bool false)

A função é dirigida por tabela. Ela lê o próximo caractere do arquivo arqv_ptr e realiza transições de estado com a tabela estados.

prox_estado = estados[estado_atual][char_lido].

A função retorna EOF ao atingir o fim do arquivo ou 1 caso contrário.

*/
TokenType tok_atual = ERROR;
char tokenString_atual[100];

int tabledriven(char tk[100], TokenType tok, bool imprimir) {
    int estado = 0;
    char c = get_next_char();

    int i = 0;
    int ultimo_estado = 0;

    bool flag_save = true;
    int flag_inicial = 0;
    while (estado != estado_ACEITA && c != EOF) {
        // printf("Estado: %d, char: %c (%d)\n", estado, c, c);  // debug
        estado = estados[estado][c - 32];
        // printf("novo estado: %d\n", estado);  // debug
        switch (estado) {
            case estado_INICIAL:
                c = get_next_char();
                break;
            case estado_ID:
                tk[i++] = c;
                tk[i] = '\0';
                tok = ID;
                c = get_next_char();
                break;
            case estado_NUM:
                tk[i++] = c;
                tk[i] = '\0';
                tok = NUM;
                c = get_next_char();

                break;
            case estado_ATTR:
                tk[i++] = c;
                tk[i] = '\0';
                if (c = get_next_char() == '=') {
                    tk[i++] = c;
                    tk[i] = '\0';
                    tok = EQ;
                } else {
                    unget_char();
                    tok = ASSIGN;
                }
                break;
            case estado_COMENTARIO:  // talvez não seja necessário
                if ((c = get_next_char()) == '*') {
                    estado = estado_COMENTARIO;
                    while (true) {
                        char temp;
                        if ((temp = get_next_char()) == '*') {
                            if ((get_next_char()) == '/') {
                                estado = estado_INICIAL;
                                break;
                            }
                        } else if (temp == EOF) {
                            printf("(4)Erro léxico. Comentário não fecha. (Linha %d)", buffer->linha + 1);
                        }
                    }
                } else {
                    unget_char();
                    tok = OVER;
                    estado = estado_ACEITA;
                }
                break;
            case estado_ACEITA:
                // printf("estado aceita %d\n", tok);
                switch (tok) {
                    case ID:
                        tok = busca_reservadas(tk);
                        // printf("ID: %s, tok: %d\n", tk, tok);  //
                        break;
                    case NUM:
                        // printf("NUM: %s, tok: %d\n", tk, tok);  //
                        break;
                    case EQ:
                        // printf("EQ: %s, tok: %d\n", tk, tok);  //
                        break;
                    case ASSIGN:
                        // printf("ASSIGN: %s, tok: %d\n", tk, tok);  //
                        break;
                    case ERROR:
                        if (flag_inicial == 1) {
                            printtoken(tk, tok);
                            break;
                        }
                        if (c == '>') {
                            tok = GT;
                            tk[i++] = c;
                            tk[i] = '\0';
                            if (get_next_char() == '=') {
                                tk[i++] = c;
                                tk[i] = '\0';
                                tok = GTE;
                            } else {
                                unget_char();
                            }
                        }
                        if (c == '<') {
                            tok = LT;
                            tk[i++] = c;
                            tk[i] = '\0';
                            if (get_next_char() == '=') {
                                tk[i++] = c;
                                tk[i] = '\0';
                                tok = LTE;
                            } else {
                                unget_char();
                            }
                            break;
                        }
                        if (c == '[') {
                            tok = LBRACKET;
                            tk[i++] = c;
                            tk[i] = '\0';
                            break;
                        }
                        switch (c) {
                            case '-':
                                tok = MINUS;
                                break;
                            case '+':
                                tok = PLUS;
                                break;
                            case '*':
                                tok = TIMES;
                                break;
                            case '/':
                                tok = OVER;
                                break;
                            case ';':
                                tok = SEMI;
                                break;
                            case ',':
                                tok = COMMA;
                                break;
                            case '(':
                                tok = LPAREN;
                                break;
                            case ')':
                                tok = RPAREN;
                                break;
                            case '[':
                                tok = LBRACKET;
                                break;
                            case ']':
                                tok = RBRACKET;
                                break;
                            case '{':
                                tok = LBRACE;
                                break;
                            case '}':
                                tok = RBRACE;
                                break;
                            case '=':
                                tok = EQ;
                                if (get_next_char() == '=') {
                                    tk[i++] = c;
                                    tk[i] = '\0';
                                    tok = EQ;
                                } else {
                                    unget_char();
                                }
                                break;
                            default:
                                // printf("(2)Erro lexico: %s, Linha: %d\n", tk, buffer->linha + 1);
                                tok = ERROR;
                                flag_inicial = 1;
                                break;
                        }
                        tk[i++] = c;
                        tk[i] = '\0';
                        // printf("%s (%d) está em estado aceita\n", tk, tok);
                        break;

                    default:
                        // printf("(1)Erro lexico: %s, Linha: %d\n", tk, buffer->linha + 1);
                        tok = ERROR;
                        flag_inicial = 1;
                        break;
                }

                // printf("imprimindo: %s %d \n", tk, tok);  // debug
                if (tok == ID) {
                    tok = busca_reservadas(tk);
                }
                if (imprimir)
                    printtoken(tk, tok);

                return tok;
                break;
            default:
                if (estado == 10 || estado == 7) {
                    // printf("estado 10 ou 7\n");
                    unget_char();
                    estado = estado_ACEITA;
                    break;
                } else if (estado == 13) {
                    // come o char que acabou de pegar
                    //  printf("estado 13\n");
                } else {
                    c = get_next_char();
                }

                // printf("(3)Erro léxico: %s, Linha: %d\n", tk, buffer->linha + 1);
                break;
        }
    }

    if (estado == estado_ACEITA) {
        if (tok == ID) {
            tok = busca_reservadas(tk);
        }
        if (imprimir)
            printtoken(tk, tok);
        return tok;
    }
    return 0;
}

// /*
// get_next_token() - retorna o próximo token do arquivo. (case aninhado, funcionando mas não estava usando a tabela de transições)
// */
// TokenType get_next_token(bool imprimir) {
//     // printf("iniciando token\n");
//     int loop_flag;
//     int estado_idx = 0;
//     TokenType tok;
//     Estado estado = estado_INICIAL;
//     char tk[256];

//     int flagtk = TRUE;

//     while (estado != estado_ACEITA) {
//         char c = get_next_char();
//         // printf("char: %c\n", c);
//         switch (estado) {
//             case estado_INICIAL:
//                 if (c == ' ' || c == '\t' || c == '\n') {
//                     flagtk = FALSE;
//                 } else if (digito(c)) {
//                     estado = estado_NUM;
//                     flagtk = TRUE;
//                 } else if (letra(c)) {
//                     estado = estado_ID;
//                     flagtk = TRUE;
//                     // printf("começou um ID\n");
//                 } else if (c == '=') {
//                     estado = estado_ATTR;
//                     flagtk = TRUE;

//                 } else {
//                     estado = estado_ACEITA;
//                     switch (c) {
//                         case EOF:
//                             flagtk = FALSE;
//                             tok = END_OF_FILE;
//                             break;
//                         case '=':
//                             tok = EQ;
//                             flagtk = TRUE;
//                             break;
//                         case '+':
//                             flagtk = TRUE;
//                             tok = PLUS;
//                             break;
//                         case '-':
//                             flagtk = TRUE;
//                             tok = MINUS;
//                             break;
//                         case '*':
//                             flagtk = TRUE;
//                             tok = TIMES;
//                             break;
//                         case '/':
//                             tok = OVER;
//                             if ((c = get_next_char()) == '*') {
//                                 estado = estado_COMENTARIO;
//                                 flagtk = FALSE;
//                             } else
//                                 flagtk = TRUE;
//                             unget_char();
//                             break;
//                         case '<':
//                             flagtk = TRUE;
//                             tok = LT;
//                             break;
//                         case '>':
//                             flagtk = TRUE;
//                             tok = GT;
//                             break;
//                         case ';':
//                             flagtk = TRUE;
//                             tok = SEMI;
//                             break;
//                         case ',':
//                             flagtk = TRUE;
//                             tok = COMMA;
//                             break;
//                         case '(':
//                             flagtk = TRUE;
//                             tok = LPAREN;
//                             break;
//                         case ')':
//                             flagtk = TRUE;
//                             tok = RPAREN;
//                             break;
//                         case '[':
//                             flagtk = TRUE;
//                             tok = LBRACKET;
//                             break;
//                         case ']':
//                             flagtk = TRUE;
//                             tok = RBRACKET;
//                             break;
//                         case '{':
//                             flagtk = TRUE;
//                             tok = LBRACE;
//                             break;
//                         case '}':
//                             flagtk = TRUE;
//                             tok = RBRACE;
//                             break;
//                         default:
//                             flagtk = TRUE;
//                             tok = ERROR;
//                             break;
//                     }
//                 }
//                 break;
//             case estado_COMENTARIO:
//                 loop_flag = TRUE;
//                 while (loop_flag) {
//                     c = get_next_char();
//                     if (c == '*') {
//                         if ((c = get_next_char()) == '/') {
//                             loop_flag = FALSE;
//                             estado = estado_INICIAL;
//                         }
//                     }
//                 }
//                 break;
//             case estado_ATTR:
//                 if ((c = get_next_char()) == '=') {
//                     tok = EQ;
//                     flagtk = TRUE;
//                 } else {
//                     tok = ASSIGN;
//                     unget_char();
//                     flagtk = FALSE;
//                 }
//                 estado = estado_ACEITA;
//                 break;
//             case estado_NUM:
//                 if (!digito(c)) {
//                     unget_char();
//                     flagtk = FALSE;
//                     estado = estado_ACEITA;
//                     tok = NUM;
//                 }
//                 break;
//             case estado_ID:
//                 // printf("letra %c é letra? %d\n", c, !letra(c));
//                 if (!letra(c)) {
//                     // printf("retornando um char\n");
//                     unget_char();
//                     estado = estado_ACEITA;
//                     flagtk = FALSE;
//                     tok = ID;
//                 }
//                 break;
//             case estado_ACEITA:
//                 break;
//             default:
//                 printf("Erro léxico: %s, Linha: %d\n", tk, buffer->linha);
//                 break;
//         }
//         if (flagtk == TRUE) {
//             // printf("escrevendo %c\n", c);
//             tk[estado_idx++] = c;
//         }
//         if (estado == estado_ACEITA) {
//             tk[estado_idx] = '\0';
//             if (tok == ID) {
//                 // printf("!!ID, %s\n", tk);
//                 tok = busca_reservadas(tk);
//             }
//         }
//     }
//     if (imprimir) {
//         printtoken(tk, tok);
//     } else {
//         if (tok == ERROR) {
//             printf("Erro lexico: %s, Linha: %d\n", tk, buffer->linha + 1);
//         }
//     }

//     return tok;
// }

int ajusta_token(TokenType token) {
    switch (token) {
        case NUM:
            return t_NUM;
            break;
        case ID:
            return t_ID;
            break;
        case IF:
            return t_IF;
            break;
        case ELSE:
            return t_ELSE;
            break;
        case INT:
            return t_INT;
            break;
        case RETURN:
            return t_RETURN;
            break;
        case VOID:
            return t_VOID;
            break;
        case WHILE:
            return t_WHILE;
            break;
        case PLUS:
            return '+';
            break;
        case MINUS:
            return '-';
            break;
        case TIMES:
            return '*';
            break;
        case OVER:
            return '/';
            break;
        case LT:
            return t_LT;
            break;
        case LTE:
            return t_LTE;
            break;
        case GT:
            return t_GT;
            break;
        case GTE:
            return t_GTE;
            break;
        case EQ:
            return t_EQ;
            break;
        case NEQ:
            return t_NEQ;
            break;
        case ASSIGN:
            return '=';
            break;
        case SEMI:
            return ';';
            break;
        case COMMA:
            return ',';
            break;
        case LPAREN:
            return '(';
            break;
        case RPAREN:
            return ')';
            break;
        case LBRACKET:
            return '[';
            break;
        case RBRACKET:
            return ']';
            break;
        case LBRACE:
            return '{';
            break;
        case RBRACE:
            return '}';
            break;

        case END_OF_FILE:
            return 0;
            break;

        default:
            break;
    }
}