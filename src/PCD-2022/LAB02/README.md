# Programação Concorrente e Distribuida

## LAB 02

> Igor Ribeiro Ferreira de Matos, Ana clara Mueller Miranda, Ulisses Auresco Damasio

---

### Explicação do algoritmo e execução

Para executar, passe os argumentos da seguinte forma:

ex1:
> ./main [qtde threads]

ex2:
> ./main [reduction || critical] [qtde de threads a serem utilizadas]

ex3:
> Compilar todos os arquivos java e executar o main // não há passagem de argumentos

---

#### Proposta:

##### Ex1
Devemos implementar o algoritmo de Manna-Pnueli para controle de seção crítica por espera ocupada: devemos implementar uma thread principal para o "servidor", e uma quantidade de threads indicada pelo usuário, para o "cliente".

##### Ex2
Reaproveitando o código do [LAB01](../LAB01/), devemos agora implementar, apenas na última interação, a somatória de células vivas através de openMP, utilizando seção crítica (critical) ou a diretriz (reduction).

##### Ex3
Modificando um código disponibilizado pelos professores, devemos implementar um semáforo no algoritmo de carros em via-dupla que têm que passar por uma ponte de via única. 


