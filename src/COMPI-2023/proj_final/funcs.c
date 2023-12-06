#include "funcs.h"

#include "lex.h"

bool done = FALSE;

void allocate_buffer(bool imprimir) {
    buffer = (buffer_texto *)malloc(sizeof(buffer_texto));
    buffer->buf = (char *)malloc(tam_buffer * sizeof(char));
    buffer->tam = tam_buffer;
    buffer->pos = 0;
    buffer->linha = 0;

    if (imprimir)
        printf("Buffer alocado com sucesso.\n");
}

void teste_scan(bool imprimir) {
    if (done) {
        reinicia_arquivo(imprimir);
    }
    char c;
    printf("\n/---Comecando scan---/\n\n");
    while ((c = get_next_char()) != EOF) {
        printf("%c", c);
    }
    done = TRUE;
    printf("\n\n/---fim do scan---/\n");
}

void teste_token(bool imprimir) {
    if (done) {
        reinicia_arquivo(imprimir);
    }
    char tk[100];
    TokenType tok = ERROR;
    printf("\n/---Comecando tokenização---/\n\n");
    int temp;
    while ((tabledriven(tk, tok, imprimir)) != END_OF_FILE) {
    }  // análise léxica

    done = TRUE;
    printf("\n\n/---fim da tokenização---/\n\n");
}

void teste_sintatico(bool imprimir) {
    if (done) {
        reinicia_arquivo(imprimir);
    }
    printf("\n/---Comecando análise sintática---/\n\n");
    yyparse();  // análise sintática
    done = TRUE;
    printf("\n/---fim da análise sintática---/\n\n");
}

void reinicia_arquivo(bool imprimir) {
    fseek(arqv_ptr, 0, SEEK_SET);
    buffer->pos = 0;
    buffer->linha = 0;
    free(buffer->buf);
    allocate_buffer(imprimir);
    done = FALSE;
}