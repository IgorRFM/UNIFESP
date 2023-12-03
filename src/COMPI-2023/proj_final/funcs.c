#include "funcs.h"

#include "lex.h"

bool done = FALSE;
void reinicia_arquivo();
void allocate_buffer() {
    buffer = (buffer_texto *)malloc(sizeof(buffer_texto));

    buffer->buf = (char *)malloc(tam_buffer * sizeof(char));
    buffer->tam = tam_buffer;
    buffer->pos = 0;
    buffer->linha = 0;
    printf("Buffer alocado com sucesso.\n");
}

void teste_scan() {
    if (done) {
        reinicia_arquivo();
    }
    char c;
    printf("\n/---Comecando scan...\n\n");
    while ((c = get_next_char()) != EOF) {
        printf("%c", c);
    }
    done = TRUE;
    printf("\n/---fim do scan\n");
}

void teste_token() {
    if (done) {
        reinicia_arquivo();
    }
    char *tk;
    TokenType tok;
    printf("\n/---Comecando tokenização...\n\n");
    // while ((tok = get_next_token(true))) {
    // }
    done = TRUE;
    printf("\n/---fim da tokenização\n\n");
}

void reinicia_arquivo() {
    fseek(arqv_ptr, 0, SEEK_SET);
    buffer->pos = 0;
    buffer->linha = 0;
    free(buffer->buf);
    allocate_buffer();
    done = FALSE;
}