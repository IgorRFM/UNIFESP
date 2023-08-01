#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <locale.h>

void iniciaSint(unsigned char S[], unsigned char T[], unsigned char K[]){
    int i;
    int k = strlen(K);
    for(i=0;i<256;i++){
        S[i] = i;
        T[i] = K[i%k];
    }
}

void swap(unsigned char Si, unsigned char Sj){
    unsigned char k = Si;
    Si = Sj;
    Sj = k;
}

void cript(unsigned char *key_, unsigned char *plain_text, unsigned char *cifrado_, int size){
    unsigned char S[256];
    unsigned char T[256];

    printf("\ntexto CHEGOU -> %s\n",plain_text);

    iniciaSint(&S, &T, key_);
    
    int i , j, k, t, l;
    j = 0;
    for(i=0;i<256;i++){ 
        j =(j+S[i]+T[i])%256;
        swap(S[i], S[j]);
    }
    
    i = j = 0;
    l = k = t = 0;
    while(l < size){

        i = (i+1)%256;
        j = (j+S[i])%256;
        swap(S[i], S[j]);
        t = (S[i]+S[j])%256;
        k = S[t];
        cifrado_[l] = plain_text[l]^k;
        l++;
    }

    //printf("\n texto SAIU -> %s", cifrado_);

    // printf("\n");

}


int main(int argc, char **argv){
    char S[256];
    char K[256];
    int Sint[256];
    int T[256];

    //int output[256];
    unsigned char output[256];

    scanf("%s", S);
    scanf(" %s", K);

    iniciaSint(Sint, T, K);
    int i , j, k, t, l;
    j = 0;
    for(i=0;i<256;i++){
        j =(j+Sint[i]+T[i])%256;
        swap(&Sint[i], &Sint[j]);
    }
    
    i = j = 0;
    l = k = t = 0;

    while(l < 256){
        i = (i+1)%256;
        j = (j+Sint[i])%256;
        swap(&Sint[i], &Sint[j]);

        t = (Sint[i]+Sint[j])%256;
        k = Sint[t];
        output[l] = S[l]^k;
        l++;
    }

    for(i=0;i<strlen(S);i++){
        printf("%x:",output[i]);
    }
    return 0;
}