/*
    Igor Ribeiro Ferreira de Matos - 140492
    Abordagem usando Programação Dinâmica e Busca em Largura

    Utilizando TAD de Grafo disponibilizada por: André Backes (prof da Ufu)
    Programação Descomplicada Linguagem C
    <https://www.youtube.com/watch?v=pJ3ilnhXWCQ&list=PL8iN9FQ7_jt4oQHq1TSeMgvVdolJvYsLO&index=9>
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define mod (int)pow(2,31)-1


/*  ======= TAD =======  */
//tad do grafo
typedef struct grafo Grafo;
// função para criar e iniciar grafo
Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
// função para liberar o grafo da memória
void libera_Grafo(Grafo* gr);
// função para inserir uma aresta no grafo gr, do vértice orig pro dest
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
// função para realizar a busca em largura
void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado);

void imprime_Grafo(Grafo *gr);


/* ======= FUNÇÕES AUXILIÁRES ======= */


// Função para verificar se os vizinhos da célula são posições válidas
int valido(int i, int j, int tamanho_da_grid);


// Função para a leitura inicial da grade NxN
// int **grid = grade
// tamanho_da_grid = N
void ler_grid(long int **grid, int tamanho_da_grid);

// Função para descobrir a quantidade de caminhos únicos através de DP,
// considerando apenas as possibilidades de movimentações: para cima e
// para baixo.
// int **grid = grade
// tamanho_da_grid = N
// int **solucao = tabela da Programação Dinâmica
unsigned long int selecao_de_caminhos(long int **grid, int tamanho_da_grid, int eh_digrafo, int vertices, int pos , Grafo * gr);


/* ======= IMPLEMENTAÇÃO ======= */

int main()
{
    int tamanho_da_grid, i;

    scanf("%d", &tamanho_da_grid);
    getchar();

    long int **grid;
    grid = (long int **)malloc(tamanho_da_grid * sizeof(long int *));
    for (i = 0; i < tamanho_da_grid; i++)
    {
        grid[i] = (long int *)malloc(tamanho_da_grid * sizeof(long int));
    }

    ler_grid(grid, tamanho_da_grid);

    int eh_digrafo = 1;
    int vertices = tamanho_da_grid*tamanho_da_grid, pos=0;

    Grafo* gr = cria_Grafo(vertices, 4, 0);

    unsigned long int res = selecao_de_caminhos(grid, tamanho_da_grid, eh_digrafo, vertices, pos ,gr);
            //printf("%lu\n", (res%mod)+1);

    int visitados[vertices];
    //imprime_Grafo(gr);
    if (res > 0)
    {
        printf("%lu\n", (res%mod)+1);
    }
    else{
        buscaLargura_Grafo(gr, 0, visitados);
        if(visitados[vertices-1]>0){
            printf("THE GAME IS A LIE\n");
        }else{
            printf("INCONCEIVABLE\n");
        }
    }
    libera_Grafo(gr);

    return 0;
}

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};


Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}


void ler_grid(long int **grid, int tamanho_da_grid)
{
    int i, j;
    char entrada;

    for (i = 0; i < tamanho_da_grid; i++)
    {
        for (j = 0; j < tamanho_da_grid; j++)
        {
            scanf(" %c", &entrada);
            if (entrada == '.')
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
        getchar();
    }
}

unsigned long int selecao_de_caminhos(long int **grid, int tamanho_da_grid, int eh_digrafo, int vertices, int pos , Grafo * gr)
{
    unsigned long int **solucao, i, j;
    solucao = (unsigned long int **)malloc(tamanho_da_grid * sizeof(unsigned long int *));
    for (i = 0; i < tamanho_da_grid; i++)
    {
        solucao[i] = (unsigned long int *)malloc(tamanho_da_grid * sizeof(unsigned long int));
    }

    /*
    Casos da tabela de programação dinâmica (andando apenas para
    baixo e para direita):
        -> 0,                                   se grid[i][j]==0
        -> 1,                                   se i e j == 0, e grid[i][j]==1
        -> solucao[i-1][j],                     se i>0 e j == 0 e grid[i][j]==1
        -> solucao[i][j-1],                     se i=0, j>0 e grid[i][j]==1
        -> solucao[i][j-1] + solucao[i-1][j],   se i>0, j>0, grid[i][j]==1
    */
    for (i = 0; i < tamanho_da_grid; i++)
    {
        for (j = 0; j < tamanho_da_grid; j++)
        {
            if (grid[i][j] == 0)
            { //  grid[i][j]==0
                solucao[i][j] = 0;
            }
            else
            { //  grid[i][j]==1
                if (i == 0 && j == 0)
                { // se i e j == 0
                    solucao[i][j] = 1;
                }
                else if (i > 0 && j == 0)
                { // se i>0 e j == 0
                    solucao[i][j] = solucao[i - 1][j];
                }
                else if (i == 0 && j > 0)
                { // se i == 0 e j>0
                    solucao[i][j] = solucao[i][j - 1];
                }
                else
                { // se i>0, j>0
                    solucao[i][j] = solucao[i][j - 1] + solucao[i - 1][j];
                }
            }

            //printf("\n%d",i);

                if(valido(i, j+1, tamanho_da_grid)==1){
                    if(grid[i][j+1]==1)
                    insereAresta(gr, pos, pos+1, eh_digrafo, 0);
                }
                if(valido(i, j-1, tamanho_da_grid)==1){
                    if(grid[i][j-1]==1)
                    insereAresta(gr, pos, pos-1, eh_digrafo, 0);
                }
                if(valido(i+1, j, tamanho_da_grid)==1){
                    if(grid[i+1][j]==1)
                    insereAresta(gr, pos, pos+tamanho_da_grid, eh_digrafo, 0);
                }
                if(valido(i-1, j, tamanho_da_grid)==1){
                    if(grid[i-1][j]==1)
                    insereAresta(gr, pos, pos-tamanho_da_grid, eh_digrafo, 0);
                }
                pos++;



        }
    }

    // printf("\nSolução: %d\n", solucao[tamanho_da_grid-1][tamanho_da_grid-1]);
    // imprimir_grid(solucao, tamanho_da_grid);

    return solucao[tamanho_da_grid - 1][tamanho_da_grid - 1];
}

int valido(int i, int j, int tamanho_da_grid){
    if(i>=0 && i<tamanho_da_grid && j>=0 && j<tamanho_da_grid){
        
        return 1;
    }else{
        return 0;
    }
}


void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1;
    int *fila, IF = 0, FF = 0;
    for(i=0; i<gr->nro_vertices; i++)
        visitado[i] = 0;

    NV = gr->nro_vertices;
    fila = (int*) malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    while(IF != FF){
        IF = (IF + 1) % NV;
        vert = fila[IF];
        if(!visitado[vert]){
            visitado[vert] = cont;
            cont++;
            for(i=0; i<gr->grau[vert]; i++){
                if(!visitado[gr->arestas[vert][i]]){
                    FF = (FF + 1) % NV;
                    fila[FF] = gr->arestas[vert][i];
                }
            }
        }
    }
    free(fila);
}