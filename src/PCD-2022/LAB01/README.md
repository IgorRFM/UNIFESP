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
_ Células com menos de 2 vizinhos morrer por abandono;
_ Cada célula viva com 2 ou 3 vizinhos deve permanecer viva para a próxima geração;
_ Cada célula viva com 4 ou mais vizinhos morre por superpopulação;
_ Cada célula com exatamente 3 vizinhos deve se tornar viva;

A variação "High Life" altera apenas as condições, para:
_ Cada célula com 2 ou 3 vizinhos deve sobreviver;
_ Cada célula morta com 3 ou 6 vizinhos torna-se viva;
\_ Qualquer outro caso, células vivas devem morrer, e mortas devem continuar mortas;

---

#### Explicação do Algoritmo:

```
if(argc != 4){
		printf("Execute o programa da seguinte forma: \n");
		printf("./main [omp || pthread] [normal || highlife] [qtde de threads a serem utilizadas]\n");
		return 0;
	}else{
		qtde_threads = (int)argv[3][0]-48;
```
