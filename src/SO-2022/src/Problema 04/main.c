#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define numprocessos 10
#define numedereco 100

typedef struct pag{
	uint16_t presente:1; // esta ou nao mapeado em memoria fisica
	uint16_t referenciada:1; //se processo ja leu a pagina
	uint16_t modificada:1; //se processo alterou
    int numpag:12;
	//uint16_t pad:1;
	//uint16_t deslocamento:12;
    //uint16_t protecao:2; //leitura ou escrita
}pag;

typedef struct lista{
    pag pagina;
    struct lista *ant;
}lista;

void shuffle(int array[]){
    srand(time(NULL));
    int i;
    for(i=0;i<numedereco;i++){
        array[i]=i*2;
    }
    if (numedereco > 1) {
        for (i = 0; i < numedereco - 1; i++){
          int j = i + rand() / (RAND_MAX / (numedereco - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int nums[numedereco];

lista *inicio=NULL, *fim=NULL;

void inicia(){
    inicio=NULL;
    fim=NULL;
}

void adicionar(lista *list, pag pagina, int alet){
    lista *ptr = (lista*)malloc(sizeof(lista));

    ptr->pagina.referenciada=1;
    ptr->pagina.numpag=alet;

    ptr->ant=NULL;
    if(inicio==NULL && fim==NULL){
        inicio=ptr;
        fim=ptr;
    }
    else{
        //printf("----");
        lista *aux = fim;
        aux->ant=ptr;
        fim=ptr;
    }
    return inicio;
}
void adicionarCircular(lista *list, pag pagina, int alet){
    lista *ptr = (lista*)malloc(sizeof(lista));
    if(inicio==NULL){
        ptr->pagina.referenciada=1;
        ptr->pagina.numpag=alet;
        inicio=ptr;
        inicio->ant=inicio;
    }else{
        lista *aux = inicio;
        while (aux->ant != inicio)
            aux = aux->ant;

        aux->ant=ptr;
        ptr->ant=inicio;
        ptr->pagina.numpag=alet;
        ptr->pagina.referenciada=1;
    }
}
lista *remover(){
    lista *aux = inicio;
    inicio = inicio->ant;

    return aux;
}
lista *removerCircular(){
    lista *aux = inicio;
    while (aux->ant != inicio)
        aux = aux->ant;

    aux->ant = inicio->ant;
    inicio = inicio->ant;
    return aux;
}
void enchememoria(lista *list){
    //shuffle(nums);
    lista *paginas = (lista *)malloc(sizeof(lista));
    inicia();
    int i;
    for(i=0;i<numedereco;i++){
        pag pg;
        adicionar(paginas, pg, nums[i]);
    }
}

void enchememoriaCircular(lista *list){
    shuffle(nums);
    lista *paginas = (lista *)malloc(sizeof(lista));
    inicia();
    int i;
    for(i=0;i<numedereco;i++){
        pag pg;
        adicionarCircular(paginas, pg, nums[i]);
    }
}

void pagemiss(lista *list, pag p, int a){
    remover();
    adicionar(list, p, a);
}

void pagemissCircular(lista *list, pag p, int a){
    remover();
    adicionarCircular(list, p, a);
}

int procura(lista *Lista, pag pg){ //procura pelo endereço da página que é o numpag
    lista *aux=inicio;
    while(aux->ant!=NULL){
        if(aux->pagina.numpag==pg.numpag){
            return 1; //achou pagina
        }else{
            aux=aux->ant;
        }
    }

    printf("page miss - ");
    pagemiss(Lista, pg, pg.numpag);
    return 0;//page miss
}
int procuraCircular(lista *Lista, pag pg){ //procura pelo endereço da página que é o numpag
    lista *aux=inicio;
    while(aux->ant!=inicio){
        if(aux->pagina.numpag==pg.numpag){
            return 1; //achou pagina
        }else{
            aux=aux->ant;
        }
    }

    if (aux->pagina.referenciada)
        aux->pagina.referenciada = 0;
    else
        remover();

    printf("page miss - ");
    return 0;//page miss
}

void limpar(lista *list){
    free(list); //para desocupar a memória da lista circular
}

int main(){
    enchememoriaCircular(NULL);
    int i=100;
    lista *circular = inicio;
    pag p;
    printf("Memoria preenchida com valores entre 0-100\n\nAlgoritmo de Relógio\n");
    i = 100;
    circular = inicio;
    int numpagemiss=0;
    while (i){
        p.numpag = rand()%125;
        if (!procuraCircular(inicio, p)){
            printf("%d\n", p.numpag);
            numpagemiss++;
        }
        i-=1;
    }
    printf("Numero de pagemiss: %d\n", numpagemiss);
    limpar(circular);
    printf("\nMemoria preenchida com os mesmos valores entre 0-100\n\nAlgoritmo FIFO\n");
    enchememoria(NULL);
    lista *FIFO = inicio;
    i = 100;
    FIFO = inicio;
    numpagemiss=0;
    while (i){
        p.numpag = rand()%125;
        if (!procura(inicio, p)){
            printf("%d\n", p.numpag);
            numpagemiss++;
        }
        i-=1;
    }
    printf("Numero de pagemiss: %d", numpagemiss);

    return 0;

}