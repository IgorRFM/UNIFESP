#include<stdio.h>
#include<stdlib.h>

#define mov01 17
#define mov02 15
#define mov03 10
#define mov04 6

int verificaPeoes(int P, int *A){
    int i;
    
    for(i=0; i<P; i++){
        if(A[i] > 64){
            return 0;
        }
    }
}

int backtracking(int P, int *A, int H, int k){ /*problema: por enquanto a verificação é feita do último peão para o primeiro, o que não seria a ideia*/
    //printf("p1: %d\n", P);
    k=0;
    if(P == 0 ){
        return 0;
    }
    if(verificaPeoes == 0){
        return -1000;
    }
    if(H+mov01 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H+mov02 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H+mov03 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H+mov04 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H-mov01 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H-mov02 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H-mov03 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else if(H-mov04 == A[P]){
        k++;
        H = A[P];
        A[P] = -1;
        P--;
    }else{
        H=H+mov01;
    }
    int i;
    for(i=1; i<=P; i++){
        A[i]=A[i]+8;
    }
    
    //printf("p2: %d\n", k);

    k += backtracking(P, A, H, k);
    return k;
}

int main(){
    int P, *A, i, H;

    scanf("%d", &P); //quantidade de peões
    A = malloc (sizeof(int)*(P+1));

    for(i=1; i<=P; i++){
        scanf("%d", &A[i]); //posição dos peões
    }

    scanf("%d", &H); //posição do cavalo

    // for(i=0; i<P; i++){
    //     printf("%d - ", A[i]);
    // }

    //printf("%d", H);

    int k = backtracking(P,A,H,k);
    if( k <= 0){
        printf("impossible");
    }else{
        printf("%d", k);
    }

    return 0;
}