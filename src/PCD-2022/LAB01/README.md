# Programação Concorrente e Distribuida

## LAB 01

> Igor Ribeiro Ferreira de Matos, Ana clara Mueller Miranda, Ulisses Auresco Damasio

---

### Explicação do algoritmo e execução

Para executar, passe os argumentos da seguinte forma:

> ./main [omp ou pthread] [normal ou highlife] [qtde_threads]

O primeiro argumento é para decidir a execução em OpenMP ou em PThread. O segundo é para decidir se será a execução do jogo da vida ou do jogo highlife. Finalmente, o terceiro, é para determinar a quantidade de Threads que serão executadas.

---

#### Proposta:

Implementação do algoritmo "Jogo da Vida", criado por John H. Conway e sua variação chamada "HighLife" em C, utilizando Pthreads e OpenMP.

Jogo da Vida é um algoritmo composto por um tabuleiro bi-dimensional, infinito em qualquer direção (ou seja, uma borba é conectada na outra).

Nele, cada célula tem exatamente 8 vizinhos, e cada célula pode estar "viva" ou "morta", que é atualizada a cada geração em base na quantidade de vizinhos vivos ou mortos da célula. As condições são:
+ Células com menos de 2 vizinhos morrer por abandono.
+ Cada célula viva com 2 ou 3 vizinhos deve permanecer viva para a próxima geração.
+ Cada célula viva com 4 ou mais vizinhos morre por superpopulação.
+ Cada célula com exatamente 3 vizinhos deve se tornar viva.

A variação "High Life" altera apenas as condições, para:
+ Cada célula com 2 ou 3 vizinhos deve sobreviver.
+ Cada célula morta com 3 ou 6 vizinhos torna-se viva.
+ Qualquer outro caso, células vivas devem morrer, e mortas devem continuar mortas.

---

#### Explicação do Algoritmo:

O método de execução do algoritmo é devinido a partir da entrada de argumentos. Dos argumentos (**argv) inseridos pelo usuário, como digitado abaixo, o irá definir: a quantidade de threads a ser executada, se será o algoritmo padrão ou a variação highlife e se será por openMP ou por Pthread.
``` C++

if(argc != 4){
		printf("Execute o programa da seguinte forma: \n");
		printf("./main [omp || pthread] [normal || highlife] [qtde de threads a serem utilizadas]\n");
		return 0;
	}else{
		qtde_threads = (int)argv[3][0]-48;
		...
		...
```

Então, duas grids foram iniciadas: GRID e NEWGRID. Elas serão nossos tabuleiros. Como acontecerá concorrência, não poderíamos fazer a verificação de vizinhos em uma tabela e atualizar na outra pelo simples motivo de que há a possibilidade de uma thread atualizar uma casa enquanto outra thread estaria lendo, e a atualização ser perdida, causando um problema de dependência.

A solução foi utilizar duas grids: em geração ímpar, iremos ler e calcular os vizinhos de cada célula da "grid" e escrever a atualização de status na "newgrid". Em geração par, fazemos o contrário.

A função _inicializa_grid_ apenas aloca a matriz e inicializa ela com valores 0, além de inserir as duas figuras iniciais: glider e rpentomino.
``` C++
grid = (int**) malloc(sizeof(int*)*TAM_TAB);
newgrid = (int**) malloc(sizeof(int*)*TAM_TAB);

inicializa_grid(grid, newgrid);	
printf("Contagem inicial: %d\n", getSobreviventes(grid));
```

Iremos contabilizar o tempo de execução através do _omp_get_wtime()_ por conta de sua precisão, e executaremos em base no modo escolhido pelo usuário.
``` C++
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
```
A _cria_threads()_ simplesmente criará a quantidade de threads indicada pelo usuário, passando como argumento de cada um id (de 0 até qtde-1, indicando a thread). A função que cada thread executa é a _*executa_thread()_.

A _executa_thread()_ irá separar, com base na quantidade de threads, intervalos para cada id, que fará a execução. Caso tenha duas threads, por exemplo, a thread de id 0 irá fazer a leitura de todas asl inhas da grid, da coluna zero até a coluna 1000; enquanto a thread de id 1 irá fazer a leitura de todas as linhas, da coluna 1000 até 2000.

Nessa análise ela chamará a getVizinhos de cada célula e calculará o próximo status da célula em _atualiza_grid()_, que passará as condições do jogo.

``` C++
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

```

O openMP é um pouco mais simples, toda a divisão da thread é feita automaticamente através das regiões paralelas: usamos as diretrizes _parallel_ para indicar a região; _private_ para indicar as variáveis locais; _for_ para indicar que haverá paralelização de domínio (cada thread executará a mesma coisa, mas com intervalo diferente).

É feita então a mesma atualização que a pthread.
```C++
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

```