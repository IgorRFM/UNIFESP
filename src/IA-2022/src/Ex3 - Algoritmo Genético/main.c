#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printVetor(int *Vetor, int qtde_bits){
    int k;
    for(k=0;k<qtde_bits;k++){
            printf("%d ",Vetor[k]);
    }
    printf("\n");
}

// double bernoulli(int *filho, int *alvo, int qtde_bits, float prob_mutacao){
//     int i;
//     double prob=1, prob_m = prob_mutacao;
//     for(i=0;i<qtde_bits;i++){
//         if(filho[i]==alvo[i]){
//             prob = prob * (1-prob_m);
//         }else{
//             prob = prob * prob_m;
//         }
//     }
//     return prob;
// }

int main(){
    int qtde_casos, qtde_bits, pos_corte, *IndvA, *IndvB, *Alvo, i, k, *filho1, *filho2, entrada;
    long double prob_mutacao;
    long double prob;
    
    scanf("%d", &qtde_casos);   //Lê T, a quantidade de caso de testes
    for(i=0; i<qtde_casos; i++){
        
        scanf("%d", &qtde_bits); //Lê a quantidade de bits que cada indv tem e aloca os vetores
        IndvA = (int*)malloc(sizeof(int *)*qtde_bits);IndvB = (int*)malloc(sizeof(int *)*qtde_bits);Alvo = (int*)malloc(sizeof(int *)*qtde_bits);
        scanf("%d %Lf", &pos_corte, &prob_mutacao); //Lê a posição de corte e a probabilidade de mutação

        
        int n=qtde_bits, i;
        n = pow(10,qtde_bits-1);
        scanf("%d", &entrada); //Lê indivA
        for(i=0; i<qtde_bits; i++){
            IndvA[i] = entrada/n;
            entrada = entrada%n;
            n = n/10;
        }

        n = pow(10,qtde_bits-1);
        scanf("%d", &entrada); //Lê indivB
        for(i=0; i<qtde_bits; i++){
            IndvB[i] = entrada/n;
            entrada = entrada%n;
            n = n/10;
        }
        
        n = pow(10,qtde_bits-1);
        scanf("%d", &entrada); //Lê alvo
        for(i=0; i<qtde_bits; i++){
            Alvo[i] = entrada/n;
            entrada = entrada%n;
            n = n/10;
        }

        filho1 = (int*)malloc(sizeof(int *)*qtde_bits);
        filho2 = (int*)malloc(sizeof(int *)*qtde_bits);

        for(k=0;k<pos_corte;k++){
            filho1[k] = IndvA[k];
            filho2[k] = IndvB[k];
        }
        for(k=pos_corte; k<qtde_bits; k++){
            filho1[k] = IndvB[k];
            filho2[k] = IndvA[k];
        }

        // printf("bits: %d | pos_corte: %d | prob: %.7f\n", qtde_bits, pos_corte, prob_mutacao);
        // printVetor(IndvA, qtde_bits);
        // printVetor(IndvB, qtde_bits);
        // printVetor(filho1, qtde_bits);
        // printVetor(filho2, qtde_bits);
        // printf("________________________\n");

        double probA=1, probB=1, probAnB=1, probAuB=1;
        n = pow(10,8);
        // probA = bernoulli(filho1, Alvo, qtde_bits, prob_mutacao);
        // probB = bernoulli(filho2, Alvo, qtde_bits, prob_mutacao);
        for(i=0;i<qtde_bits;i++){
            if(filho1[i]==Alvo[i]){
                probA = probA * (1-prob_mutacao);
            }else{
                probA = probA * prob_mutacao;
            }
             if(filho2[i]==Alvo[i]){
                probB = probB * (1-prob_mutacao);
            }else{
                probB = probB * prob_mutacao;
            }
        }
        probAuB = probA+probB-(probA*probB);
        printf("%.7lf\n", probAuB);
        free(IndvA);free(IndvB);free(Alvo);free(filho1);free(filho2);
    }

    return 0;
}