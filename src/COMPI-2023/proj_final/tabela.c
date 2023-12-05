#include <stdio.h>

int estados[14][96];

void cria_tabela() {
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
            // printf("%c ", c);
            if (c != 9) {
                d = (d * 10) + (c - 48);
            } else {  // NÃO DIGITO
                total += d;
                d = 0;
                estados[i][j] = total;
                j++;
                // if (i == 0) {
                //     printf("total: %d, (indo do estado 0 para o %d ao ler %c)\n", total, total, j + 31);
                // }
                total = 0;
            }
            // printf("inserindo %d em (%d,%d)\n", c - 48, i, j);
            c = fgetc(tabela);
        }
        // printf("\n");
        c = fgetc(tabela);
        i++;
    }

    // printf("Printando tabela (ex: %d):\n", estados[0][0]);

    // for (i = 4; i < 5; i++) {
    //     for (j = 0; j < 95; j++) {
    //         printf("(%d,%d) %d \n", i, j, estados[i][j]);
    //     }
    //     printf("\n");
    // }
}