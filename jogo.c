#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo.h"
#include "utils.h"
#include "ranking.h"

void menuPrincipal(int tamanho) {
    int opcao;
    do {
        system("cls || clear");
        printf("===== JOGO DA VELHA =====\n");
        printf("1 - Jogar contra outro jogador\n");
        printf("2 - Jogar contra o computador\n");
        printf("3 - Ver Ranking\n");
        printf("4 - Créditos\n");
        printf("0 - Sair\n");
        printf("--------------------------\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: jogar(tamanho, 0); break; // modo 2 jogadores
            case 2: jogar(tamanho, 1); break; // modo vs computador
            case 3: exibirRanking(); break;
            case 4:
                printf("\nDesenvolvido por:\n");
                printf("- Bruno Sena e Equipe - TDA 2025.2\n");
                system("pause || read -p 'Enter...'"); 
                break;
        }
    } while (opcao != 0);
}

void jogar(int tamanho, int modoComputador) {
    char **tabuleiro = criarTabuleiro(tamanho);
    Jogador j1, j2;
    int x, y, vez = 1, fim = 0;

    srand(time(NULL)); // para o rand() do computador

    printf("\nNome do Jogador 1 (X): ");
    scanf("%s", j1.nome);
    j1.simbolo = 'X';
    j1.vitorias = 0;

    if (modoComputador) {
        strcpy(j2.nome, "Computador");
        j2.simbolo = 'O';
        j2.vitorias = 0;
    } else {
        printf("Nome do Jogador 2 (O): ");
        scanf("%s", j2.nome);
        j2.simbolo = 'O';
        j2.vitorias = 0;
    }

    while (!fim) {
        system("cls || clear");
        mostrarTabuleiro(tabuleiro, tamanho);
        Jogador atual = (vez == 1) ? j1 : j2;

        if (modoComputador && vez == 2) {
            // jogada automática do computador
            printf("\n🤖 Computador está jogando...\n");
            do {
                x = rand() % tamanho;
                y = rand() % tamanho;
            } while (!jogadaValida(tabuleiro, x, y, tamanho));
            tabuleiro[x][y] = atual.simbolo;
            sleep(1); // pausa curta pra parecer mais real
        } else {
            // jogada humana
            printf("%s (%c), digite linha e coluna: ", atual.nome, atual.simbolo);
            scanf("%d %d", &x, &y);

            if (!jogadaValida(tabuleiro, x, y, tamanho)) {
                printf("Jogada inválida! Tente novamente.\n");
                system("pause || read -p 'Enter...'"); 
                continue;
            }

            tabuleiro[x][y] = atual.simbolo;
        }

        if (verificarVitoria(tabuleiro, tamanho)) {
            system("cls || clear");
            mostrarTabuleiro(tabuleiro, tamanho);
            printf("\n🎉 %s venceu!\n", atual.nome);
            salvarVencedor(atual);
            fim = 1;
        } else if (verificarEmpate(tabuleiro, tamanho)) {
            system("cls || clear");
            mostrarTabuleiro(tabuleiro, tamanho);
            printf("\n😐 Deu velha! Empate.\n");
            fim = 1;
        } else {
            vez = (vez == 1) ? 2 : 1;
        }
    }

    liberarTabuleiro(tabuleiro, tamanho);
    system("pause || read -p 'Enter...'");
}
