/* Igor Ribeiro Ferreira de Matos
140492
PAA - Problema_04: Selecionanado transações */

#include <stdio.h>
#include<stdlib.h>
 
//retorna o recompensador máximo entre dois recompensaores
int max(int a, int b) { 
    int max;
    if(a>b){
        max=a;
    }else{
        max=b;
    }
    return max;
}
 
/*
Função de seleção:
caso base
    se a quantidade de transações (n) ou a capacidade
    de Bytes (C) sejam 0, então teremos apenas "0"
caso "tamanho maior do que a capacidade":
    Se o tamanho do item for maior do que a capacidade limite,
    então selecionamos a "linha anterior"
caso "capacidade menor ou igual o limite":
    Se não, a seleção ótima será o máximo entre:
    1) a solução ótima da última linha + a solução ótima atual (descontando o tamanho da capacidade de bits)
    2) a solução ótima da última linha

+ aplicação de bottom-up com uma tabela K[][]

*/
int selecao(int C, int tamanho[], int recompensa[], int n)
{
    int i, w; //variáveis de (n..i) e (capacidade..w)

    /*Tabela de memorização*/
    int linhas, colunas;
    linhas = n+1;
    colunas= C+1;
    
    int** K = (int**)malloc(linhas * sizeof(int*));
    for (i = 0; i < linhas; i++)
        K[i] = (int*)malloc(colunas * sizeof(int));

    /*bottom-up*/
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= C; w++)
        {
            if (i == 0 || w == 0) //caso base
                K[i][w] = 0;
            else if (tamanho[i - 1] > w){ //caso "tamanho maior do que a capacidade":
                K[i][w] = K[i - 1][w]; //seleciona a linha anterior
            }
            else{        //caso "capacidade menor ou igual o limite":
                K[i][w] = max(                  //seleciona o máximo entre:
                    recompensa[i - 1]+ K[i - 1][w - tamanho[i - 1]], //ultima linha + linha atual
                    K[i - 1][w]                 //ultima linha
                    );
            }
        }
    }
 
    return K[n][C];
        
}
 
int main()
{
    /*
    Leitura da quantidade de transações (n) e
    do tamanho máximo da capacidade de butes (C)
    */
    int n, C;
    scanf("%d", &n);
    scanf("%d", &C);

    /*
    leitura de cada ri..rn (recompensas) e si..sn (tamanhos)
    */
    int *recompensa;
    int *tamanho;
    recompensa = malloc(n * sizeof(int));
    tamanho = malloc(n * sizeof(int));
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &recompensa[i]);
        scanf("%d", &tamanho[i]);
    }
    

    int res=0;
    res =selecao(C, tamanho, recompensa, n);
    printf("%d", res );
    return 0;
}