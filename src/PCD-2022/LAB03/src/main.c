#define _POSIX_C_SOURCE 200112L /* para não desabilitar o pthread_barr*/

#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

#include "func.h"

#define TAM_TAB 2048
#define GERACOES 2000

int qtde_threads = 1;
int **grid;
int **newgrid;
int *t_args;

pthread_barrier_t barr;

/* Na geração 467 deve começar a ficar constante 51, em
um tab de 2048x2048*/

int modo = -1; 		// OpenMp = 1 | Pthread = 0
int jogo = -1;  	// Normal = 1 | Highlife = 0

int main(int argc, char **argv){
	omp_set_dynamic(0);     // Explicitly disable dynamic teams
	char txt[256]="";

	if(argc != 4){
		printf("Execute o programa da seguinte forma: \n");
		printf("./main [omp || pthread] [normal || highlife] [qtde de threads a serem utilizadas]\n");
		return 0;
	}else{
		qtde_threads = (int)argv[3][0]-48;
		omp_set_num_threads(qtde_threads); 

		if(strcmp(argv[1],"omp")==0){
			strcat(txt, "[OpenMP] ");
			modo = 1;
		}else if(strcmp(argv[1],"pthread")==0){
			strcat(txt, "[Pthread] ");
			modo = 0;
		}
		strcat(txt, "executando ");
		if(strcmp(argv[2], "normal")==0){
			strcat(txt, "JOGO DA VIDA com");
			jogo = 1;
		}else if(strcmp(argv[2], "highlife")==0){
			strcat(txt, "HIGH LIFE com ");
			jogo = 0;
		}	
	}
	printf("%s %d threads.\n", txt, qtde_threads);

	int i,j, total_restante;
	double start, end, run;

	grid = (int**) malloc(sizeof(int*)*TAM_TAB);
	newgrid = (int**) malloc(sizeof(int*)*TAM_TAB);
	
	inicializa_grid(grid, newgrid);	
	printf("Contagem inicial: %d\n", getSobreviventes(grid));

	
	start = omp_get_wtime();
	
	if(modo == 1){
		executa_openmp(grid, newgrid, GERACOES);
	}else if (modo == 0){
		cria_threads();
	}else{
		printf("Execute com o argummento 'pthread' ou 'omp'.\n");
		return 0;
	}
	
	end = omp_get_wtime();
	total_restante = GERACOES%2 ? getSobreviventes(newgrid) : getSobreviventes(grid);
  	
	printf("Quantidade de célular vivas no final das iterações: %d\n", total_restante);
	printf("\nForam necessário %f segundos para executar com %d threads.\n", end-start, qtde_threads);
	
	printf("_____________________________________________________________\n");
	return 0;
}

void inicializa_grid(int **grid, int **newgrid){
	int i, j;
	for(i=0; i<TAM_TAB; i++){
		grid[i]=(int*)malloc(sizeof(int*)*TAM_TAB);
		newgrid[i]=(int*)malloc(sizeof(int*)*TAM_TAB);
		
		for(j=0; j<TAM_TAB; j++){
			grid[i][j]=0;
			newgrid[i][j]=0;
		}

	}

	glider(grid);
	rpentomino(grid);
}

void glider(int **grid){
	int lin = 1, col = 1;
	grid[lin][col+1] = 1;
	grid[lin+1][col+2] = 1;
	grid[lin+2][col  ] = 1;
	grid[lin+2][col+1] = 1;
	grid[lin+2][col+2] = 1;
}

void rpentomino(int **grid){
	int lin =10, col = 30;
	grid[lin  ][col+1] = 1;
	grid[lin  ][col+2] = 1;
	grid[lin+1][col  ] = 1;
	grid[lin+1][col+1] = 1;
	grid[lin+2][col+1] = 1;

}

void print_grid(int **grid){
	int i, j;
	for(i=0; i<TAM_TAB; i++){
		for(j=0;j<TAM_TAB; j++){
			printf("%d " ,grid[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

}

void executa_openmp(int **grid, int **newgrid, int iteracoes){
	int i, linha, col, vizinhos;

	for(i=0; i<iteracoes; i++){
#pragma omp parallel private(col, vizinhos) num_threads(qtde_threads)
{
#pragma omp for		
		for(linha=0; linha<TAM_TAB; linha++){
			for(col=0; col<TAM_TAB; col++){
				if(i%2==0){	//Leia de uma, atualize na outra;
					vizinhos = getVizinhos(grid, linha, col);
					if(vizinhos != -1){
						atualiza_grid(grid, newgrid, linha, col, vizinhos);
					}
				}else{
					vizinhos = getVizinhos(newgrid, linha, col);
					if(vizinhos != -1){
						atualiza_grid(newgrid, grid, linha, col, vizinhos);
					}
				}
			}
		}
}
	}
}

void cria_threads(){
	int i=0;
	pthread_t thr[qtde_threads];
	t_args = (int*) malloc(sizeof(int*)*qtde_threads);

	if(pthread_barrier_init(&barr, NULL, qtde_threads)){
		printf("Falha ao iniciar barreira\n");
    }

	for(i=0; i<qtde_threads; i++){
		t_args[i] = i;
		if(pthread_create(&thr[i], NULL, &executa_pthread, (void*)&t_args[i])){
	    	printf("Falha ao criar thread %d\n", i);
		}
	}

	for(i=0; i<qtde_threads; i++){
		pthread_join(thr[i], NULL);
	}
	
}

void *executa_pthread(void* tid){
	int i, linha, col, vizinhos;
	int thid = *((int*) tid);
	
	int intervalo = TAM_TAB / qtde_threads;
	int inicio = intervalo * thid;
	int fim = inicio+intervalo;

	for(i=0; i<GERACOES; i++){
		for(linha=inicio; linha<fim; linha++){
			for(col=0; col<TAM_TAB; col++){
				if(i%2==0){	//Leia de uma, atualize na outra;
					vizinhos = getVizinhos(grid, linha, col);
					if(vizinhos != -1){
						atualiza_grid(grid, newgrid, linha, col, vizinhos);
					}
				}else{
					vizinhos = getVizinhos(newgrid, linha, col);
					if(vizinhos != -1){
						atualiza_grid(newgrid, grid, linha, col, vizinhos);
					}
				}
			}
		}

		int bn = pthread_barrier_wait(&barr); 
		if(bn == PTHREAD_BARRIER_SERIAL_THREAD){
	    	continue;
	  			 			
		}else if(bn != 0){
	    	printf("Could not wait on barrier\n");
	    	exit(-1);
		}
	}
	
}
int getVizinhos(int **grid, int pos_x, int pos_y){
	int contador=0;
	int i = pos_x;
	int j = pos_y;

	if(pos_x > 0 && pos_y > 0){
		contador += grid[i-1][j-1];
		contador += grid[i-1][j];
		contador += grid[i-1][(j+1)%TAM_TAB];
		contador += grid[i][j-1];
		contador += grid[i][(j+1)%TAM_TAB];
		contador += grid[(i+1)%TAM_TAB][j-1];
		contador += grid[(i+1)%TAM_TAB][j];
		contador += grid[(i+1)%TAM_TAB][(j+1)%TAM_TAB];

	}else if (pos_x == 0 && pos_y > 0){
		contador += grid[TAM_TAB-1][j-1];
		contador += grid[TAM_TAB-1][j];
		contador += grid[TAM_TAB-1][(j+1)%TAM_TAB];
		contador += grid[i][j-1];
		contador += grid[i][(j+1)%TAM_TAB];
		contador += grid[(i+1)%TAM_TAB][j-1];
		contador += grid[(i+1)%TAM_TAB][j];
		contador += grid[(i+1)%TAM_TAB][(j+1)%TAM_TAB];
	}else if(pos_x > 0 && pos_y == 0){
		contador += grid[i-1][TAM_TAB-1];
		contador += grid[i-1][j];
		contador += grid[i-1][(j+1)%TAM_TAB];
		contador += grid[i][TAM_TAB-1];
		contador += grid[i][(j+1)%TAM_TAB];
		contador += grid[(i+1)%TAM_TAB][TAM_TAB-1];
		contador += grid[(i+1)%TAM_TAB][j];
		contador += grid[(i+1)%TAM_TAB][(j+1)%TAM_TAB];
	}else{
		return -1;
	}

	return contador;
}

void atualiza_grid(int **grid, int **newgrid, int linha, int col, int vizinhos){
	int cond_jogo;
	if(jogo==0){ //highlife
		cond_jogo = (vizinhos == 3 || vizinhos == 6);
	}else if(jogo == 1){ //normal
		cond_jogo = (vizinhos == 3);
	}else{
		printf("Modo de jogo inválido, passe argumentos 'normal' ou 'highlife'.\n");
	}

	if(grid[linha][col]==1 && (vizinhos == 2 || vizinhos == 3)){
		//Qualquer célula viva com dois ou três vizinhos deve sobreviver
		newgrid[linha][col] = 1;
	}else if(cond_jogo && grid[linha][col]==0){
		//Qualquer célula morta com exatamente 3 vizinhos deve se tornar viva
		newgrid[linha][col] = 1;
	}else{
		newgrid[linha][col]=0;
	}
}

int getSobreviventes(int **grid){
	int i, j;
	int contador=0;
	for(i=0; i<TAM_TAB; i++){
		for(j=0; j<TAM_TAB; j++){
			contador+= grid[i][j];
		}
	}
	return contador;
}