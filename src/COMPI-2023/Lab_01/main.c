#include<stdio.h>
#include<stdlib.h>

#include "funcs.h"
#include "funcs.c"

int main(int argc, char** argv){
	if(argc!=3){
		printf("Quantidade de parâmetros errada. Execute da seguinte forma: \n./main <nome do arquivo> <tamanho do buffer>\n");
		return 0;
	}else{
		printf("Executando...\n");
	}

	int tam = atoi(argv[2]);
	FILE *arqv_ptr;
	arqv_ptr = fopen(argv[1], "r");

	if(arqv_ptr == 0){
		printf("Falha ao abrir o arquivo. Verifique se o nome foi passado corretamente.\n");
		return 0;
	}else{
		printf("Arquivo aberto com sucesso.\n");
	}

	allocate_buffer(tam+1);

	replace_print(arqv_ptr);
	deallocate_buffer();

	fclose(arqv_ptr);

	return 0;
}

	