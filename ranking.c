#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

#define ARQ "ranking.txt"

void salvarVencedor(Jogador vencedor) {
    FILE *f = fopen(ARQ, "a");
    if (!f) {
        printf("Erro ao abrir arquivo de ranking.\n");
        return;
    }
    fprintf(f, "%s;%c;%d\n", vencedor.nome, vencedor.simbolo, 1);
    fclose(f);
}

void exibirRanking() {
    FILE *f = fopen(ARQ, "r");
    if (!f) {
        printf("\nNenhum ranking encontrado ainda.\n");
        system("pause || read -p 'Enter...'");
        return;
    }

    printf("\n===== RANKING =====\n");
    char nome[50], simb;
    int vit;
    while (fscanf(f, "%49[^;];%c;%d\n", nome, &simb, &vit) == 3)
        printf("%-15s | %c | %d vitorias\n", nome, simb, vit);

    fclose(f);
    system("pause || read -p 'Enter...'");
}
