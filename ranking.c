/*
Documentação
Função: Controla o sistema de ranking do jogo.
Objetivo: Registrar, ler e ordenar pontuações dos jogadores.
Entradas: Nome do jogador e resultado da partida.
Processo: Atualiza o arquivo de ranking e organiza a lista.
Saída: Exibição do ranking atualizado no terminal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

#define ARQ "ranking.txt"

typedef struct {
    char nome[50];
    int vitorias;
} RegistroRanking;

// Função que salva ou atualiza o vencedor
void salvarVencedor(Jogador vencedor) {
    FILE *f = fopen(ARQ, "r");
    RegistroRanking lista[100];
    int count = 0;
    int encontrado = 0;

    // Carrega dados existentes
    if (f) {
        while (fscanf(f, "%49[^;];%d\n", lista[count].nome, &lista[count].vitorias) == 2)
            count++;
        fclose(f);
    }

    // Atualiza se já existir
    for (int i = 0; i < count; i++) {
        if (strcmp(lista[i].nome, vencedor.nome) == 0) {
            lista[i].vitorias++;
            encontrado = 1;
            break;
        }
    }

    // Se for novo jogador
    if (!encontrado) {
        strcpy(lista[count].nome, vencedor.nome);
        lista[count].vitorias = 1;
        count++;
    }

    // Ordena do maior para o menor (bubble sort)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lista[j].vitorias < lista[j + 1].vitorias) {
                RegistroRanking temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }

    // Regrava o arquivo
    f = fopen(ARQ, "w");
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s;%d\n", lista[i].nome, lista[i].vitorias);
    }
    fclose(f);
}

// Exibe ranking formatado
void exibirRanking() {
    FILE *f = fopen(ARQ, "r");
    if (!f) {
        printf("\nNenhum ranking encontrado ainda.\n");
        system("pause || read -p 'Enter...'");
        return;
    }

    printf("\n=====================================\n");
    printf("             RANKING TOP 5           \n");
    printf("=====================================\n");
    printf("  #  %-20s  %-10s\n", "Jogador", "Vitorias");
    printf("-------------------------------------\n");

    char nome[50];
    int vit, pos = 1;
    while (pos <= 5 && fscanf(f, "%49[^;];%d\n", nome, &vit) == 2) {
        printf("  %-2d %-20s  %-10d\n", pos, nome, vit);
        pos++;
    }

    printf("=====================================\n");
    fclose(f);
    system("pause || read -p 'Enter...'");
}
