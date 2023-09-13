// #include<stdio.h>
#include "funcs.h"

buffer_texto *buf;

void allocate_buffer(int tamanho) {
    buf = (buffer_texto *)malloc(sizeof(buffer_texto));

    buf->buf = (char *)malloc(tamanho * sizeof(char));
    buf->max_tam = tamanho;
    buf->tam = tamanho;
    buf->pos = 0;
    buf->linha = 0;
}

char get_next_char(FILE *arqv_ptr) {
    // printf("Buf pos: %d, buf tam: %d", buf->pos, buf->tam);

    if (buf->pos == 0 || buf->pos == buf->tam) {
        if (fgets(buf->buf, buf->max_tam, arqv_ptr) != NULL) {
            // puts(buf->buf);
            // printf("Buf: %s (tam: %d)\n", buf->buf, strlen(buf->buf));
            if (strlen(buf->buf) < buf->max_tam) {
                buf->tam = strlen(buf->buf);
            } else {
                buf->tam = buf->max_tam;
            }
            buf->pos = 0;
            // printf("\tbuf max tam: %d, buf tam: %d\n", buf->max_tam, buf->tam);
        } else {
            flag_full = 1;
        }
    }
    char next_c = buf->buf[buf->pos];
    buf->pos = buf->pos + 1;
    if (next_c == '\n') {
        buf->linha++;
    }
    // printf(" (buf pos: %d)\n", buf->pos);
    // printf("(.%c)", buf->buf[buf->pos - 1]);
    return next_c;
}

void deallocate_buffer() {
    free(buf->buf);
    free(buf);
}
