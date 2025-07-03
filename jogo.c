#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jogo.h"
#include "system.h"

void imprimir_jogo(Jogo *jogo) {
    printf("\n[ JOGO %d ] -------------------------\n", jogo->id);

    printf("Nome: %s\n", jogo->nome);
    printf("Data de lancamento: %s\n", jogo->data_lancamento);
    printf("Idade minima para jogar: %d\n", jogo->idade_minima);
    printf("Sua nota do jogo: %.1f\n", jogo->nota);
    printf("Quantidade de horas para zerar: %.1f\n", jogo->horas_para_zerar); 
}

int buscar_jogo(Jogo **jogos, int total_jogos) {
    int id;
    
    printf("Informe o ID do jogo a pesquisar: ");
    scanf("%d", &id);
    limpar_buffer();

    if (total_jogos == 0) {
            printf("Nenhum jogo cadastrado!");
        } else {
            for (int i = 0; i < total_jogos; i++) {
                if (jogos[i]->id == id) {
                    imprimir_jogo(jogos[i]);
                    return 0;
                }
            }
            return 1;
        }
}

void adicionar_jogo(Jogo ***jogos, int *total_jogos, int *count_id) {
    *jogos = realloc(*jogos, sizeof(Jogo *) * (*total_jogos + 1));
    
    Jogo *novo_jogo = malloc(sizeof(Jogo));

    novo_jogo->id = *count_id + 1;

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
    
    printf("Quantiadade de horas para zerar: ");
    scanf("%f", &novo_jogo->horas_para_zerar);
    limpar_buffer();

    (*jogos)[*total_jogos] = novo_jogo;
    (*total_jogos)++;
    (*count_id)++;

    printf("\n%s incluido com sucesso! [ID: %d]", (*jogos)[*total_jogos - 1]->nome, (*jogos)[*total_jogos - 1]->id);
}

void deletar_jogo(Jogo ***jogos, int *total_jogos) {
    int id;
    
    printf("Informe o ID do jogo a ser deletado: ");
    scanf("%d", &id);
    limpar_buffer();

    for (int i = 0; i < *total_jogos; i++) {
        if ((*jogos)[i]->id == id) {
            free((*jogos)[i]);
            for (int j = i; j < *total_jogos;j++) {
                (*jogos)[i] = (*jogos)[i+1];
            }

            (*total_jogos)--;

            *jogos = realloc(*jogos, sizeof(Jogo *) * (*total_jogos));

            printf("Jogo [Id: %d] deletado com sucesso!", id);
        }
    }
}

void editar_jogo(Jogo ***jogos, int total_jogos) {
    int id;
    
    printf("Informe o ID do jogo a ser editado: ");
    scanf("%d", &id);
    limpar_buffer();

    for (int i = 0; i < total_jogos; i++) {
        if ((*jogos)[i]->id == id) {
            printf("Nome: ");
            fgets((*jogos)[i]->nome, sizeof((*jogos)[i]->nome), stdin);
            (*jogos)[i]->nome[strcspn((*jogos)[i]->nome, "\n")] = 0;

            printf("Data de lancamento: ");
            fgets((*jogos)[i]->data_lancamento, sizeof((*jogos)[i]->data_lancamento), stdin);
            (*jogos)[i]->data_lancamento[strcspn((*jogos)[i]->data_lancamento, "\n")] = 0;
            limpar_buffer();

            printf("Idade minima: ");
            scanf("%d", &(*jogos)[i]->idade_minima);
            limpar_buffer();

            printf("Nota [1 a 10]: ");
            scanf("%f", &(*jogos)[i]->nota);
            limpar_buffer();
            
            printf("Quantiadade de horas para zerar: ");
            scanf("%f", &(*jogos)[i]->horas_para_zerar);
            limpar_buffer();

            limpar_console();

            printf("\nJogo [Id: %d] editado com sucesso!\n", id);
        }
    }
}

void imprimir_jogos(Jogo **jogos, int total_jogos) {
    printf("\n--------------------- [Lista de Jogos] ---------------------\n\n");

    if (total_jogos == 0) {
        printf("Nenhum jogo cadastrado!\n");
    } else {
        for (int i=0;i<total_jogos;i++) {
            imprimir_jogo(jogos[i]);
        }
    }
}
