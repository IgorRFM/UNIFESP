#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

void swap(unsigned char *a, unsigned char *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Inicializacao_S(char *key, unsigned char *S)
{

    int len = strlen(key);
    int j = 0;

    for (int i = 0; i < N; i++)
        S[i] = i;

    return 0;
}

int permutacao_inicial_S(int j, unsigned char *S, char *key, int len)
{
    for (int i = 0; i < N; i++)
    {
        j = (j + S[i] + key[i % len]) % N;

        swap(&S[i], &S[j]);
    }
    return j;
}

int geracao_fluxo(unsigned char *S, char *plaintext, unsigned char *res)
{

    int i = 0;
    int j = 0;
    size_t n, len = strlen(plaintext);

    for (n = 0; n < len; n++)
    {
        i = (i + 1) % N;
        j = (j + S[i]) % N;
        swap(&S[i], &S[j]);
        int K = S[(S[i] + S[j]) % N];
        res[n] = K ^ plaintext[n];
    }

    return 0;
}

int main(int argc, char *argv[])
{

    char chave[256], entrada[256];

    // printf("Digite a entrada: ");
    scanf("%s", entrada);
    // printf("\nDigite a chave e a entrada: ");
    scanf("%s", chave);
    unsigned char *res = malloc(sizeof(int) * strlen(entrada));

    unsigned char S[N];
    Inicializacao_S(chave, S);
    permutacao_inicial_S(0, S, chave, strlen(chave));
    geracao_fluxo(S, entrada, res);

    for (size_t i = 0, len = strlen(entrada); i < len; i++)
        printf("%x:", res[i]);

    return 0;
}