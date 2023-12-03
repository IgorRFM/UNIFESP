

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef GLOBALS_H
#define GLOBALS_H
#include "globals.h"
#endif
#include "lex.h"

int hash_key(char* key) {
    // printf("(%s)Fazendo hash...\n", key);
    int hash = 4205;
    unsigned i;
    for (i = 0; i < strlen(key) - 1; i++) {
        hash += key[i] * key[i];
    }
    return hash;
}

typedef struct hte {
    char* key;
    TokenType tok;
    struct hte* prox;
} ht_entry;

typedef struct ht {
    ht_entry** entries;
} ht;

ht* hash_table;

void insert(ht* tabela, char* key, TokenType tok) {
    int indice = hash_key(key) % 7;

    ht_entry* new = malloc(sizeof(ht_entry));

    new->key = malloc(strlen(key) + 1);
    strcpy(new->key, key);
    new->tok = tok;

    new->prox = tabela->entries[indice];
    tabela->entries[indice] = new;
}

TokenType find(ht* tabela, char* key) {
    int indice = hash_key(key) % 7;
    ht_entry* entry = tabela->entries[indice];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->tok;
        }
        entry = entry->prox;
    }
    return ERROR;
}

void print_hash_table(ht* tabela) {
    int i;
    for (i = 0; i < 7; i++) {
        printf("%d: ", i);
        ht_entry* entry = tabela->entries[i];
        while (entry != NULL) {
            printf("%s ", entry->key);
            entry = entry->prox;
        }
        printf("\n");
    }
}

void inicializa_hash() {
    hash_table = (ht*)malloc(sizeof(ht));
    hash_table->entries = (ht_entry**)malloc(7 * sizeof(ht_entry*));
    memset(hash_table->entries, 0, 7 * sizeof(ht_entry*));

    insert(hash_table, "else", ELSE);
    insert(hash_table, "if", IF);
    insert(hash_table, "int", INT);
    insert(hash_table, "return", RETURN);
    insert(hash_table, "void", VOID);
    insert(hash_table, "while", WHILE);
}