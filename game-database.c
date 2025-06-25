#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game-database.h"
#include "system.h"

int main()
{
    int totoal_jogos = 0;
    Jogo *jogos = malloc(sizeof(Jogo)*totoal_jogos);
    int escolha;

    print_painel();
    scanf("%d", &escolha);
    scanf("%c");

    limpar_console();

    adicionar_jogo(&jogos, &totoal_jogos);

    imprimir_jogos(&jogos, totoal_jogos);

    free(jogos);

    return 0;
}
