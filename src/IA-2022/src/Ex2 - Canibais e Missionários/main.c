/*
    Igor Ribeiro Ferreira de Matos - 140492
    Solução do problema dos Canibais e Missionários Utilizando Busca em Largura

    Adaptando TAD de Grafo disponibilizada por: André Backes (prof da Ufu)
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
//tad do jogo, com atributos relevantes para diferenciar cada estado único
struct tabuleiro;
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

// Função manual para implementar os poucos casos possíveis, baseado na resolução da atividade teórica da semana
void popula_casos(Grafo* gr);
// Função auxiliar para definir os casos na estrutura de dados do jogo
void define_estado(Grafo* gr, int id, int can, int mis, int barco);
// Função que verifica se o estado do vertice sendo visitado é igual ao estado de fim de jogo
void ehfim(Grafo *gr, int vert);


/* ======= IMPLEMENTAÇÃO ======= */

int main()
{
    int  vertices=15, visitados[vertices];  // como visto na atividade teórica, haverá 15 casos possíveis
    Grafo* gr = cria_Grafo(15, 4, 0);

    popula_casos(gr);
    // imprime_Grafo(gr);
    buscaLargura_Grafo(gr, 0, visitados);
        libera_Grafo(gr);
    
    printf("\nSolução não encontrada\n");   // Caso a função ehfim() não encontre um estado e finalize o programa por lá, a main() notificará aqui que não foi encontrada a solução

    return 0;
}


struct tabuleiro{       // TAD de estado do tabuleiro, com dados o suficiente para gerar estados únicos
    int id;
    int canibais_esq;
    int missionarios_esq;
    int barco;              //0=esq, 1=dir
};


struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
    struct tabuleiro* jogo;
};


void define_estado(Grafo* gr, int id, int can, int mis, int barco){
    gr->jogo[id].id=id;
    gr->jogo[id].canibais_esq=can;
    gr->jogo[id].missionarios_esq=mis;
    gr->jogo[id].barco=barco;
}

void popula_casos(Grafo *gr){
    define_estado(gr, 0,3,3,0);
    define_estado(gr, 1,1,3,1);
        insereAresta(gr,0,1,0,1);

    define_estado(gr, 2,2,3,1);
        insereAresta(gr,0,2,0,1);
    
    define_estado(gr, 3,2,2,1);
        insereAresta(gr,0,3,0,1);

    define_estado(gr, 4,2,3,0);
        insereAresta(gr,1,4,0,1);
        insereAresta(gr,2,4,0,1);
        insereAresta(gr,3,4,0,1);

    define_estado(gr, 5,0,3,1);
        insereAresta(gr,4,5,0,1);
    define_estado(gr, 6,1,3,0);
        insereAresta(gr,5,6,0,1);
    define_estado(gr, 7,1,1,1);
        insereAresta(gr,6,7,0,1);
    define_estado(gr, 8,2,2,0);
        insereAresta(gr,7,8,0,1);
    define_estado(gr, 9,2,0,1);
        insereAresta(gr,8,9,0,1);
    define_estado(gr, 10,3,0,0);
        insereAresta(gr,9,10,0,1);
    define_estado(gr, 11,1,0,1);
        insereAresta(gr,10,11,0,1);

    define_estado(gr, 12,2,0,0);
    define_estado(gr, 13,1,1,0);
        insereAresta(gr,11,12,0,1);
        insereAresta(gr,11,13,0,1);
    define_estado(gr, 14,0,0,1);
        insereAresta(gr,12,14,0,1);
        insereAresta(gr,13,14,0,1);
}

// Ideia para uma função genérica, definir todos os possíveis movimentos baseado nas regras e limitações do jogo
/*
void funcao_geradora(int miss_esq, int barco, int can_esq){

    if(barco==0){
        if(miss_esq>0){
            //define mover um missionário da esquerda para direita
            if(miss_esq>1){
                //define dois missionários da esquerda pra direita
            }
            if(can_esq>0){
                    //define mover um missionário e um canibal da esq pra dir
            }
        }else{
            //
        }
    }else if(barco==1){
            //
    }

}
*/

void ehfim(Grafo *gr, int vert){
    int mis_esq = gr->jogo[vert].missionarios_esq,
        can_esq = gr->jogo[vert].canibais_esq,
        barco = gr->jogo[vert].barco;

    if(mis_esq == 0 && can_esq == 0 && barco == 1){
        printf("Solucao alcancada\n---Estado---\nmis_esq=%d,\ncan_esq=%d,\nbarco=%d\n------\n\n",gr->jogo[vert].missionarios_esq, gr->jogo[vert].canibais_esq, gr->jogo[vert].barco);
        libera_Grafo(gr);
        exit(0);
    }
}


Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));
        gr->jogo = (struct tabuleiro*) calloc(nro_vertices,sizeof(struct tabuleiro));

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
        free(gr->jogo);

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
            ehfim(gr, vert);                        // a cada vértice visitado, verifica se ele está com o estado de final de jogo
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