#include <stdio.h>
#include <stdlib.h>

int flag_full = 0;
#include <string.h>

// #include "funcs.h"
/*Biblioteca de funções*/

#include "funcs.c"
/*Funções*/

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Quantidade de parâmetros errada. Execute da seguinte forma: \n./main <nome do arquivo>\n");
        exit(1);
    } else {
        printf("Executando...\n");
    }

    int tam = 7;
    FILE* arqv_ptr;
    arqv_ptr = fopen(argv[1], "r");

    if (arqv_ptr == 0) {
        printf("Falha ao abrir o arquivo. Verifique se o nome foi passado corretamente.\n");
        return 0;
    } else {
        printf("Arquivo aberto com sucesso.\n");
    }

    allocate_buffer(tam + 1);

    // replace_print(arqv_ptr);
    while (flag_full == 0) {
        char c = get_next_char(arqv_ptr);
        if (flag_full != 1) {
            printf("%c", c);
        }
    }

    deallocate_buffer();

    fclose(arqv_ptr);

    return 0;
}
