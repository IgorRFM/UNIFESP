#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int soma=0; // Variável global
int respond=0;
int request=0; //variavel que libera as threads
int N=10; //iterações

#define NUM_THREADS 2

void secao_critica(){
    int local = soma; //variável local dos clientes
    sleep(rand()%2);
    soma = local + 1;
    printf("seção crítica, SOMA: %d\n", soma);
}

void *cliente(void* i){
    int aux = *(int*)i;
	for(int j=0;j<N;j++){
        printf("seção não crítica\n");
        while(respond != aux){
            request = aux;
        }
        secao_critica();
        respond=0;
    }
	pthread_exit(NULL);
}

void *servidor(){
	while(1==1){
		while(request == 0){
            //await request
        }
		respond = request;		
		while(respond != 0){
            //await response
        }
		request = 0;
	}
	pthread_exit(NULL);
}

int main(void){

	pthread_t t[NUM_THREADS];
	pthread_t t_server;
	int tid;
	int i;		
	pthread_create(&t_server, NULL, servidor, NULL); // Cria thread do servidor
	for(i = 1; i <= NUM_THREADS; i++){
		pthread_create(&t[i-1], NULL, cliente, (void*)&i);			
	}
	
	for(i = 0; i < NUM_THREADS; i++){ //juntando as threads
		pthread_join(t[i], NULL);
	}
	
	printf("soma = %d\n", soma);
	return 0;
}