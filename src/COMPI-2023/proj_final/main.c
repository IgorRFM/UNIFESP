
#include <locale.h>

#include "tabela.c"
/* ----- Analisador Léxico ----- */
/*
Arquivo com as declarações e procedimentos para o funcionamento da tabela hash para palavras reservadas.
Com a tabela hash é possível fazer uma busca com uma otimização de O(1). Ou, no cenário de pior caso O(n) - o que nunca é alcançado neste caso, uma vez que a tabela tem garantidamente várias posições não vazias.

hash_key: Função que recebe uma string e retorna um inteiro que é a chave hash para a tabela. A chave é calculada somando-se o valor ASCII de cada caractere da string e elevando ao quadrado, somado a um offset ded 4205.

hte: estrutura de dados que representa uma entrada. Ela contém a chave, o  tipo de token e um ponteiro para a próxima entrada, no caso de hash collision.

ht: estrutura de dados que representa a tabela hash. Ela contém um vetor de ponteiros para entradas. O tamanho do vetor é um número primo, para evitar colisões. O tamanho é definido na inicialização da tabela.

insert: função que recebe uma tabela hash, uma chave e um tipo de token. Ela insere na tabela uma nova entrada com a chave e o tipo de token passados. A função calcula o índice da tabela a partir da chave e insere no início da lista encadeada de entradas.

find: função que recebe uma tabela hash e uma chave. Ela retorna o tipo de token associado à chave passada. A função calcula o índice da tabela a partir da chave e percorre a lista encadeada de entradas até encontrar a chave. Caso não encontre, retorna ERROR.

print_hash_table: função que recebe uma tabela hash e imprime todas as entradas da tabela. É usada para debug.

inicializa_hash: função que inicializa a tabela hash. Ela aloca memória para a tabela e para o vetor de entradas. Em seguida, inicializa todas as entradas com NULL e insere todas as palavras reservadas na tabela.
*/
#include "hash.c"
#include "lex.c"
/*
Arquivo com as declarações e procedimentos para o funcionamento do buffer de leitura do arquivo de entrada.
*/
#include "funcs.c"
int error = FALSE;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Portuguese");

    if (argc != 2) {
        printf("Quantidade de parâmetros errada. Execute da seguinte forma: \n %s <nome do arquivo>\n", argv[0]);
        exit(1);
    } else {
        printf("Executando sob o Arquivo: %s\n", argv[1]);
    }

    arqv_ptr = fopen(argv[1], "r");

    if (arqv_ptr == 0) {
        printf("Falha ao abrir o arquivo. Verifique se o nome foi passado corretamente.\n");
        return 0;
    } else {
        printf("Arquivo aberto com sucesso.\n");
    }

    allocate_buffer();
    inicializa_hash();

    cria_tabela();

    char tk[100];
    TokenType tok = ERROR;
    printf("lendo...\n");
    while ((tabledriven(tk, tok, true)) != END_OF_FILE) {
        }

    // teste_scan();
    // teste_token();

    // while (get_next_token(false) != END_OF_FILE) {
    // }

    // syntaxTree = parse();
    // if (TraceParse && !error) {
    //     fprintf(listing, "\nSyntax tree:\n");
    //     printTree(syntaxTree);
    // }

    // fclose(src);
    return 0;
}