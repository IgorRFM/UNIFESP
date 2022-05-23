#include <stdio.h>
#include <math.h>

#define TAM 30

/*
div_teto retorna a divisão inteira entre dois números
mas se houvesse resto na divisão, retornava o resultado +1
>(5/3 = 1)
>(tem resto)
>retorna 1+1 (2)
*/

int div_teto(int x, int y)
{
    return x / y + (x % y != 0);
}

/*
qtde_ini e  qtde_fim são os valores N e M entrados pelo usuário.
qtde é a quantidade total (a quantidade inicial + os valores diários).
media é a média móvel dos últimos 30 dias.
novos_usuarios é o vetor que contém os valores dos últimos 30 dias.
qtde_aux é a apenas dos últimos 30 dias

*/

int main()
{

    int qtde_ini, qtde_fim, i = 0, qtde_total = 0, media = 0, qtde = 0, qtde_aux = 0;
    int novos_usuarios[TAM];

    scanf("%d", &qtde_ini);
    scanf("%d", &qtde_fim);
    qtde_total = qtde_ini;
    qtde = qtde_ini;

    // lendo novos usuários + calculando média + verificando a quantidade
    for (i = 0; i < TAM; i++)
    {
        scanf("%d", &novos_usuarios[i]);
        qtde_total += novos_usuarios[i];
        qtde_aux += novos_usuarios[i];
        if (qtde_total >= qtde_fim)
        {
            printf("%d", i + 1);
            return 0;
        }
    }

    // verificando quantidade nos proximos dias
    // dia 31 = media do dia 1 ao 30
    // dia 32 = media do dia 2 ao 31
    // dia 30+i = media do dia[i] ao dia[30+i-1]

    // vetor circular (j%30) => circular vetor de 0 a 29
    int j = 0;
    i = 0;
    qtde = qtde_ini;
    while (qtde < qtde_fim)
    {
        media = div_teto(qtde_aux, 30.0);
        qtde += media;

        // perde a primeira posição relativa
        qtde_aux -= novos_usuarios[j % TAM];

        // adiciona a próx posição, na primeira
        novos_usuarios[j % TAM] = media;

        // soma a prox posição (a primeira)
        qtde_aux += novos_usuarios[j % TAM];

        qtde_total += media;

        i++;
        j++;
    }

    printf("%d", i);
    return 0;
}