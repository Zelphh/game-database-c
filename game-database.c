#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game-database.h"

#define TAMANHO 2

int main()
{
    Jogo *jogos = malloc(sizeof(Jogo)*TAMANHO);


    for (int i=0;i<TAMANHO;i++) {
        printf("\nJOGO %d ----------------\n", i+1);

        printf("NOME DO JOGO: ");
        fgets(jogos[i].nome, 50, stdin);

        printf("DATA DE LANCAMENTO [dd/mm/yyyy]: ");
        scanf("%s", jogos[i].data_lancamento);

        printf("IDADE MINIMA: ");
        scanf("%d", &jogos[i].idade_minima);

        printf("NOTA: ");
        scanf("%f", &jogos[i].nota);

        printf("HORAS PARA ZERAR: ");
        scanf("%f", &jogos[i].horas_para_zerar);
        scanf("%c");
    }

    imprimir_jogos(jogos, TAMANHO);

    free(jogos);

    return 0;
}
