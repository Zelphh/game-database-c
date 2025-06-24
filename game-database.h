#include <stdio.h>

#ifndef GAME_DATABASE_H
#define GAME_DATABASE_H

typedef struct
{
    int id;
    char nome[50];
    char data_lancamento[10]; // dd/mm/yyyy
    int idade_minima;
    float nota;
    float horas_para_zerar;
} Jogo;


void imprimir_jogos(Jogo jogos[], int quantidade) {
    printf("\n--------------------- [Lista de Jogos] ---------------------\n\n");

    for (int i=0;i<quantidade;i++) {
        printf("\nJOGO %d ----------------\n", i+1);

        printf("Nome: %s\n", jogos[i].nome);
        printf("Data de lancamento: %s\n", jogos[i].data_lancamento);
        printf("Idade minima para jogar: %d\n", jogos[i].idade_minima);
        printf("Sua nota do jogo: %.1f\n", jogos[i].nota);
        printf("Quantidade de horas para zerar: %.1f\n", jogos[i].horas_para_zerar);
    }
}

#endif
