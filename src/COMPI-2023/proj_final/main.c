/*------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE SÃO PAULO  */
/* INSTITUTO DE CIÊNCIA E TECNOLOGIA  */
/* CURSO DE CIÊNCIA DA COMPUTAÇÃO  */
/*  */
/* Trabalho de Compiladores  */
/* Professor: Luis Pereira */
/*  */
/* Aluno:  */
/* Igor Ribeiro Ferreira de Matos*/
/* RA: 140492 */
/*  */
/*  */
/*  */

/*

Algumas partes do código (principalmente a parte de análise sintática) foram baseadas no livro "Compiladores: Princípios e Práticas" de Kenneth C. Louden e na sua implementação no capítulo final.

A parte de análise semântica não foi implementada.

A parte de análise sintática foi parcialmente implementada: faltou tempo para conseguir conciliar a parte do Bison com o resto do código. Quando finalmente consegui, enfrentei inúmeros problemas de memórias (provavelmente na parte de alocação de memória para os nós da árvore sintática). Por isso, a parte de análise sintática está incompleta, pois eu estava "desmembrando" cada regra sintática com o intuito de descobrir potenciais falhas.

A parte de análise léxica foi implementada com sucesso.

O cóodigo consegue, com sucesso:
    [ V ] Alocar e utilizar buffers para leitura dos arquivos;
    [ V ] Fazer o scan char a char do arquivo, com o buffer criado.
    [ V ] Fazer a tokenização (análise léxica) e indicar todos os erros léxicos de uma  varredura.
    [ V ] Criar uma tabela de transições (extraída de uma tabela do excel, com todos os estados e símbolos de transição).
    [ V ] Fazer a tokenização com uma matriz de transição (a criada anteirormente)
    [ V ] Criar uma tabela hash de palavras reservadas e realizar uma busca hash melhor do que linear (Garantidamente, por conta das poucas palavras e poucas repetições de chaves, será realizado no máximo duas comparações de chaves).
    [ V ] Imprimir os tokens para o usuário (caso imprimir = TRUE) ou então apenas imprimir as mensagens de erro (imprimir = FALSE)
    [ V ] Converter o tipo de enumeradores utilizados na tokenização para os enumeradores esperados na parte de análise sintática.

*/

#include <locale.h>

/*
                <<<globals.h>>>

Arquivos com definições globais e constantes. que serão utilizadas em todo o programa.

Nela é possível encontrar:

tam_buffer: tamanho do buffer de leitura do arquivo de entrada.

arqv_ptr: ponteiro para o arquivo de entrada.

struct buffer_texto: estrutura de dados que representa o buffer de leitura do arquivo de entrada. Ela contém um vetor de caracteres, o tamanho do buffer, a posição do próximo caractere a ser lido e a linha atual do arquivo.

enum TokenType: enumeração que representa os tipos de tokens que podem ser encontrados no arquivo de entrada. Ela contém todos os tokens definidos na gramática. Implementação inspirada pelo capítulo final do livro "Compiladores: Princípios e Práticas" de Kenneth C. Louden.

MAXCHILDREN: quantidade máxima ded filhos que seria possível ter em uma árvore sintática. Para cada nó. Não é utilizada neste trabalho, por conta da falha na implementação.

enums NodeKind, StmtKind, ExpKind, DeclKind: enumerações que representam os tipos de nós que podem ser encontrados na árvore sintática. Não são utilizadas neste trabalho, por conta da falha na implementação. Padrão de nomenclatura visto no livor.

struct treeNode:  estrutura que representa o cada nó encontrada na árvore de análise sintática. Novamente, não implementada.
*/

#include "globals.h"

/*
                <<<funcs.c>>>
Arquivo com as declarações de procedimentos para o funcionamento do Bison, gerador de análise sintática. Derivado do arquivo <<<bison.y>>>.
*/
#include "bison.tab.c"

/*
                <<<hash.c>>>
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

/*
                <<<tabela.c>>>




*/

#include "tabela.c"
/*
                <<<lex.c>>>

Arquivo com declarações e procedimentos principais do analisador léxico.
Nele é possível encontrar:

printtoken: recebe uma string de token e um token do tipo TokenType (enum previamente declarado). Ela imprime o token e o tipo de token, caso imprimir = TRUE.

get_next_char: função que lê o próximo caractere do arquivo de entrada. Ela utiliza o buffer de leitura para ler o arquivo.

unget_next_char: função que retorna a posição do buffer de entrada em 1.

palavras_reservadas: estrutura de dados que representa uma palavra reservada. Ela contém a string da palavra reservada e o tipo de token associado.

busca_reservadas: busca na tabela hash se uma string "s" é uma palavra reservada. Caso seja, retorna o tipo de token associado. Caso contrário, retorna o token "ID".

Estado: definições de alguns estados relevantes do DFA da tabela de transição.

Tabledriven: Basicamente um get_token(), mas que utiliza uma tabela de trnasição para fazer a tokenização.

ajusta_token: faz a conversão dos tokens do tipo TokenType para o tipo de token esperado pelo Bison.
*/
#include "lex.c"

/*
                <<<funcs.c>>>

Arquivos com algumas funções auxiliares para o funcionamento do programa. Nele é possível encontrar os testes de execução de cada etapa do programa.
*/
#include "funcs.c"

int error = FALSE;

int main(int argc, char* argv[]) {
    printf("inciando...\n");
    setlocale(LC_ALL, "Portuguese");

    int modo = 0;
    bool imprimir = TRUE;

    if (argc != 2 && argc != 3) {
        printf("Quantidade de params. errada. Execute da seguinte forma: \n ./main <nome do arquivo> [modo]\nOnde [modo]:\n\t0-Execucao completa. \n\t1-Execucao do Scanner (leitura de chars). \n\t2-Execucao até a analise Lexica. \n\t3-Execucao ate a analise sintatica (incompleto). \n\t4-Execucao ate a analise semantica (Não feito). ");

        exit(1);
    } else if (argc == 2) {
        printf("Executando sob o Arquivo: %s\nModo (padrão): 0.", argv[1]);
    } else if (argc == 3) {
        modo = atoi(argv[2]);
        printf("Executando sob o Arquivo: %s\nModo : %d.", argv[1], modo);
    }

    arqv_ptr = fopen(argv[1], "r");

    if (arqv_ptr == 0) {
        printf("Falha ao abrir o arquivo. Verifique se o nome foi passado corretamente.\n");
        return 0;
    } else {
        printf("Arquivo aberto com sucesso.\n");
    }

    allocate_buffer(imprimir);
    inicializa_hash();

    cria_tabela(FALSE);  // tabela de transições, passe TRUE para imprimir a tabela (muito grande)
    print_hash_table(hash_table);

    if (modo == 0) {
        yyparse();  // implementado apenas até a análise sintática, parcialmente.
    } else if (modo == 1) {
        teste_scan(imprimir);  // scanner de chars
    } else if (modo == 2) {
        teste_token(imprimir);  // scanner de tokens (análise léxica)
    } else if (modo == 3) {
        yyparse();  // análise sintática
    } else if (modo == 4) {
        printf("Análise semântica não implementada.\n");  // análise semântica
    }

    fclose(arqv_ptr);
    return 0;
}