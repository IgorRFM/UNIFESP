
#include <stdbool.h>
#include <stdio.h>

int estados[14][96];

void cria_tabela(bool imprimir) {
    printf("Criando tabela...\n");
    char* filename = "transicoes.tsv";
    FILE* tabela = fopen(filename, "r");

    char c;
    c = fgetc(tabela);
    int i = 0, j = 0;
    int d = 0, total = 0;
    while (c != EOF) {
        j = 0;
        d = 0;
        total = 0;
        while (c != '\n' && c != EOF) {
            if (c != 9) {
                d = (d * 10) + (c - 48);
            } else {  // NÃO DIGITO
                total += d;
                d = 0;
                estados[i][j] = total;
                j++;

                total = 0;
            }
            c = fgetc(tabela);
        }
        c = fgetc(tabela);
        i++;
    }

    if (imprimir) {
        printf("Printando tabela:\n");

        for (i = 0; i < 13; i++) {
            for (j = 0; j < 95; j++) {
                printf("%d ,", estados[i][j]);
            }
            printf("\n");
        }
    }
}