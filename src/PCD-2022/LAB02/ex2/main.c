#define _POSIX_C_SOURCE 200112L /* para n�o desabilitar o pthread_barr*/

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

int modo = 0;
int qtde_threads = 8;
int **grid;
int **newgrid;
int *t_args;
//
int total_restante_global = 0;

pthread_barrier_t barr;

/* Na gera��o 467 deve come�ar a ficar constante 51, em
um tab de 2048x2048*/

     // reduction = 0 | pragma omp critical = 1

int main(int argc, char **argv)
{
    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    char txt[256]="";

    if(argc != 3)
    {
        printf("Execute o programa da seguinte forma: \n");
        printf("./main [reduction || critical] [qtde de threads a serem utilizadas]\n");
        return 0;
    }
    else
    {
        qtde_threads = (int)argv[2][0]-48;
        omp_set_num_threads(qtde_threads);
        strcat(txt, "[OpenMP] ");
        if(strcmp(argv[1],"reduction")==0)
        {
            strcat(txt, "[reduction] ");
            modo=0;
        }
        else if(strcmp(argv[1],"critical")==0)
        {
            strcat(txt, "[critical] ");
            modo=1;
        }
        strcat(txt, "executando ");
        strcat(txt, "HIGH LIFE com ");
    }

    printf("%s %d threads.\n", txt, qtde_threads);

    int i,j, total_restante;
    long double start=0,end=0;

    grid = (int**) malloc(sizeof(int*)*TAM_TAB);
    newgrid = (int**) malloc(sizeof(int*)*TAM_TAB);

    inicializa_grid(grid, newgrid);

    executa_openmp(grid, newgrid, GERACOES);

    start = omp_get_wtime();
    if(modo == 0)
    {
        GERACOES%2 ? getSobreviventesReduction(newgrid) : getSobreviventesReduction(grid);
    }
    else
    {
        GERACOES%2 ? getSobreviventesCritical(newgrid) : getSobreviventesCritical(grid);
    }
    end = omp_get_wtime();
    printf("\nForam necess�rio %Lf segundos para executar o somatorio final com %d threads.\n", end-start, qtde_threads);
    printf("\nQuantidade de c�lular vivas no final das iteracoes: %d\n", total_restante_global);
    printf("_____________________________________________________________\n");

    return 0;
}

void inicializa_grid(int **grid, int **newgrid)
{
    int i, j;
    for(i=0; i<TAM_TAB; i++)
    {
        grid[i]=(int*)malloc(sizeof(int*)*TAM_TAB);
        newgrid[i]=(int*)malloc(sizeof(int*)*TAM_TAB);

        for(j=0; j<TAM_TAB; j++)
        {
            grid[i][j]=0;
            newgrid[i][j]=0;
        }
    }
    glider(grid);
    rpentomino(grid);
}

void glider(int **grid)
{
    int lin = 1, col = 1;
    grid[lin][col+1] = 1;
    grid[lin+1][col+2] = 1;
    grid[lin+2][col  ] = 1;
    grid[lin+2][col+1] = 1;
    grid[lin+2][col+2] = 1;
}

void rpentomino(int **grid)
{
    int lin =10, col = 30;
    grid[lin  ][col+1] = 1;
    grid[lin  ][col+2] = 1;
    grid[lin+1][col  ] = 1;
    grid[lin+1][col+1] = 1;
    grid[lin+2][col+1] = 1;

}


void executa_openmp(int **grid, int **newgrid, int iteracoes)
{
    int i, linha, col, vizinhos;

    for(i=0; i<iteracoes; i++)
    {
        #pragma omp parallel private(col, vizinhos) num_threads(qtde_threads)
        {
            #pragma omp for

            for(linha=0; linha<TAM_TAB; linha++)
            {
                for(col=0; col<TAM_TAB; col++)
                {
                    if(i%2==0) 	//Leia de uma, atualize na outra;
                    {
                        vizinhos = getVizinhos(grid, linha, col);
                        if(vizinhos != -1)
                        {
                            atualiza_grid(grid, newgrid, linha, col, vizinhos);
                        }
                    }
                    else
                    {
                        vizinhos = getVizinhos(newgrid, linha, col);
                        if(vizinhos != -1)
                        {
                            atualiza_grid(newgrid, grid, linha, col, vizinhos);
                        }
                    }
                }
            }

        }
    }

}


int getVizinhos(int **grid, int pos_x, int pos_y)
{
    int contador=0;
    int i = pos_x;
    int j = pos_y;

    if(pos_x > 0 && pos_y > 0)
    {
        contador += grid[i-1][j-1];
        contador += grid[i-1][j];
        contador += grid[i-1][(j+1)%TAM_TAB];
        contador += grid[i][j-1];
        contador += grid[i][(j+1)%TAM_TAB];
        contador += grid[(i+1)%TAM_TAB][j-1];
        contador += grid[(i+1)%TAM_TAB][j];
        contador += grid[(i+1)%TAM_TAB][(j+1)%TAM_TAB];

    }
    else if (pos_x == 0 && pos_y > 0)
    {
        contador += grid[TAM_TAB-1][j-1];
        contador += grid[TAM_TAB-1][j];
        contador += grid[TAM_TAB-1][(j+1)%TAM_TAB];
        contador += grid[i][j-1];
        contador += grid[i][(j+1)%TAM_TAB];
        contador += grid[(i+1)%TAM_TAB][j-1];
        contador += grid[(i+1)%TAM_TAB][j];
        contador += grid[(i+1)%TAM_TAB][(j+1)%TAM_TAB];
    }
    else if(pos_x > 0 && pos_y == 0)
    {
        contador += grid[i-1][TAM_TAB-1];
        contador += grid[i-1][j];
        contador += grid[i-1][(j+1)%TAM_TAB];
        contador += grid[i][TAM_TAB-1];
        contador += grid[i][(j+1)%TAM_TAB];
        contador += grid[(i+1)%TAM_TAB][TAM_TAB-1];
        contador += grid[(i+1)%TAM_TAB][j];
        contador += grid[(i+1)%TAM_TAB][(j+1)%TAM_TAB];
    }
    else
    {
        return -1;
    }

    return contador;
}

void atualiza_grid(int **grid, int **newgrid, int linha, int col, int vizinhos)
{
    int cond_jogo;
    cond_jogo = (vizinhos == 3 || vizinhos == 6);


    if(grid[linha][col]==1 && (vizinhos == 2 || vizinhos == 3))
    {
        //Qualquer c�lula viva com dois ou tr�s vizinhos deve sobreviver
        newgrid[linha][col] = 1;
    }
    else if(cond_jogo && grid[linha][col]==0)
    {
        //Qualquer c�lula morta com exatamente 3 vizinhos deve se tornar viva
        newgrid[linha][col] = 1;
    }
    else
    {
        newgrid[linha][col]=0;
    }
}

void getSobreviventesCritical(int **grid)
{
    int i, j;
    int ContadorLocal=0;
    int total = 0;
    total_restante_global = 0;

    #pragma omp parallel private(ContadorLocal,j) num_threads(qtde_threads)
    {
        total = omp_get_num_threads();

        #pragma omp for

        for(i=0; i<TAM_TAB; i++)
        {

            for(j=0; j<TAM_TAB; j++)
            {
                ContadorLocal+= grid[i][j];
            }
        }

        #pragma omp critical
        {
            total_restante_global += ContadorLocal;
        }
    }
}

void getSobreviventesReduction(int **grid)
{
    int i, j;
    int ContadorLocal=0;
    total_restante_global = 0;

    #pragma omp parallel private(j) reduction(+:ContadorLocal) num_threads(qtde_threads)
    {
        int total = omp_get_num_threads();

        #pragma omp for

        for(i=0; i<TAM_TAB; i++)
        {

            for(j=0; j<TAM_TAB; j++)
            {
                ContadorLocal+= grid[i][j];
            }
        }
    }
    total_restante_global = ContadorLocal;
}
