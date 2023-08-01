#include<stdio.h>
#include<string.h>

void p10(char K_p10[11], char K[11]){
    K_p10[0] = K[2];
    K_p10[1] = K[4];
    K_p10[2] = K[1];
    K_p10[3] = K[6];
    K_p10[4] = K[3];
    K_p10[5] = K[9];
    K_p10[6] = K[0];
    K_p10[7] = K[8];
    K_p10[8] = K[7];
    K_p10[9] = K[5];
    K_p10[10] = '\0';
}

void separacao(char K_p10[10], char K_esq[6], char K_dir[6]){
    int i;
    for(i=0;i<5;i++){
        K_esq[i] = K_p10[i];
    }
    for(i=5;i<10;i++){
        K_dir[i-5] = K_p10[i];
    }
    K_esq[5] = '\0';
    K_dir[5] = '\0';
}

void rotacaoLS1(char K[6]){
    char aux = K[0];
    int i;
    for(i=0;i<4;i++){
        K[i] = K[i+1];
    }
    K[4] = aux;
}

void rotacaoLS2(char K[6]){
    char aux1 = K[0], aux2 = K[1];

    int i;
    for(i=0;i<3;i++){
        K[i] = K[i+2];
    }
    K[3] = aux1;
    K[4] = aux2;
    
}

void chaveP8(char K_esq[6], char K_dir[6], char K1[9]){
    K1[0] = K_dir[0];
    K1[1] = K_esq[2];
    K1[2] = K_dir[1];
    K1[3] = K_esq[3];
    K1[4] = K_dir[2];
    K1[5] = K_esq[4];
    K1[6] = K_dir[4];
    K1[7] = K_dir[3];
    K1[8] = '\0';
}

void ip(char B[9], char B_esq[5], char B_dir[5]){
    B_esq[0] = B[1];
    B_esq[1] = B[5];
    B_esq[2] = B[2];
    B_esq[3] = B[0];
    B_esq[4] = '\0';

    B_dir[0] = B[3];
    B_dir[1] = B[7];
    B_dir[2] = B[4];
    B_dir[3] = B[6];
    B_dir[4] = '\0';
}

void ep(char B_dir[5], char B_expandido[9]){
    // printf("B_dir[3]: %c\n", B_dir[3]);
    B_expandido[0] = B_dir[3];
    B_expandido[1] = B_dir[0];
    B_expandido[2] = B_dir[1];
    B_expandido[3] = B_dir[2];
    B_expandido[4] = B_dir[1];
    B_expandido[5] = B_dir[2];
    B_expandido[6] = B_dir[3];
    B_expandido[7] = B_dir[0];
    B_expandido[8] = '\0';
}

void xor(char B_expandido[9], char K1[9], char R[9]){
    int i;
    for(i=0;i<8;i++){
        R[i] = ((int) B_expandido[i]-48) ^ (int)K1[i];
    }
    R[8] = '\0';
}

void separacao8(char R[9], char R_esq[5], char R_dir[5]){
    int i;
    for(i=0;i<4;i++){
        R_esq[i] = R[i];
    }
    for(i=4;i<8;i++){
        R_dir[i-4] = R[i];
    }
    R_esq[4] = '\0';
    R_dir[4] = '\0';
}

int bin_para_num(char a, char b){
    int valor = ((int) a-48)*2 + (int) b -48;
    return valor;
}

void num_para_bin(int valor, char ss0[3]){
    if(valor == 0){
        ss0[0] = '0';
        ss0[1] = '0';
    }
    else if(valor == 1){
        ss0[0] = '0';
        ss0[1] = '1';
    }
    else if(valor == 2){
        ss0[0] = '1';
        ss0[1] = '0';
    }
    else if(valor == 3){
        ss0[0] = '1';
        ss0[1] = '1';
    }
}

void matrizs0(char s[5], char ss0[3]){
    int s0[4][4] = {
        {1,0,3,2},
        {3,2,1,0},
        {0,2,1,3},
        {3,1,3,2}
    };

    int linha = bin_para_num(s[0], s[3]);
    int col = bin_para_num(s[1], s[2]);
    int valor = s0[linha][col];
    num_para_bin(valor, ss0);
    ss0[2] = '\0';
}

void matrizs1(char s[5], char ss0[3]){
    int s0[4][4] = {
        {1,1,2,3},
        {2,0,1,3},
        {3,0,1,0},
        {2,1,0,3}
    };

    int linha = bin_para_num(s[0], s[3]);
    int col = bin_para_num(s[1], s[2]);
    int valor = s0[linha][col];
    num_para_bin(valor, ss0);
    ss0[2] = '\0';
}

void p4(char ss0[3], char ss1[3], char R[5]){
    R[0] = ss0[1];
    R[1] = ss1[1];
    R[2] = ss1[0];
    R[3] = ss0[0];
    R[4] = '\0';
}

void xor4(char p4[5], char B_esq[5], char B_dir[5]){
    int i;
    for(i=0;i<4;i++){
        B_dir[i] = ((int) p4[i]-48) ^ (int)B_esq[i];
    }
    B_dir[4] = '\0';
}
void funcaofk(char B_esq[5], char B_dir[5], char K1[9]){
    char B_expandido[9], R[9], s0[5], s1[5], ss0[3], ss1[3], saidap4[5];
    // printf("B_esq=%s, B_dir=%s\n",B_esq, B_dir);
    ep(B_dir, B_expandido);
    // printf("B_expandido=%s\n",B_expandido);
    xor(B_expandido, K1,R);
    // printf("R=%s\n",R);
    separacao8(R, s0, s1);
    // printf("s0=%s, s1=%s\n",s0, s1);
    matrizs0(s0, ss0);
    matrizs1(s1, ss1);
    // printf("ss0=%s, ss1=%s\n",ss0, ss1);
    p4(ss0, ss1, saidap4);
    // printf("saidap4=%s\n",saidap4);
    xor4(saidap4, B_esq, B_dir);
    // printf("metade B= %s.\n", B_dir );
    // printf("B_esq=%s, B_dir=%s\n",B_esq, B_dir);
}

void ipreverso(char B[9], char B_esq[5], char B_dir[5]){
    B[0] = B_esq[3];
    B[1] = B_esq[0];
    B[2] = B_esq[2];
    B[3] = B_dir[0];
    B[4] = B_dir[2];
    B[5] = B_esq[1];
    B[6] = B_dir[3];
    B[7] = B_dir[1];
    B[8] = '\0';
}

void sw(char B_esq[5], char B_dir[5]){
    char aux[5];
    strcpy(aux, B_esq);
    strcpy(B_esq, B_dir);
    strcpy(B_dir, aux);
}

int main(){
    int L;
    scanf("%d",&L);
    while ((getchar()) != '\n'); //This will consume the '\n' char

    int i=0, j;
    char K[12], B[10], O[3];
    while(i<L){
        fgets(O, sizeof(O), stdin);
        // while ((getchar()) != '\n'); //This will consume the '\n' char
        // O[3] = '\0';

        fgets(K, sizeof(K), stdin);
        // while ((getchar()) != '\n'); //This will consume the '\n' char
        // K[12] = '\0';

        fgets(B, sizeof(B), stdin);
        // while ((getchar()) != '\n'); //This will consume the '\n' char
        // B[10] = '\0';

        i++;
    
        char K_p10[11], K_esq[6], K_dir[6], K1[9], K2[9];
        p10(K_p10, K);
        // printf("K_p10=%s (%s)\n",K_p10, K);
        separacao(K_p10, K_esq, K_dir);
        // printf("Esq: %s, Dir: %s\n",K_esq, K_dir);
        rotacaoLS1(K_esq);
        rotacaoLS1(K_dir);
        // printf("Esq rot: %s, Dir rot: %s\n",K_esq, K_dir);
        chaveP8(K_esq, K_dir, K1);
        // printf("K1=%s\n",K1);
        rotacaoLS2(K_esq);
        rotacaoLS2(K_dir);
        // printf("Esq rot: %s, Dir rot: %s\n",K_esq, K_dir);
        chaveP8(K_esq, K_dir, K2);
        // printf("K2=%s\n",K2);
       
       //função F_k
    //    printf("O=%s, %d\n", O, strcmp(O, "C\n"));
        if(strcmp(O, "C\n")==0){
            // printf("Criptografando...\n");
            char B_esq[5], B_dir[5], B_dir_original[5], B_esq_original[5], sw1[5], sw2[5];
            ip(B, B_esq, B_dir);
            strcpy(B_dir_original, B_dir);
            strcpy(B_esq_original, B_esq);
            funcaofk(B_esq, B_dir, K1);
            strcpy(sw1, B_dir);
            // printf("sw1: %s\n", sw1);
            // printf("%s%s\n",B_esq, B_dir);
            funcaofk(B_dir_original, B_dir, K2);
            // printf("%s%s\n",B_dir, sw1);
            ipreverso(B, B_dir, sw1);
            printf("%s\n",B);
        }
        else if(strcmp(O, "D\n")==0){
            // printf("Descriptografando...\n");
            char B_esq[5], B_dir[5], B_dir_original[5], B_esq_original[5], sw1[5], sw2[5];
            ip(B, B_esq, B_dir);
            strcpy(B_dir_original, B_dir);
            strcpy(B_esq_original, B_esq);
            funcaofk(B_esq, B_dir, K2);
            strcpy(sw1, B_dir);
            // printf("sw1: %s\n", sw1);
            // printf("%s%s\n",B_esq, B_dir);
            funcaofk(B_dir_original, B_dir, K1);
            // printf("%s%s\n",B_dir, sw1);
            ipreverso(B, B_dir, sw1);
            printf("%s\n",B);
        }
        
        
    }    
    return 0;

}