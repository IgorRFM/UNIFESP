#include <stdio.h>
#include<stdlib.h>

int menor_nao_nulo=0;

typedef struct{
    int *vet;
    int tam;
    int ini;
}TipoNo;

typedef struct{
    TipoNo *no;
    int tam;
}TipoDado;

void printData(TipoDado data){
    int i,j;
    for(i=0; i<data.tam; i++){
        for(j=data.no[i].ini; j<data.no[i].tam; j++){
            printf("%d ", data.no[i].vet[j]);
        }
        printf("\n");
    }
}

void removeMenor(TipoDado *data){
    while(data->no[menor_nao_nulo].ini>=data->no[menor_nao_nulo].tam){
        menor_nao_nulo++;
    }
    //printf("removendo menor elemento (%d)(%d)", data->no[menor_nao_nulo].vet[data->no[menor_nao_nulo].ini],data->no[menor_nao_nulo].ini);
    data->no[menor_nao_nulo].ini++;

}

void merge(TipoDado *data, int l, int m, int r){
    int i,j,k;
    int n1=m-l+1, n2=r-m;

    TipoDado L, R, temp;
    L.no = malloc (n1*sizeof(TipoNo));
    R.no = malloc (n2*sizeof(TipoNo));

    for(i=0; i<n1;i++)
        L.no[i] = data->no[l+i];
    for(j=0; j<n2;j++)
        R.no[j] = data->no[m+1+j];
    //printData(L);
    
    i=0; j=0; k=l;
    while(i<n1 && j<n2){
        if(L.no[i].vet[L.no[i].ini] <= R.no[j].vet[R.no[j].ini]){
            data->no[k]=L.no[i];
            i++;
        }else{
            data->no[k]=R.no[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        data->no[k]=L.no[i];
        i++;
        k++;
    }
    while(j<n2){
         data->no[k]=R.no[j];
        j++;
        k++;
    }
}

void mergeSort(TipoDado *data, int l, int r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);
  
        merge(data, l, m, r);
    }
}

unsigned long int somar(TipoDado data){
    int i,j;
    unsigned long int soma=0;
    for(i=0; i<data.tam; i++){
        if(data.no[i].tam>0)
            soma+=data.no[i].vet[data.no[i].ini];
    }
    return soma;
}

int main(){
    int I,K,i,j,tam;
    TipoDado data;

    scanf("%d %d", &K, &I);

    data.no = malloc (K * sizeof(TipoNo));
    data.tam=K;

    for(i=0; i<K; i++){
        scanf("%d", &tam);
        data.no[i].vet = malloc(tam*sizeof(int));
        for(j=0; j<tam; j++){
            scanf("%d", &data.no[i].vet[j]);
        }
        data.no[i].tam=tam;
        data.no[i].ini=0;
    }
    
    
    unsigned long int soma;
	for(i=0;i<I-1;i++){
        mergeSort(&data, 0, data.tam-1);
        removeMenor(&data); //nós já estão ordenados
	}
   
    soma = somar(data);

    printf("%d", soma);

    return 0;
}