#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1010000010
char *Permutation(char *chave_K, int P[], int tam) {
    char *temp;
    temp = (char *)malloc(sizeof(char) * tam);
    int i;
    for (i = 0; i < tam; i++)
        temp[i] = chave_K[P[i] - 1];
    return temp;
}

void separacao(char *chave_K, char *separationEsq, char *separationDir, int tam) {
    int i;
    int j = 0;
    for (i = 0; i < tam; i++)
        separationEsq[i] = chave_K[i];

    for (i = tam; i < (tam * 2); i++) {
        separationDir[j] = chave_K[i];
        j++;
    }
}

void juncao(char *LS_, char *separationEsq, char *separationDir, int tam) {
    int i;
    int j = 0;
    for (i = 0; i < tam; i++)
        LS_[i] = separationEsq[i];

    for (i = tam; i < (tam * 2); i++) {
        LS_[i] = separationDir[j];
        j++;
    }
}

void rotacaoEsq(char *separation, int tam) {
    char temp = separation[0];
    int i;
    for (i = 0; i < tam; i++)
        separation[i] = separation[i + 1];
    separation[i] = temp;
}

char *getXorada(char *extendedIPDir, char K[], int tam) {
    int i;
    char *temp;
    temp = (char *)malloc(sizeof(char) * tam);
    for (i = 0; i < tam; i++) {
        if (extendedIPDir[i] == '1' && K[i] == '1')
            temp[i] = '0';
        else if (extendedIPDir[i] == '0' && K[i] == '0')
            temp[i] = '0';
        else
            temp[i] = '1';
    }
    return temp;
}

void getSubKeys(char *chave_K, char K1[], char K2[]) {
    char *separationEsq;
    char *separationDir;
    char *LS_;

    separationEsq = (char *)malloc(sizeof(char) * 5);
    separationDir = (char *)malloc(sizeof(char) * 5);
    LS_ = (char *)malloc(sizeof(char) * 10);

    // printf("=============K1=================\n");
    int P10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    chave_K = Permutation(chave_K, P10, 10);
    // printf("PERMUTOU %s\n", chave_K);
    separacao(chave_K, separationEsq, separationDir, 5);
    // printf("SEPAROU %s | %s\n", separationEsq, separationDir);

    // Gerando K1
    int P8[] = {6, 3, 7, 4, 8, 5, 10, 9};
    rotacaoEsq(separationEsq, 4);
    rotacaoEsq(separationDir, 4);
    // printf("ROTACIONOU %s | %s\n", separationEsq, separationDir);

    juncao(LS_, separationEsq, separationDir, 5);
    // printf("JUNTOU %s\n",LS_);
    strcpy(K1, Permutation(LS_, P8, 8));
    // K1 = Permutation(LS_, P8, 8);
    // printf("PERMUTOU %s\n",K1);

    // printf("=============K2=================\n");

    // Gerando K2
    separacao(LS_, separationEsq, separationDir, 5);
    // printf("SEPAROU %s | %s\n", separationEsq, separationDir);
    rotacaoEsq(separationEsq, 4);
    rotacaoEsq(separationEsq, 4);
    rotacaoEsq(separationDir, 4);
    rotacaoEsq(separationDir, 4);
    // printf("ROTACIONOU %s | %s\n", separationEsq, separationDir);
    juncao(LS_, separationEsq, separationDir, 5);
    // printf("JUNTOU %s\n",LS_);
    strcpy(K2, Permutation(LS_, P8, 8));
    // K2 = Permutation(LS_, P8, 8);
    // printf("PERMUTOU %s\n",K2);
}

void reverteString(char *S_bits) {
    char temp[1];
    temp[0] = S_bits[0];
    S_bits[0] = S_bits[1];
    S_bits[1] = temp[0];

    // printf("STRING REVERTIDA -> %s\n", S_bits);
}

char *getResult(char *seq_bits, char K[], int qualK) {
    char *separationEsq, *separationDir;
    separationEsq = (char *)malloc(sizeof(char) * 4);
    separationDir = (char *)malloc(sizeof(char) * 4);

    char *S0, *S1;
    S0 = (char *)malloc(sizeof(char) * 4);
    S1 = (char *)malloc(sizeof(char) * 4);

    char *S0_03, *S0_12, *S1_03, *S1_12;
    S0_03 = (char *)malloc(sizeof(char) * 2);
    S0_12 = (char *)malloc(sizeof(char) * 2);
    S1_03 = (char *)malloc(sizeof(char) * 2);
    S1_12 = (char *)malloc(sizeof(char) * 2);

    char *S0_2bits, *S1_2bits;
    S0_2bits = (char *)malloc(sizeof(char) * 2);
    S1_2bits = (char *)malloc(sizeof(char) * 2);

    char *extendedIPDir;
    extendedIPDir = (char *)malloc(sizeof(char) * 8);

    char *ipXorado, *ip4Xorado;
    ipXorado = (char *)malloc(sizeof(char) * 8);
    ip4Xorado = (char *)malloc(sizeof(char) * 4);

    char *permutP4;
    permutP4 = (char *)malloc(sizeof(char) * 4);

    char *resultado;
    resultado = (char *)malloc(sizeof(char) * 8);

    if (qualK == 1) {
        // Permutando
        int IP[] = {2, 6, 3, 1, 4, 8, 5, 7};
        seq_bits = Permutation(seq_bits, IP, 8);
        // printf("IP permutado -> %s\n", seq_bits);
    }

    separacao(seq_bits, separationEsq, separationDir, 4);

    // Permutando
    int EP[] = {4, 1, 2, 3, 2, 3, 4, 1};
    extendedIPDir = Permutation(separationDir, EP, 8);
    // printf("EP permutado -> %s\n", extendedIPDir);

    // Xorando
    ipXorado = getXorada(extendedIPDir, K, 8);
    // printf("EP xorado com K -> %s\n",ipXorado);
    // criando S0 e S1
    separacao(ipXorado, S0, S1, 4);
    // printf("Separou\nS0 -> %s\nS1 -> %s\n", S0, S1);

    /*
    Agora precisamos utilizar essas matrizes como referencia:
    S0 = [1 0 3 2]
         [3 2 1 0]
         [0 2 1 3]
         [3 1 3 2]

    S1 = [0 1 2 3]
         [2 0 1 3]
         [3 0 1 0]
         [2 1 0 3]
    */
    int S0_Matriz[4][4] = {
        {1, 0, 3, 2},
        {3, 2, 1, 0},
        {0, 2, 1, 3},
        {3, 1, 3, 2}};

    int S1_Matriz[4][4] = {
        {0, 1, 2, 3},
        {2, 0, 1, 3},
        {3, 0, 1, 0},
        {2, 1, 0, 3}};
    /*
    Consideramos pegar a primeira e ultimo valor de S0 (vindo da separacao)
    [0,3] -> pegamos o decimal dessa combinação (0 à 3)

    Pegamos entao os do meio de S0 ( vindo da separação)
    [1,2] -> pegamos o decimal dessa combinação
    */

    S0_03[0] = S0[0];
    S0_03[1] = S0[3];
    S0_12[0] = S0[1];
    S0_12[1] = S0[2];
    unsigned long S0_int03;
    unsigned long S0_int12;
    S0_int03 = strtoul(S0_03, NULL, 2);
    S0_int12 = strtoul(S0_12, NULL, 2);
    // printf("S0 inteiros\n S0_03 -> %lu\nS0_12 -> %lu\n", S0_int03, S0_int12);

    S1_03[0] = S1[0];
    S1_03[1] = S1[3];
    S1_12[0] = S1[1];
    S1_12[1] = S1[2];
    unsigned long S1_int03;
    unsigned long S1_int12;
    S1_int03 = strtoul(S1_03, NULL, 2);
    S1_int12 = strtoul(S1_12, NULL, 2);
    // printf("S1 inteiros\n S1_03 -> %lu\nS1_12 -> %lu\n", S1_int03, S1_int12);

    /*
    Os decimais pegos vão se tornar LINHA e COLUNA da matriz em questão
    que referenciam um inteiro decimal, pegamos então esse inteiro e pegamos a sua versão
    em binário que será o nosso vetor de 2 posições que se tornará parte do P4
    ( faz o mesmo processo para S1)
    */

    S0_int03 = S0_Matriz[S0_int03][S0_int12];
    S1_int03 = S1_Matriz[S1_int03][S1_int12];
    // printf("Valores pegos da matriz\nS0 -> %lu\n S1 -> %lu\n", S0_int03, S1_int03);

    // transformando pra binario
    if (S0_int03 == 0) {
        S0_2bits[0] = '0';
        S0_2bits[1] = '0';
    } else {
        int posicao = 0;
        do {
            S0_2bits[posicao++] = S0_int03 % 2 + '0';
            S0_int03 /= 2;
        } while (S0_int03 >= 0 && posicao < 2);
    }

    if (S1_int03 == 0) {
        S1_2bits[0] = '0';
        S1_2bits[1] = '0';
    } else {
        int posicao = 0;
        do {
            S1_2bits[posicao++] = S1_int03 % 2 + '0';
            S1_int03 /= 2;
        } while (S1_int03 >= 0 && posicao < 2);
    }

    // printf("S0_2bits -> %s\n", S0_2bits);
    // printf("S1_2bits -> %s\n", S1_2bits);
    reverteString(S0_2bits);
    reverteString(S1_2bits);

    // printf("Strings Revertidas\nS0 -> %s\nS1 -> %s\n", S0_2bits, S1_2bits);

    // Montando e permutando P4
    int P4[] = {2, 4, 3, 1};
    juncao(permutP4, S0_2bits, S1_2bits, 2);
    permutP4 = Permutation(permutP4, P4, 4);
    // printf("Permutacao P4 -> %s\n", permutP4);

    // Xorando P4 com a esquerdinha original
    ip4Xorado = getXorada(permutP4, separationEsq, 4);
    // printf("IP4 xorado -> %s\n", ip4Xorado);

    // Juntando com a direitinha original, só que invertendo
    if (qualK == 1)
        juncao(resultado, separationDir, ip4Xorado, 4);
    else
        juncao(resultado, ip4Xorado, separationDir, 4);

    // printf("Junção -> %s\n", resultado);

    return resultado;
}

void dcript(unsigned char chave_K[], unsigned char seq_bits[], unsigned char buffer[]) {
    int IP1[] = {4, 1, 3, 5, 7, 2, 8, 6};

    char *K1;
    char *K2;
    char retorno[8];
    unsigned char *resultado;
    resultado = (unsigned char *)malloc(sizeof(unsigned char) * 8);
    char output[8];

    K1 = (char *)malloc(sizeof(char) * 8);
    K2 = (char *)malloc(sizeof(char) * 8);

    // printf("\nMSG CRIPTO LADO .C -> %s\n", seq_bits);
    getSubKeys(chave_K, K1, K2);
    resultado = getResult(seq_bits, K2, 1);
    resultado = getResult(resultado, K1, 2);
    resultado = Permutation(resultado, IP1, 8);
    strcpy(buffer, resultado);
}

char *cript(unsigned char chave_K[], unsigned char seq_bits[], unsigned char buffer[]) {
    int IP1[] = {4, 1, 3, 5, 7, 2, 8, 6};

    char *K1;
    char *K2;
    char retorno[8];
    unsigned char *resultado;
    resultado = (unsigned char *)malloc(sizeof(unsigned char) * 8);
    char output[8];

    K1 = (char *)malloc(sizeof(char) * 8);
    K2 = (char *)malloc(sizeof(char) * 8);

    getSubKeys(chave_K, K1, K2);
    resultado = getResult(seq_bits, K1, 1);
    resultado = getResult(resultado, K2, 2);
    resultado = Permutation(resultado, IP1, 8);
    strcpy(buffer, resultado);
}

int main(int argv, char **argc) {
    int IP1[] = {4, 1, 3, 5, 7, 2, 8, 6};

    int qtdOP;   // quantidade de operacoes
    char OP_CD;  // operacao Cifrar ou Decifrar

    char *chave_K;
    char *seq_bits;

    char *K1;
    char *K2;

    char *resultado;
    resultado = (char *)malloc(sizeof(char) * 8);

    K1 = (char *)malloc(sizeof(char) * 8);
    K2 = (char *)malloc(sizeof(char) * 8);
    chave_K = (char *)malloc(sizeof(char) * 10);
    seq_bits = (char *)malloc(sizeof(char) * 8);

    scanf("%d", &qtdOP);

    int i;
    for (i = 0; i < qtdOP; i++) {
        scanf(" %c", &OP_CD);
        scanf(" %s", chave_K);
        scanf(" %s", seq_bits);

        // printf("%d\n%c\n%s\n%s\n", qtdOP, OP_CD, chave_K, seq_bits);
        getSubKeys(chave_K, K1, K2);
        if (OP_CD == 'C') {
            // printf("K1 : %s\n", K1);
            // printf("K2 : %s\n", K2);

            // printf("===================RESULTADO=================\n");
            // printf("===================K1=================\n");
            resultado = getResult(seq_bits, K1, 1);
            // printf("===================K2=================\n");
            resultado = getResult(resultado, K2, 2);

            resultado = Permutation(resultado, IP1, 8);
            printf("%s\n", resultado);
        }

        else if (OP_CD == 'D') {
            // printf("K1 : %s\n", K1);
            // printf("K2 : %s\n", K2);

            // printf("===================RESULTADO=================\n");
            // printf("===================K1=================\n");
            resultado = getResult(seq_bits, K2, 1);
            // printf("===================K2=================\n");
            resultado = getResult(resultado, K1, 2);
            resultado = Permutation(resultado, IP1, 8);
            printf("%s\n", resultado);
        }
    }

    return 0;
}