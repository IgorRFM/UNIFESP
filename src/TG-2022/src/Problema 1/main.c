/*
==Entradas==
Linha 1: N (numero de usuario) e M (interações dos usuários)
Linha 2 até M: u e v (u segue v diretamente) 
Linha M+1: P (número de pares de usuários a serem consultados)
Linha M+2 até M+P: u e v (consultando se u segue v direta ou indiretamente)

==Saída==
Para cada consulta:{1 se segue direta ou indireta, 0 caso contrário}
*/

/*
Proposta: construir o dígrafo com matriz de 
adjacência e, para cada consulta realizar uma busca
em profundidade em "u" e "v"
*/

/* =========== BIBLIOTECAS E DEFINES ============ */
#include <stdio.h>
#include <stdlib.h>
static int cnt, pre[30000];
static int cntt, post[30000];
static int vv[30000];

/* ============ TADS.H ============ */
// TADS consultadas de: [ https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html ]
// Estrutura de dados representando as arestas e o grafo (Graph)
// Como o método de representação utilizado é lista de adjacência,
// cada nó da lista [Graph->adj], vai representar uma vértice.
// Cada vértice aponta para o próximo [arestas->next]

typedef struct node *arestas;
struct node;

typedef struct graph *Graph;
struct graph;


/* ============ FUNÇÕES ============ */
// A função InsereNO retorna uma aresta que começa em W e aponta para NEXT
static arestas InsereNO( int w, arestas next);

// A função GRAPHinit inicia um gráfico zerado com umas lista de adjacência
// com V arestas
Graph GRAPHinit( int V);

// Utilizando o InsereNO, a função GRAPHinserArc cria links (adiciona na lsita de adj)
// entre os vértices "v" e "w". (V começa a apontar para W)
void GRAPHinsertArc( Graph G, int v, int w);

// Função auxiliar para a função GRAPHdestroy, libera a memória dos vértices apontados
// de uma posição da lista de adj do grafo
void DestroiLista(arestas lista);

// Função para liberar memória de todas as posições da lista de adj do grafo e do grafo
void GRAPHdestroy(Graph a);

// A função GRAPHstrongCompK implementa o algoritmo de Kosaraju.
// A função te mcomo objetivo enumerar os vértices que pertencem a mesma componente em um vetor.
// Se o vértice 1 pertence a uma componente "1" e o dois a uma outra componente "2", ou seja, 
// não são fortemente conextos, então sc[1] == 1 e sc[2] == 2.
// Esta função usa um vetor "pre" para que salve enquanto faça a consulta os vértices já visitados (na dfs) em um
// grafo invertido. Deste grafo invertido, usamos essa ordem para achar a pós ordem no grafo original.
// Usamos um vetor "pos" pra salvar a numeração dos vértices a ser visitado na pós ordem (as folhas primeiro)
// então, no vetor VV, é salvo a ordem que os vértices serão visitados.
// Finalmente, é raelizada uma busca dfs em G, no grafo original, seguindo a ordem encontrada em VV.
int GRAPHstrongCompsK( Graph G, int *sc);

// Esta função faz a DFS atribuindo "k" para a numeração de componente de cada vértice.
// Quando acaba uma componente, GRAPHstrongCompsK itera para a próxima componente e
// concatena o valor de K.
void dfsRstrongCompsK( Graph G, int v, int *sc, int k) ;

// Busca dfs no grafo invertido
void dfsR( Graph GR, int v) ;

// Função para inverter o grafo
Graph GRAPHreverse( Graph G);

/* ============ MAIN ============ */

int main(){
    int N, M,i, u,v;
    scanf("%d %d", &N,&M);
    
    Graph g = GRAPHinit(N);
    
    for(i=0; i<M; i++){
        u=0; v=0;
        scanf("%d %d", &u, &v);
        GRAPHinsertArc(g, u, v);
    }
    
    // GRAPHprint(g);
    int sc[N], P;
    GRAPHstrongCompsK(g, sc);
    scanf("%d", &P);
    u=0;v=0;

    for(i=0; i<P; i++){
        scanf("%d %d", &u,&v);
        if(sc[u]==sc[v]){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    
    return 0;
}


typedef struct node *arestas;
struct node { 
   int w; 
   arestas next; 
};

struct graph {
   int V; 
   int A; 
   arestas *adj; 
};
typedef struct graph *Graph;

static arestas InsereNO( int w, arestas next) { 
   arestas a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (arestas));
   for (int v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}
void GRAPHinsertArc( Graph G, int v, int w) { 
   for (arestas a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = InsereNO( w, G->adj[v]);
   G->A++;
}

void GRAPHprint( Graph G) { 
    int i;
    for(i=0; i< G->V; i++){
        printf("[%d]", i);
        for (arestas a = G->adj[i]; a != NULL; a = a->next) 
            printf("->%d", a->w);
        printf("\n");
    }
}

void DestroiLista(arestas lista) {
  arestas a;
  while(lista) {
    a = lista->next;
    free(lista);
    lista=a;
  }
}
void GRAPHdestroy(Graph a) {
  int i;
  for(i=0;i<a->V;i++) {
    DestroiLista(a->adj[i]);

  }
  free(a->adj);
  free(a);
}

void dfsRstrongCompsK( Graph G, int v, int *sc, int k) 
{ 
   sc[v] = k;
   for (arestas a = G->adj[v]; a != NULL; a = a->next)
      if (sc[a->w] == -1) 
         dfsRstrongCompsK( G, a->w, sc, k);
}

void dfsR( Graph GR, int v) 
{ 
   pre[v] = cnt++; 
   for (arestas a = GR->adj[v]; a != NULL; a = a->next)
      if (pre[a->w] == -1) 
         dfsR( GR, a->w); 
   post[v] = cntt++;
}

Graph GRAPHreverse( Graph G) 
{
   Graph GR = GRAPHinit( G->V);
   for (int v = 0; v < G->V; ++v) 
      for (arestas a = G->adj[v]; a != NULL; a = a->next)
         GRAPHinsertArc( GR, a->w, v);
   return GR;
}

int GRAPHstrongCompsK( Graph G, int *sc) 
{
   // fase 1:
   Graph GR = GRAPHreverse( G);
   cnt = cntt = 0;
   int v; 
   for (v = 0; v < GR->V; ++v) pre[v] = -1;
   for (v = 0; v < GR->V; ++v) 
      if (pre[v] == -1)
         dfsR( GR, v); 
   for (v = 0; v < GR->V; ++v) 
      vv[post[v]] = v;
   // vv[0..V-1] é permutação de GR em pós-ordem

   // fase 2:
   for (v = 0; v < G->V; ++v) sc[v] = -1;
   int k = 0;
   for (int i = G->V-1; i >= 0; --i) {
      v = vv[i];
      if (sc[v] == -1) { // nova etapa
         dfsRstrongCompsK( G, v, sc, k);
         k++;
      }
   }
   GRAPHdestroy( GR);
   return k;
}
