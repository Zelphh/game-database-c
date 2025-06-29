#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jogo.h"
#include "system.h"

int main()
{
    int total_jogos = 0;
    Jogo **jogos = NULL;
    int escolha;

    do {
        imprimir_painel();
        scanf("%d", &escolha);
        limpar_buffer();
        
        switch (escolha) {
            case 1:
                //buscar_jogo(&jogos, total_jogos);
                break;
            case 2:
                limpar_console();
                adicionar_jogo(&jogos, &total_jogos);
                break;
            case 3:
                //deletar_jogo(&jogos, &totoal_jogos);
                break;
            case 4:
                //editar_jogo(&jogos, total_jogos);
                break;
            case 5:
                limpar_console();
                imprimir_jogos(jogos, total_jogos);
                break;
            default:
                if (escolha == 0) {
                    printf("\nProgama Encerrado! Volte sempre :D\n");
                } else {
                    printf("\nEscolha invalida!");
                }
        }
    } while (escolha != 0);

    for (int i = 0; i < total_jogos; i++) {
        free(jogos[i]);
    }

    free(jogos);

    return 0;
}
