#include <stdio.h>
#include <stdlib.h>

#ifndef SYSTEM_H
#define SYSTEM_H

void limpar_console() {
    #ifdef _WIN32 // Se for windows
        system("cls");
    #else 
        system("clear");
    #endif
}

void print_painel() {

    printf("\n\n ------- [Games database] -------\n\n");
    printf("[1] Buscar Jogo\n");
    printf("[2] Incluir Jogo\n");
    printf("[3] Deletar um Jogo\n");
    printf("[4] Editar um jogo\n");
    printf("[0] Mostrar todos os Jogos\n\n");
}

#endif

