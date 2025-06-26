#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef JOGO_H
#define JOGO_H

typedef struct {
    int id;
    char nome[50];
    char data_lancamento[10]; // dd/mm/yyyy
    int idade_minima;
    float nota;
    float horas_para_zerar;
} Jogo;

void adicionar_jogo(Jogo ***jogos, int *quantidade) {
    **jogos = realloc(jogos, sizeof(Jogo) * (*quantidade + 1));
    
    Jogo *novo_jogo = malloc(sizeof(Jogo));

    novo_jogo->id = *quantidade + 1;

    printf("Nome: ");
    fgets(novo_jogo->nome, sizeof(novo_jogo->nome), stdin);
    novo_jogo->nome[strcspn(novo_jogo->nome, "\n")] = 0;

    printf("Data de lancamento: ");
    fgets(novo_jogo->data_lancamento, sizeof(novo_jogo->data_lancamento), stdin);
    novo_jogo->data_lancamento[strcspn(novo_jogo->data_lancamento, "\n")] = 0;
    limpar_buffer();

    printf("Idade minima: ");
    scanf("%d", &novo_jogo->idade_minima);
    limpar_buffer();

    printf("Nota [1 a 10]: ");
    scanf("%f", &novo_jogo->nota);
    limpar_buffer();
    
    printf("Quantidade de horas para zerar: ");
    scanf("%f", &novo_jogo->horas_para_zerar);
    limpar_buffer();

    (*jogos)[*quantidade] = novo_jogo;
    (*quantidade)++;

    limpar_console();

    printf("\n%s incluido com sucesso!", (*jogos)[*quantidade - 1]->nome);
}

void imprimir_jogos(Jogo ***jogos, int quantidade) {
    printf("\n--------------------- [Lista de Jogos] ---------------------\n\n");

    for (int i=0;i<quantidade;i++) {
        printf("\nJOGO %d ----------------\n", (*jogos)[i]->id);

        printf("Nome: %s\n", (*jogos)[i]->nome);
        printf("Data de lancamento: %s\n", (*jogos)[i]->data_lancamento);
        printf("Idade minima para jogar: %d\n", (*jogos)[i]->idade_minima);
        printf("Sua nota do jogo: %.1f\n", (*jogos)[i]->nota);
        printf("Quantidade de horas para zerar: %.1f\n", (*jogos)[i]->horas_para_zerar);
    }
}

#endif