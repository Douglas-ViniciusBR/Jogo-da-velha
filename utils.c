#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char **criarTabuleiro(int tamanho) {
    char **tab = malloc(tamanho * sizeof(char *));
    for (int i = 0; i < tamanho; i++) {
        tab[i] = malloc(tamanho * sizeof(char));
        for (int j = 0; j < tamanho; j++)
            tab[i][j] = ' ';
    }
    return tab;
}

void liberarTabuleiro(char **tab, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        free(tab[i]);
    free(tab);
}

void mostrarTabuleiro(char **tab, int tamanho) {
    printf("\n\t  ");
    for (int i = 0; i < tamanho; i++) printf(" %d  ", i);
    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("\t%d ", i);
        for (int j = 0; j < tamanho; j++) {
            printf(" %c ", tab[i][j]);
            if (j < tamanho - 1) printf("|");
        }
        if (i < tamanho - 1) {
            printf("\n\t  ");
            for (int j = 0; j < tamanho; j++) printf("--- ");
        }
        printf("\n");
    }
    printf("\n");
}

int jogadaValida(char **tab, int linha, int coluna, int tamanho) {
    return (linha >= 0 && linha < tamanho &&
            coluna >= 0 && coluna < tamanho &&
            tab[linha][coluna] == ' ');
}

int verificarVitoria(char **tab, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int igual = 1;
        for (int j = 1; j < tamanho; j++)
            if (tab[i][j] != tab[i][0] || tab[i][0] == ' ') igual = 0;
        if (igual) return 1;
    }

    for (int j = 0; j < tamanho; j++) {
        int igual = 1;
        for (int i = 1; i < tamanho; i++)
            if (tab[i][j] != tab[0][j] || tab[0][j] == ' ') igual = 0;
        if (igual) return 1;
    }

    int igual = 1;
    for (int i = 1; i < tamanho; i++)
        if (tab[i][i] != tab[0][0] || tab[0][0] == ' ') igual = 0;
    if (igual) return 1;

    igual = 1;
    for (int i = 1; i < tamanho; i++)
        if (tab[i][tamanho - i - 1] != tab[0][tamanho - 1] ||
            tab[0][tamanho - 1] == ' ')
            igual = 0;
    return igual;
}

int verificarEmpate(char **tab, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            if (tab[i][j] == ' ') return 0;
    return 1;
}
