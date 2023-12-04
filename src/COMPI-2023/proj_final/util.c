#include "util.h"

#include "globals.h"

TreeNode *newStmtNode(StmtKind kind) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;

    if (t == NULL) {
        printf("Falta de memória na linha %d\n", buffer->linha);
    } else {
        for (i = 0; i < MAXCHILDREN; i++) {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = StmtK;
        t->kind.stmt = kind;
        t->lineno = buffer->linha;
    }
    return t;
}

TreeNode *newExpNode(ExpKind kind) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;

    if (t == NULL) {
        printf("Falta de memória na linha %d\n", buffer->linha);
    } else {
        for (i = 0; i < MAXCHILDREN; i++) {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = ExpK;
        t->kind.exp = kind;
        t->lineno = buffer->linha;
        t->type = Void;
    }
    return t;
}

TreeNode *newDeclNode(DeclKind kind) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;

    if (t == NULL) {
        printf("Falta de memória na linha %d\n", buffer->linha);
    } else {
        for (i = 0; i < MAXCHILDREN; i++) {
            t->child[i] = NULL;
        }
        t->sibling = NULL;
        t->nodekind = Decl;
        t->kind.decl = kind;
        t->lineno = buffer->linha;
    }
    return t;
}

char *copyString(char *s) {
    char *t = malloc(strlen(s) + 1);
    strcpy(t, s);
    return t;
}

void printTree(TreeNode *tree) {
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        printf(" ");
    }
    while (tree != NULL) {
        if (tree->nodekind == StmtK) {
            switch (tree->kind.stmt) {
                case IfK:
                    printf("If\n");
                    break;
                case RepeatK:
                    printf("Repeat\n");
                    break;
                case AssignK:
                    printf("Assign to: %s\n", tree->attr.name);
                    break;
                case ReturnK:
                    printf("Return\n");
                    break;
                case CompoundK:
                    printf("Compound Statement\n");
                    break;
                default:
                    printf("Unknown StmtNode kind\n");
                    break;
            }
        } else if (tree->nodekind == ExpK) {
            switch (tree->kind.exp) {
                case OpK:
                    printf("Op: ");
                    printToken(tree->attr.op, "\0");
                    break;
                case ConstK:
                    printf("Const: %d\n", tree->attr.val);
                    break;
                case IdK:
                    printf("Id: %s\n", tree->attr.name);
                    break;
                case TypeK:
                    printf("Type: ");
                    printToken(tree->attr.type, "\0");
                    break;
                case ArrIdK:
                    printf("ArrId: %s\n", tree->attr.name);
                    break;
                case CallK:
                    printf("Call: %s\n", tree->attr.name);
                    break;
                case CalcK:
                    printf("Calc: ");
                    printToken(tree->attr.op, "\0");
                    break;
                default:
                    printf("Unknown ExpNode kind\n");
                    break;
            }
        } else if (tree->nodekind == Decl) {
            switch (tree->kind.decl) {
                case VarK:
                    printf("Var: %s\n", tree->attr.name);
                    break;
                case FunK:
                    printf("Fun: %s\n", tree->attr.name);
                    break;
                case ParamK:
                    printf("Param: %s\n", tree->attr.name);
                    break;
                case ArrParamK:
                    printf("ArrParam: %s\n", tree->attr.name);
                    break;
                default:
                    printf("Unknown DeclNode kind\n");
                    break;
            }
        }
    }
}