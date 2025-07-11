#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jogo.h"
#include "system.h"

int main()
{
    int total_jogos = 0;
    int count_id = 0;
    Jogo **jogos = NULL;
    int escolha;
    const char *NOME_ARQUIVO = "jogos.csv";

    carregar_jogos_csv(&jogos, &total_jogos, &count_id, NOME_ARQUIVO);

    do {
        imprimir_painel();
        scanf("%d", &escolha);
        limpar_buffer();
        
        switch (escolha) {
            case 1:
                limpar_console();
                if (buscar_jogo(jogos, total_jogos) == 1)
                    printf("Jogo com esse ID não encontrado!");
                break;
            case 2:
                limpar_console();
                adicionar_jogo(&jogos, &total_jogos, &count_id);
                break;
            case 3:
                limpar_console();
                deletar_jogo(&jogos, &total_jogos);
                break;
            case 4:
                limpar_console();
                editar_jogo(&jogos, total_jogos);
                break;
            case 5:
                limpar_console();
                imprimir_jogos(jogos, total_jogos);
                break;
            default:
                if (escolha == 0) {
                    salvar_jogos_csv(jogos, total_jogos, NOME_ARQUIVO);
                    printf("\nPrograma Encerrado! Volte sempre :D\n");
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