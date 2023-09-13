// #include<stdio.h>

typedef struct bufferr{
    char *buf;
    int tam;
} buffer_texto;

void allocate_buffer(int tamanho);
void repleace_print(FILE *arqv_ptr);
void deallocate_buffer();