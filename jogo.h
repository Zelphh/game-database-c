#ifndef JOGO_H
#define JOGO_H

typedef struct {
    int id;
    char nome[50];
    char data_lancamento[10];
    int idade_minima;
    float nota;
    float horas_para_zerar;
} Jogo;

void imprimir_jogo(Jogo *jogo);
int buscar_jogo(Jogo **jogos, int total_jogos);
void adicionar_jogo(Jogo ***jogos, int *total_jogos, int *count_id);
void deletar_jogo(Jogo ***jogos, int *total_jogos);
void editar_jogo(Jogo ***jogos, int total_jogos);
void imprimir_jogos(Jogo **jogos, int total_jogos);

void carregar_jogos_csv(Jogo ***jogos, int *total_jogos, int *count_id, const char *filename);
void salvar_jogos_csv(Jogo **jogos, int total_jogos, const char *filename);

#endif