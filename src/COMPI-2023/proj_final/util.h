#ifndef _UTIL_H
#define _UTIL_H
#include "globals.h"
#include "lex.h"

TreeNode* newStmtNode(StmtKind kind);

TreeNode* newExpNode(ExpKind kind);

TreeNode* newDeclNode(DeclKind kind);

char* copyString(char* s);

void printTree(TreeNode* tree);

#endif