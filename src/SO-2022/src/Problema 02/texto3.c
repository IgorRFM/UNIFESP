#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAXTAM 2000
#define MAX_T 50
#define MAX_CHAR 50

struct stat sb;
char nome[20];
int maps;

typedef struct TLista{
    char string[MAX_CHAR];
    int valor;
    struct TLista *prox;
}TLista;
typedef struct {
    int index;
    char string[MAX_CHAR];
}param_t;

TLista *Hash[6];

char strings[MAXTAM][MAXTAM];
int numPalavras;
pthread_mutex_t mutex_trata = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_map = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t tratar_tid[MAX_T];
pthread_t mapear_tid[MAX_T];
typedef struct{
    int inicio;
    int fim;
} bloco;

int tamanho(){
    stat(nome, &sb);
    int t = sb.st_size;
    return t;
}

void *tratamento(void* args){
    //int inicio, int fim
    //void* args
    pthread_mutex_lock(&mutex_trata);
    bloco bytes = *(bloco *)args;
    int inicio = bytes.inicio;
    int fim = bytes.fim;
    FILE *auxiliar=fopen(nome,"r");
    if(inicio != 1){
        fseek(auxiliar, inicio-1, SEEK_SET);
        int letra =fgetc(auxiliar);
        while(letra!=32){
            if(letra==10){
                break;
            }
            fseek(auxiliar, inicio-1, SEEK_SET);
            letra=fgetc(auxiliar);
            inicio--;
        }
    }
    if(fim!=tamanho()){
        fseek(auxiliar, fim-1, SEEK_SET);
        int letra=fgetc(auxiliar);
        while(letra!=32){
            fseek(auxiliar, fim-1, SEEK_SET);
            letra=fgetc(auxiliar);
            fim--;
        }
    }
    bytes.inicio = inicio;
    bytes.fim=fim;
    pthread_mutex_unlock(&mutex_trata);
}

TLista *novo(char string[]){
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->prox = NULL;
    novo->valor=1;
    strcpy(novo->string, string);
    return novo;
}


void *insere(void* args){
    param_t castedArgs = *(param_t *)args;
    //printf("->%s<-\n",castedArgs.string);
    //pthread_mutex_lock(&mutex);
    TLista *Lista = Hash[castedArgs.index];
    if (Lista==NULL){
        Hash[castedArgs.index] = novo(castedArgs.string);
      //  pthread_mutex_unlock(&mutex);
        return NULL;
    }
    while(Lista->prox!=NULL)
        Lista = Lista->prox;

    Lista->prox = novo(castedArgs.string);
    //pthread_mutex_unlock(&mutex);
}

void *map(void* args){
    //int inicio, int fim
    //void* args
    pthread_mutex_lock(&mutex_map);
    bloco bytes = *(bloco *)args;
    int inicio = bytes.inicio;
    int fim = bytes.fim;
    FILE *pont_arq=fopen(nome,"r");
    char c;
    int N=inicio-1, i=0, j=0, k, l=0; //-1 no inicio pois come�a no 0 entao caracter 8 � posi��o 7
    param_t params[MAX_T];
    char vetor[50];
    for(i=0;i<50;i++)
        vetor[i]=0;
    fseek(pont_arq, inicio-1, SEEK_SET);
    while (N<=fim+1) { //+1 pois tem de checar se o proximo eh espa�o ou enter pra adicionar palavra
        c=fgetc(pont_arq);
        //printf("%c", c);

        if( c == 32 || c == 10 || c==-1){
            params[j].index = ((int)vetor[0])%6;
            strcpy(params[j].string, vetor);
            if(strlen(params[j].string)!=0){
                insere((void* )&params[j]);
            }
            j++;
            for(i=0;i<50;i++)
                vetor[i]=0;
            l=0;
        }else{
            vetor[l] = c;
            l++;
        }
        N = N + sizeof(c);
    }
    pthread_mutex_unlock(&mutex_map);
}

void divide(){
    int t = tamanho();
    int qnt_blocos= t/maps, i, j=0;
    bloco blocos[qnt_blocos];
    printf("%d / %d = %d\n", t, maps, qnt_blocos);
    for(i=1;i<=t;i=i+qnt_blocos){
        blocos[j].inicio=i; //inicio do bloco
        blocos[j].fim=i+qnt_blocos-1; //fim do bloco
        //printf("\nbloco: %d %d %d", j, blocos[j].inicio,  blocos[j].fim);
        pthread_create(&tratar_tid[j],NULL, tratamento, (void*)&blocos[j]);
        j++;
    }

    for(i=1;i<=t;i=i+qnt_blocos)
        pthread_join(&tratar_tid[i],NULL);


    for(i=1;i<=t;i=i+qnt_blocos)
        pthread_create(&mapear_tid[j],NULL, map, (void*)&blocos[j]);
    for(i=1;i<=t;i=i+qnt_blocos)
        pthread_join(&mapear_tid[i],NULL);


    if(blocos[j-1].fim>t){
        blocos[j-1].fim=t;
    }
}

void printList(TLista *Lista){
    while(Lista!=NULL){
        printf("%s ",Lista->string);
        Lista=Lista->prox;
    }
    printf("\n");
}
void getHash(){
    int i=0;
    for(i=0;i<6;i++){
        printf("%d ",i);
        printList(Hash[i]);
    }
}

void printar_resultado(TLista *Lista){
    while(Lista!=NULL){
        if(strcmp(Lista->string, "CHECADO")!=0){
            printf("%s--------%d\n",Lista->string, Lista->valor);
        }
        Lista=Lista->prox;
    }
}

void *reduce(void* args){
    int index = *(int *)args;
    TLista *aux=Hash[index];
    TLista *principal=Hash[index];
    while(principal!=NULL){
        while(aux!=NULL){
            aux=aux->prox;
            if(aux==NULL){
                break;
            }
            if(strcmp(principal->string,  aux->string)==0){
                principal->valor++;
                strcpy(aux->string, "CHECADO");
            }
        }
        principal=principal->prox;
        aux=principal;
    }
}

pthread_t reduce_tid[6];
int nums[6]={0,1,2,3,4,5};

void map_reduce(){
    int i;
    for(i=0;i<6;i++){
        pthread_create(&reduce_tid[i],NULL, reduce, (void*)&nums[i]);
    }
    for (i=0; i<6; i++){
        pthread_join(reduce_tid[i], NULL);
    }
    for(i=0;i<6;i++){
        printar_resultado(Hash[i]);
    }
}

int main(){
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    printf("O arquivo tem %d bytes digite quantos maps deseja abrir: ", tamanho());
    scanf("%d", &maps);
    divide();
    //printf("\n\n\n\n\n\n\n");
    getHash();
    printf("\nPalavra e Ocorrências\n");
    map_reduce();
    return 0;
}