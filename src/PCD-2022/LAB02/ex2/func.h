#include<stdio.h>
#include<stdlib.h>

/*=== Funções Utilizadas por ambos === */
void inicializa_grid(int **grid, int **newgrid);
void print_grid(int **grid);
void glider(int **grid);
void rpentomino(int **grid);
int getVizinhos(int **grid, int pos_x, int pos_y);
void atualiza_grid(int **grid, int **newgrid, int linha, int coluna, int vizinhos);
void getSobreviventesCritical(int **grid);
void getSobreviventesReduction(int **grid);

/*=== Funções Utilizadas pelo OpenMP === */
void executa_openmp(int **grid, int **newgrid, int iteracoes);
