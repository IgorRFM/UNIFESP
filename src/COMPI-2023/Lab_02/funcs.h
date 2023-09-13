// #include<stdio.h>

typedef struct tipobuffer {
    char *buf;
    int max_tam;
    int tam;
    int pos;  // pos do próximo char a ser lido.
    int linha;

} buffer_texto;

void allocate_buffer(int tamanho);
void replace_print(FILE *arqv_ptr);
void deallocate_buffer();
