// #include "globals.h"

// static TokenType token;
// static char tokenString[100];

// static TreeNode* stmt_sequence(void);
// static TreeNode* statement(void);
// static TreeNode* if_stmt(void);
// static TreeNode* repeat_stmt(void);
// static TreeNode* assign_stmt(void);
// static TreeNode* read_stmt(void);
// static TreeNode* write_stmt(void);
// static TreeNode* exp(void);
// static TreeNode* simple_exp(void);
// static TreeNode* term(void);
// static TreeNode* factor(void);

// void syntaxError(char* message) {
//     printf("\n>>> Erro de sintaxe na linha %d: %s", buffer->linha + 1, message);
// }

// void casa(char tokenstr[100], TokenType tok) {
//     if (token == tok) {
//         tabledriven(tokenstr, token, FALSE);
//     } else {
//         syntaxError("Token inesperado -> ");
//         printtoken(tokenstr, tok);
//         printf("Esperado -> ");
//         printtoken(tokenString, token);
//         printf("\n");
//         exit(1);
//     }
// }

// TreeNode* stmt_sequence(void) {
//     TreeNode* t = statement();
//     TreeNode* p = t;
//     while ((token != SEMI) && (token != END_OF_FILE)) {
//         TreeNode* q;
//         casa("", SEMI);
//         q = statement();
//         if (q != NULL) {
//             if (t == NULL) {
//                 t = p = q;
//             } else {
//                 p->sibling = q;
//                 p = q;
//             }
//         }
//     }
//     return t;
// }

// TreeNode* statement(void) {
//     TreeNode* t = NULL;
//     switch (token) {
//         case IF:
//             t = if_stmt();
//             break;
//         case REPEAT:
//             t = repeat_stmt();
//             break;
//         case ID:
//             t = assign_stmt();
//             break;
//         case READ:
//             t = read_stmt();
//             break;
//         case WRITE:
//             t = write_stmt();
//             break;
//         default:
//             syntaxError("Comando inesperado -> ");
//             printtoken(tokenString, token);
//             token = getToken();
//             break;
//     }
//     return t;
// }

// TreeNode* if_stmt(void) {
//     TreeNode* t = newStmtNode(IfK);
//     casa("if", IF);
//     if (t != NULL) {
//         t->child[0] = exp();
//     }
//     casa("then", THEN);
//     if (t != NULL) {
//         t->child[1] = stmt_sequence();
//     }
//     if (token == ELSE) {
//         casa("else", ELSE);
//         if (t != NULL) {
//             t->child[2] = stmt_sequence();
//         }
//     }
//     casa("end", END);
//     return t;
// }

// TreeNode* repeat_stmt(void) {
//     TreeNode* t = newStmtNode(RepeatK);
//     casa("repeat", REPEAT);
//     if (t != NULL) {
//         t->child[0] = stmt_sequence();
//     }
//     casa("until", UNTIL);
//     if (t != NULL) {
//         t->child[1] = exp();
//     }
//     return t;
// }

// TreeNode* assign_stmt(void) {
//     TreeNode* t = newStmtNode(AssignK);
//     if ((t != NULL) && (token == ID)) {
//         t->attr.name = copyString(tokenString);
//     }
//     casa("", ID);
//     casa("", ASSIGN);
//     if (t != NULL) {
//         t->child[0] = exp();
//     }
//     return t;
// }

// TreeNode* read_stmt(void) {
//     TreeNode* t = newStmtNode(ReadK);
//     casa("read", READ);
//     if ((t != NULL) && (token == ID)) {
//         t->attr.name = copyString(tokenString);
//     }
//     casa("", ID);
//     return t;
// }

// TreeNode* write_stmt(void) {
//     TreeNode* t = newStmtNode(WriteK);
//     casa("write", WRITE);
//     if (t != NULL) {
//         t->child[0] = exp();
//     }
//     return t;
// }

// TreeNode* exp(void) {
//     TreeNode* t = simple_exp();
//     if ((token == LT) || (token == EQ)) {
//         TreeNode* p = newExpNode(OpK);
//         if (p != NULL) {
//             p->child[0] = t;
//             p->attr.op = token;
//             t = p;
//         }
//         casa("", token);
//         if (t != NULL) {
//             t->child[1] = simple_exp();
//         }
//     }
//     return t;
// }

// TreeNode* simple_exp(void) {
//     TreeNode* t = term();
//     while ((token == PLUS) || (token == MINUS)) {
//         TreeNode* p = newExpNode(OpK);
//         if (p != NULL) {
//             p->child[0] = t;
//             p->attr.op = token;
//             t = p;
//             casa("", token);
//             t->child[1] = term();
//         }
//     }
//     return t;
// }

// TreeNode* term(void) {
//     TreeNode* t = factor();
//     while ((token == TIMES) || (token == OVER)) {
//         TreeNode* p = newExpNode(OpK);
//         if (p != NULL) {
//             p->child[0] = t;
//             p->attr.op = token;
//             t = p;
//             casa("", token);
//             t->child[1] = factor();
//         }
//     }
//     return t;
// }

// TreeNode* factor(void) {
//     TreeNode* t = NULL;
//     switch (token) {
//         case LPAREN:
//             casa("(", LPAREN);
//             t = exp();
//             casa(")", RPAREN);
//             break;
//         case NUM:
//             t = newExpNode(ConstK);
//             if ((t != NULL) && (token == NUM)) {
//                 t->attr.val = atoi(tokenString);
//             }
//             casa("", NUM);
//             break;
//         case ID:
//             t = newExpNode(IdK);
//             if ((t != NULL) && (token == ID)) {
//                 t->attr.name = copyString(tokenString);
//             }
//             casa("", ID);
//             break;
//         default:
//             syntaxError("Token inesperado -> ");
//             printtoken(tokenString, token);
//             token = getToken();
//             break;
//     }
//     return t;
// }

// TreeNode* parse(void) {
//     TreeNode* t;
//     tabledriven(tokenString, token, FALSE);
//     t = stmt_sequence();
//     if (token != END_OF_FILE) {
//         syntaxError("Codigo terminou antes do esperado.\n");
//     }
//     return t;
// }
