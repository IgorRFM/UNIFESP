# Programação Concorrente e Distribuida

## LAB 01

> Igor Ribeiro Ferreira de Matos, Ana clara Mueller Miranda, Ulisses Auresco Damasio

---

### Explicação do algoritmo e execução

Para executar, passe os argumentos da seguinte forma:

> mpirun -np [nª de processos] ./main [nª de processos]

Dependendo da versão do MPI encontramos problemas ao pegar o número de processos sendo executado, argumento do -np; por isso, optamos por reforçar a declaração da quantidade de processos que serão executado.

O algoritmo foi desenvolvido na versão 4.1.4 do MPI. Em versões anteriores, como 3.x, este código não executava corretamente em algumas máquinas.

---

#### Proposta:

Implementação do algoritmo "Jogo da Vida", criado por John H. Conway e sua variação chamada "HighLife" em C, OpenMPI.

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

```